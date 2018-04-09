function hw2testcase(flag,type)

% n=k
if flag==1
    
% know solution
    if type==1
        for i=1:5
A=random('unif',-200,200,50*i,50*i);
x=random('unif',-500,500,50*i,1);
b=A*x;
[H,y]=Householder(A,b);
norm(x-y(1:50*i))
        end
   
% don't know solution
    elseif type==2
for i=1:5
A=random('unif',-200,200,50*i,50*i);
b=random('unif',-500,500,50*i,1);
[H,x]=Householder(A,b);

norm(b-A*x(1:50*i))
end
    end
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% n>k b belong to R(A)
elseif flag==2
    
% know solution
if type==1
        
    for i=1:5
A=random('unif',-200,200,60*i,50*i);
x=random('unif',-500,500,50*i,1);
b=A*x;
[H,y]=Householder(A,b);
norm(x-y(1:50*i))
        end
% don't know solution
elseif type==2
 
        for i=1:5
A=random('unif',-200,200,60*i,50*i);
b=A*random('unif',200,500,50*i,1);
[H,x]=Householder(A,b);
norm(b-A*x(1:50*i))
        end
        
end



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%555
% n>k b does not belong to R(A)
elseif flag==3
   
    if type==1
% know solution   
    for i=1:5
        
A=random('unif',-200,200,60*i,50*i);
Q=orth(A);

A=Q*random('unif',-200,200,50*i,50*i);
v=random('unif',-500,500,60*i,1);
v1=Q*Q'*v;
v2=v-v1;
if norm(v1'*v2)>0.0000001
    error('not good');return;
end
a1=1;
a2=1;

while norm(a1*v1)/norm(a2*v2)<1 ||  norm(a1*v1)/norm(a2*v2)>5
a1=rand();
a2=rand();
end
b1=a1*v1;
b2=a2*v2;
b=b1+b2;

[H,x]=Householder(A,b);

norm(b-A*x(1:50*i))-norm(b2)
        end  

% don't know solution   
    elseif type==2
        for i=1:5
A=random('unif',-200,200,60*i,50*i);
b=random('unif',-500,500,60*i,1);
[H,x]=Householder(A,b);
r=A*x(1:50*i)-b;
e1=norm(r'*A);
min=1;
for j=1:100
y=random('unif',-500,500,50*i,1);
if norm(b-A*y)<norm(r)
min=0;
end
end
if min==0
    error('not the least square solution'); return;
end

[z,bint,rr] = regress(b,A);
e2=abs(norm(rr)-norm(r));
e3=norm(z-x(1:50*i));

maxe=e1;
if e2>maxe
    maxe=e2;
end
if e3>maxe
        maxe=e3;
end
maxe

        end          
    end     
end

