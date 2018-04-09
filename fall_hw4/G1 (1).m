function [x1,y1] = G1( x0,y0 )
x1=5;y1=5;k=0;
while ((x1-x0)^2+(y1-y0)^2 >0.000001)
    if k==0
    x1=log(1-y0);
    y1=-sqrt(4-x0^2);
    else
     x0=x1;y0=y1;
     x1=log(1-y0);
    y1=-sqrt(4-x0^2); 
    end
    k=k+1;
end
x1
y1
k  
