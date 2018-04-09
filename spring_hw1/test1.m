function test1(m,n)
for i=1:(m+1)
    I(i)=i-1;
end
xx=linspace(-1,1,1000);
for flag=1:3
    for i=1:1000
        [p(i),y,fun]=evaluate(xx(i),I,m,n,flag);
        ft(i)=f1(xx(i));
        temp(i)=abs(p(i)-ft(i));
    end
    error(flag)=max(temp);
    figure(flag);
    plot(y,fun,'*')
    hold on;
    plot(xx,p,'-')
     hold on;
    plot(xx,ft,'--k')
    hold on;
   
end
error