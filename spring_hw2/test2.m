function test2(a,b,n)
xx=linspace(a,b,1000);
for alph=1:9:19
    for beta=1:9:19
    for i=1:1000
        p(i)=B(n,a,b,xx(i),alph,beta);
        ft(i)=f1(xx(i),alph,beta);
        temp(i)=abs(p(i)-ft(i));
        
    end
    error=max(temp);
    figure;
    plot(xx,p,'-')
    hold on;
    plot(xx,ft,'--k')
    hold on;
    error
end
    end
end