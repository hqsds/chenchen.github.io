for j=1:2
    for i=1:5
     A=random('unif',-100,100+20*i,50*i,50*i-10*i*(j-1));   
        b=random('unif',-200-20*i,200,50*i,1);
     [C,R]=qr(A);
     [H,b]=Householder(A,b);
       RR=triu(H);
       norm(RR-R)
    end
end

hw2testcase(1,1)
hw2testcase(1,2)
hw2testcase(2,1)
hw2testcase(2,2)
hw2testcase(3,1)
hw2testcase(3,2)