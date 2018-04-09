function test1(I)
[m,n]=size(I);
xx=linspace(I(1),I(n),1000);
for alph=1:9:19
    for beta=1:9:19
for flag=1:2
    for i=1:1000
        p(i)=Firstd(I,xx(i),flag,alph,beta);
        q(i)=secondd(I,xx(i),flag,alph,beta);
        ft(i)=f1(xx(i),alph,beta);
        temp1(i)=abs(p(i)-ft(i));
        temp2(i)=abs(q(i)-ft(i));
    end
    error(1)=max(temp1);
    error(2)=max(temp2);
    figure;
    plot(xx,p,'.')
    hold on;
    plot(xx,q,'-')
     hold on;
    plot(xx,ft,'--k')
    hold on;
    error
   
end
    end
end