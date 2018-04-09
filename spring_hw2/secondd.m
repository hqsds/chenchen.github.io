function [y] = secondd(I,x,flag,alph,beta)
               %splines derived from Ts"=d. 
               %evaluate the spline at x.output the value y.
               %I is a vector which saves the given points.ie. I gives out a partition of
               %the interval; flag is the for the boundary conditions you choose
[m,n]=size(I);
 
 %%compute functional value at given points.
 for i=1:n
  fun(i)=f1(I(i),alph,beta);
 end
 
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  start compute s"   %%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
 for i=1:n-1
     h(i)=I(i+1)-I(i);
 end
 for i=1:n-2
     miu(i)=h(i)/(h(i)+h(i+1));
     lamta(i)=h(i+1)/(h(i)+h(i+1));
 end     %%%  compute the parameters miu and lamta. %%
 
 %% now start to compute the divided difference which we need  %%%%%%
    A=zeros(3,n);
    for j=1:n
        A(1,j)=fun(j);
    end
    
    for i=2:3
        for j=i:n
            A(i,j)=(A(i-1,j)-A(i-1,j-1))/(I(j)-I(j-i+1));
        end
    end
 for i=1:n-2
     Divided(i)=A(3,i+2);
 end
 
 %%%%%%%%start solve tridiagonal matrix.d is the righthand side vector for
 %%%%%%%%this matrix.
 
 if flag==1
derix0=f12(I(1),alph,beta);
derixn=f12(I(n),alph,beta);%%%%%%%save the boundary condition give the secondary derivatives
 
for i=1:n-2
     d(i)=6*Divided(i);
 end
 d(1)=d(1)-miu(1)*derix0;
 d(n-2)=d(n-2)-lamta(n-2)*derixn;
 

 %%%%%%%%%%%% Gauss elimation  %%%%%%%%%%%%%%%%%%%%%%%%
 for i=1:n-2
     Diag(i)=2;
 end
 for i=1:n-3
     d(i+1)=d(i+1)-d(i)*miu(i+1)/Diag(i);
     Diag(i+1)=Diag(i+1)-lamta(i)*miu(i+1)/Diag(i);
 end
 
 
 s2(n-1)=d(n-2)/Diag(n-2);
 for j=1:n-3
     s2(n-1-j)=(d(n-2-j)-lamta(n-2-j)*s2(n-j))/Diag(n-2-j);
 end
 s2(1)=derix0;
 s2(n)=derixn;
 end
 
 if flag==2
   derix0=f11(I(1),alph,beta);
   derixn=f11(I(n),alph,beta);%%%%%%%save the boundary condition. give the first derivatives
 
     for i=2:n-1
         d(i)=6*A(3,i+1);
     end
     d(1)=-6*(derix0-A(2,2))/h(1);
     d(n)=6*(derixn-A(2,n))/h(n-1);
     
     
     %%%%%%  Gauss elimination  %%%%%%%%%%%%%%%
    for i=1:n
     Diag(i)=2;
 end
     d(2)=d(2)-d(1)*miu(1)/2;
     Diag(2)=Diag(2)-miu(1)/2;
     
     for i=2:n-2
         d(i+1)=d(i+1)-d(i)*miu(i)/Diag(i);
         Diag(i+1)=Diag(i+1)-lamta(i-1)*miu(i)/Diag(i);
     end
     
     d(n)=d(n)-d(n-1)/Diag(n-1);
     Diag(n)=Diag(n)-lamta(n-2)/Diag(n-1);
     
    s2(n)=d(n)/Diag(n);
     for j=1:n-2
         s2(n-j)=(d(n-j)-lamta(n-1-j)*s2(n-j+1))/Diag(n-j);
     end
     s2(1)=(d(1)-s2(2))/Diag(1);
 end 
     
     %%%%%%%%%%%%%%%%%  Now start to evaluate interpolating functional value at x %%%%%%%%%%%%%%%%%%%%%
     
     a=1; b=n;
     t=floor((a+b)/2);
     while (b-a)~=1
     if x==I(t)
        y=fun(t);
       break;
     elseif x>I(t)
             a=t;
     elseif x<I(t)
             b=t;
             end
     t=floor((a+b)/2);
                
     end
     
     
     %%%%%%%%% x lies in [I(a),I(b)] i=a %%%%%%%%%%%%%%%%%%
     if b-a==1
     l1=I(b)-x;
     l2=x-I(a);
     y=[1/(6*h(a)),h(a)/6,-(h(a)^2)/6]*[l1^3,l2^3;l2,-l2;1,0]*[s2(a);s2(b)]+A(2,b)*l2+fun(a);
     
     %%%y=s2(a)*l1^3/(6*h(a))+s2(b)*l2^3/(6*h(a))+(A(2,b)-h(a)*(s2(b)-s2(a)
     %%%)/6)*l2+fun(a)-s2(a)*h(a)^2/6;%%%%
     
     end
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
 
     
    
    
    
    
    
    
    
    
    
    
    
    

 