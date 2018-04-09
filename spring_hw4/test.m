function [err1,err2,err3,err4]=test(I)
for i=1:7
    err1(i)=Forward_euler(I(i));
    err2(i)=Midpoint(I(i));
    err3(i)=RK(I(i));
    err4(i)=Backward_euler(I(i));
end
err1
err2
err3
err4