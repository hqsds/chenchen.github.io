function [H,b]=Householder(A,b)
S=size(A);
n=S(1);
k=S(2);
if n<k
error('matrix does not meet requirement'); return;
end

H=A;
% use h to store extra vector. and compute H1 then act it on H.
h=ones(n,1);
gama=sign(H(1,1))*norm(H(:,1));
h=A(:,1)+gama*eye(n,1);
a=-2/(norm(h).^2);
b=(eye(n)+a*h*h')*b;   %% change
H=(eye(n)+a*h*h')*H;   %% change

temp=b;
for p=1:n
temp(p)=b(p);    
for t=1:n
temp(p)=temp(p)+a*h(p)*h(t)*b(t);
end
end
b=temp;

for q=1:k
    temp=H(:,q);
  for p=1:n
      temp(p)=H(p,q);
      for t=1:n
          temp(p)=temp(p)+a*h(p)*h(t)*H(t,q);
      end
  end
  H(:,q)=temp;
end

kk=k;
if n==k
    kk=k-1;
end

for i=2:kk
    m=n-i+1;
    gama=sign(H(i,i))*norm(H(i:n,i));
    H(i:n,i-1)=H(i:n,i)+gama*eye(m,1);  
    a=-2/(norm(H(i:n,i-1)).^2);

%    b(i:n)=(eye(m)+a*H(i:n,i-1)*H(i:n,i-1)')*b(i:n);   %% change

    temp=b;
    for p=i:n
temp(p)=b(p);    
for t=i:n
temp(p)=temp(p)+a*H(p,i-1)*H(t,i-1)*b(t);
end
    end
    
b=temp;

for q=i:k
    temp=H(:,q);
  for p=i:n
      temp(p)=H(p,q);
      for t=i:n
          temp(p)=temp(p)+a*H(p,i-1)*H(t,i-1)*H(t,q);
      end
  end
  H(:,q)=temp;
end
%  H(i:n,i:k)=(eye(m)+a*H(i:n,i-1)*H(i:n,i-1)')*H(i:n,i:k);  %% change
end

% since the upper triangle R contained in H, we compute b=inv(R)*b to get the Xmin stored in x.  
b(k)=b(k)/H(k,k);
for i=(k-1):-1:1
  for j=k:-1:(i+1) 
     b(i)=b(i)-H(i,j)*b(j);
  end
  b(i)=b(i)/H(i,i);
end