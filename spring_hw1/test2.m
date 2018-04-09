function test2(I1,I2,m,n,flag)
xx=linspace(-1,1,1000);
    for i=1:1000
        [p1(i),y,fun]=evaluate(xx(i),I1,m,n,flag);
        [p2(i),y,fun]=evaluate(xx(i),I2,m,n,flag);
    end
    error=max(abs(p1-p2))
    figure(1);
plot(xx,p1,'-k')
hold on;
plot(xx,p2,'--k')
hold on;