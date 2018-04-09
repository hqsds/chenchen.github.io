number=0;
for precision=1:2                     
a=3;                                           
for aa=2:3  

    n=100;             
    for nn=1:3               
   
        for flag=1:3           
               
                epsilon=1/10000;                        
                for ee=1:3
                    test(a,n,precision,epsilon,flag,1); 
                    number=number+1  
                   epsilon=epsilon/(100.^ee);
                end

            end
      
        n=n*(10.^nn);
    end
    
    a=a+1;
        
end
end