program main 
        implicit none 
        real*8 A, B, y
	double precision x(1:5)
        A = 0.4d0 
        B = 0.3d0 

        call root(A,B,y) 

        !write(*,*) x(:)
        write(*,*) y

end program main 
