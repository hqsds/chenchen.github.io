function [value,y,fun]=evaluate(x,I,m,n,flag)%%evaluate poly at x,I is the sequence of points oder
                               %%,m is degree of poly,n is the number of points you choose,
                               %%flag is point set you choose.
if flag==1
    for i=1:(n+1)
        y(i)=-1+2*(i-1)/n;
    end
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5    
    
elseif flag==2
        for i=1:(n+1)
        y(i)=cos((2*i-1)*pi/(2*n+2));
        end
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        
elseif flag==3
           
            for i=1:(n+1)
        y(i)=cos(pi*(i-1)/n);
            end
end
            %% choose three kinds of points
            
    for i=1:(n+1)
    fun(i)=f1(y(i));
    end
      %%compute the functional value at the interpolating points
    for i=1:m+1
        yorder(i)=y(I(i)+1);
    end %%the points according to the sequence I
    
    %%now start to build the divided difference table
    A=zeros(n+1,n+1);
    for j=1:n+1
        A(1,j)=fun(j);
    end
    
    for i=2:n+1
        for j=i:n+1
            A(i,j)=(A(i-1,j)-A(i-1,j-1))/(y(j)-y(j-i+1));
        end
    end
 
    %% now we just choose specific path
    J(1)=I(1);
    a(1)=A(1,J(1)+1);
    for i=2:m+1
        
        if (I(i)-J(i-1))==1
            J(i)=I(i);
        elseif (J(1)-I(i))==1
             
                j=i;
               while j>=2
                J(j)=J(j-1);
                j=j-1;
               end
            J(1)=I(i);
            
        else
            
           error('the path is not available');
           break;
        
        end
                a(i)=A(i,J(i)+1);
    end
    
    %%now we start to evaluate the value at x
    value=a(m+1);
    i=m;
    while(i>=1)
        value=value*(x-yorder(i));
        value=value+a(i);
        i=i-1;
    end

    
    
    
    
    
    
    
    
    
    
    
    
    
    