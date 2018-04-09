function [error] = Midpoint(h)
%%% Apply Explicit Midpoint method%%%%%%%%
t=1; y0=1;
while(t<25)
    
    f1=f(t,y0);
    y1=y0+h*f(t+h/2,y0+(h/2)*f1);
    y0=y1;
    t=t+h;
end
error=abs(y0-1/25);