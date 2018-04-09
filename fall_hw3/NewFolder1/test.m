function test(a,n,precision,epsilon,flag,initial)

if precision==1
a=single(a);
if initial==1
Xtrue=single(random('unif',-1,1,n,1));   % normalize
X0=single(random('unif',-1,1,n,1));
Xtrue=Xtrue/norm(Xtrue);
X0=X0/norm(X0);
else
X0=zeros(n,1); 
Xtrue=ones(n,1);
end
b=single(ones(n,1));
else
    a=double(a);
    if initial==1
Xtrue=double(random('unif',-1,1,n,1));   % normalize
X0=double(random('unif',-1,1,n,1));
Xtrue=Xtrue/norm(Xtrue);
X0=X0/norm(X0);
    else
X0=zeros(n,1); 
Xtrue=ones(n,1);
    end
b=double(ones(n,1));
end


b(1)=a*Xtrue(1)-Xtrue(2);
for i=2:n-1
b(i)=-Xtrue(i-1)+a*Xtrue(i)-Xtrue(i+1);
end
b(n)=-Xtrue(n-1)+a*Xtrue(n);

[x,Zk,Ek,r,K,p]=Iteration(a,b,X0,epsilon,Xtrue,flag);
norm(x-Xtrue)/norm(Xtrue)