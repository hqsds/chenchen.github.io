function [error] = RK(h)
%%% Apply Runge kutta method%%%%%%%%
t=1; y0=1;
while(t<25)
    
    f1=f(t,y0);
    f2=f(t+h/2,y0+(h/2)*f1);
    f3=f(t+h/2,y0+(h/2)*f2);
    f4=f(t+h,y0+h*f3);
    y1=y0+h*(f1+2*f2+2*f3+f4)/6;
    y0=y1;
    t=t+h;
    
end
error=abs(y0-1/25);