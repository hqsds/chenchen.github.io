function [x1,y1] = G2( x0,y0 )
x1=5;y1=5;k=0;
while ((x1-x0)^2+(y1-y0)^2 >0.000001)
    if k==0
    y1=1-exp(x0);
    x1=-sqrt(4-y0^2);
    else
     x0=x1;y0=y1;
     y1=1-exp(x0);
    x1=-sqrt(4-y0^2); 
    end
    k=k+1;
end
x1
y1
k  