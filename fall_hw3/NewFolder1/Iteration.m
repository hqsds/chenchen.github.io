function [X0,Zk,Ek,r,K,p]=Iteration(a,b,X0,epsilon,Xtrue,flag);
Max=1000;
s=size(b);
n=s(1);
count=1;

normx=norm(X0);
if normx<(epsilon/10)
    normx=1;
end
X00=X0;

Zk(1)=1;
Ek(1)=1;
r(1)=1;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%            Jacobi          %%%%%%%%%%%%%%%%%%
if flag==1
p=2*cos(pi/(n+1))/a;
while count<=Max && Ek(max(count,2)-1)> epsilon 
%%  && && Zk(count)>epsilon
Zk(count)=0;
Ek(count)=0;
denom=normx;
normx=0;

    for i=1:n         
        temp2=X0(i);
        
    if i==1
        X0(i)=(X0(i+1)+b(i))/a;
    else if i==n
           X0(i)=(temp1+b(i))/a;
        else
           X0(i)=(temp1+b(i)+X0(i+1))/a;
        end
    end
    
    temp1=temp2;
    
    Zk(count)=Zk(count)+(temp2-X0(i)).^2;
    Ek(count)=Ek(count)+(Xtrue(i)-X0(i)).^2;
    normx=normx+X0(i).^2;
    end
    normx=sqrt(normx);

    r(count)=0; 
    for i=1:n
     if i==1
        r(count)=r(count)+(b(i)-a*X0(i)+X0(i+1)).^2;
    else if i==n
          r(count)=r(count)+(b(i)-a*X0(i)+X0(i-1)).^2;
        else
         r(count)=r(count)+(b(i)-a*X0(i)+X0(i-1)+X0(i+1)).^2;
        end
     end
     end
    
    r(count)=sqrt(r(count))/norm(b);
    Zk(count)=sqrt(Zk(count))/denom;
    Ek(count)=sqrt(Ek(count))/norm(Xtrue);
    
    count=count+1;
end
X00=X00-Xtrue;
K=(log(epsilon)/(norm(X00)/norm(Xtrue)))/log(p);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%     Forward       GS       %%%%%%%%%%%%%%%%%%
elseif flag==2
p=(2*cos(pi/(n+1))/a)^2;
while count<=Max && Ek(max(count,2)-1)> epsilon 
%%  && && Zk(count)>epsilon
Zk(count)=0;
Ek(count)=0;
denom=normx;
normx=0;

   for i=1:n         
        temp=X0(i);        
    if i==1
        X0(i)=(b(i)+X0(i+1))/a;
    else if i==n
          X0(i)=(X0(i-1)+b(i))/a;
        else
           X0(i)=(X0(i-1)+b(i)+X0(i+1))/a;
        end
    end
    
    Zk(count)=Zk(count)+(temp-X0(i)).^2;
    Ek(count)=Ek(count)+(Xtrue(i)-X0(i)).^2;
    normx=normx+X0(i).^2; 
   end
    normx=sqrt(normx);

    r(count)=0; 
    for i=1:n
     if i==1
        r(count)=r(count)+(b(i)-a*X0(i)+X0(i+1)).^2;
     else if i==n
          r(count)=r(count)+(b(i)-a*X0(i)+X0(i-1)).^2;
        else
         r(count)=r(count)+(b(i)-a*X0(i)+X0(i-1)+X0(i+1)).^2;
         end
     end
    end
    
    r(count)=sqrt(r(count))/norm(b);
    Zk(count)=sqrt(Zk(count))/denom;
    Ek(count)=sqrt(Ek(count))/norm(Xtrue);
    
    count=count+1; 
end

X00=X00-Xtrue;
K=(log(epsilon)/(norm(X00)/norm(Xtrue)))/log(p);  

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%            SGS              %%%%%%%%%%%%%%%%%%
elseif flag==3 
p=(2*cos(pi/(n+1))/a)^4;
while count<=Max && Ek(max(count,2)-1)> epsilon 
%%  && && Zk(count)>epsilon
Zk(count)=0;
Ek(count)=0;
denom=normx;
normx=0;

temp=ones(n,1);
    for i=1:n         
        temp(i)=X0(i);        
    if i==1
        X0(i)=(b(i)+X0(i+1))/a;
    else if i==n
          X0(i)=(X0(i-1)+b(i))/a;
        else
           X0(i)=(X0(i-1)+b(i)+X0(i+1))/a;
        end
    end  
    end
    
     for i=n:-1:1         
    if i==1
        X0(i)=(b(i)+X0(i+1))/a;
    else if i==n
          X0(i)=(X0(i-1)+b(i))/a;
        else
           X0(i)=(X0(i-1)+b(i)+X0(i+1))/a;
        end
    end
    
    Zk(count)=Zk(count)+(temp(i)-X0(i)).^2;
    Ek(count)=Ek(count)+(Xtrue(i)-X0(i)).^2;
    normx=normx+X0(i).^2;
     end
    
        normx=sqrt(normx);

    r(count)=0; 
    for i=1:n
     if i==1
        r(count)=r(count)+(b(i)-a*X0(i)+X0(i+1)).^2;
     else if i==n
          r(count)=r(count)+(b(i)-a*X0(i)+X0(i-1)).^2;
        else
         r(count)=r(count)+(b(i)-a*X0(i)+X0(i-1)+X0(i+1)).^2;
         end
     end
    end    
    r(count)=sqrt(r(count))/norm(b);
    Zk(count)=sqrt(Zk(count))/denom;
    Ek(count)=sqrt(Ek(count))/norm(Xtrue);
    
    count=count+1;
end
X00=X00-Xtrue;
K=(log(epsilon)/(norm(X00)/norm(Xtrue)))/log(p);     
end
p
K
count=count-1