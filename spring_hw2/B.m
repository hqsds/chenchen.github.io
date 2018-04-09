function [y] = B(n,a,b,x,alph,beta)
               %B-splines.evaluate the spline at x.output the value y.
               %a,b are the endpoints of the interval. n is the number of
               %subintervals.(n+1)points
h=(b-a)/n;
derivx0=f11(a,alph,beta);
derivxn=f11(b,alph,beta);

for i=0:n
    I(i+1)=a+i*h;
end

for i=1:n+1
    fun(i)=f1(I(i),alph,beta);
end

%%%%%%%%%%%%%%  start solve the linear system.  %%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%  save d  %%%%%%%%%%%%%%%%%%

for i=1:n+1
    d(i)=fun(i);
end
    d(1)=d(1)+h*derivx0/3;
    d(n+1)=d(n+1)-h*derivxn/3;
  
%%%%%%%%%%%%%%  Gauss elimination  %%%%%%%%%%%%%%%%%%%%    

 for i=1:n+1
     Diag(i)=4;
 end
 d(2)=d(2)-d(1)/4;
Diag(2)=Diag(2)-1/2;

for i=2:n-1
    d(i+1)=d(i+1)-d(i)/Diag(i);
    Diag(i+1)=Diag(i+1)-1/Diag(i);
end
d(n+1)=d(n+1)-d(n)*2/Diag(n);
Diag(n+1)=Diag(n+1)-1/Diag(n);


alpha(n+1)=d(n+1)/Diag(n+1);
for j=1:n-1
    alpha(n+1-j)=(d(n+1-j)-alpha(n+2-j))/Diag(n+1-j);
end
alpha(1)=(d(1)-2*alpha(2))/Diag(1);

alpha(n+2)=h*derivxn/3+alpha(n);
alphaspecial=alpha(2)-h*derivx0/3;

%%%%%%%%%%%%%% start to evaluate the value at x %%%%%%%%%%%%%%%%%%%%%%%%%
if (x-a)/h-floor((x-a)/h)==0
    y=f1(x,alph,beta);
else
     i0=floor((x-a)/h)+1;
    
     l2=(I(i0+1)-x)/h;
     l1=(x-I(i0))/h;
   
     if i0==1
         
     y=[alpha(i0),alpha(i0+1)]*[1,l2,l2^2,l2^3;1,l1,l1^2,l1^3]*[1;3;3;-3]+[alphaspecial,alpha(i0+2)]*[l2^3;l1^3];
     else
         
     y=[alpha(i0),alpha(i0+1)]*[1,l2,l2^2,l2^3;1,l1,l1^2,l1^3]*[1;3;3;-3]+[alpha(i0-1),alpha(i0+2)]*[l2^3;l1^3];
     end
     end
    
    
    
    
    
    
    
    
    
    
    
    