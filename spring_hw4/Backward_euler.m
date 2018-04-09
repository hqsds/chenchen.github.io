function [error] = Backward_euler(h)
%%% Apply the Backward Euler method%%%%%%%%
t=1+h;  y0=1;
while(t<25)
    
    y1=-1/(10*t*h)+sqrt(1/(100*t^2*h^2)+y0/(5*t*h)+1/(t^2)-1/(5*t^3));
    y0=y1;
    t=t+h;
end
error=abs(y0-1/25);