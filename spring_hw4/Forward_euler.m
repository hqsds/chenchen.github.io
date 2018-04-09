function [error] = Forward_euler(h)
%%% Apply the Forward Euler method%%%%%%%%
t=1; y0=1;
while (t<25)
    
    y1=y0+h*f(t,y0);
    y0=y1;
    t=t+h;
    
end
    
error=abs(y0-1/25);