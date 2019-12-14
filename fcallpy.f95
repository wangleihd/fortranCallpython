program main 
        implicit none 
        real*8 A, B, y, x 
        A = 0.4d0 
        B = 0.3d0 

        call root(A,B,y,x) 

        write(*,*) y,x 

end program main 
