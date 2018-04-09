function test4(I1,m,n,flag)
xx=linspace(-1,1,1000);
    for i=1:1000
        [p1(i),y,fun]=evaluate(xx(i),I1,m,n,flag);
    end
    plot(xx,p1,'-')
