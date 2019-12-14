!  Fortran_code.f90 
!

program Fortran_code

        implicit none

        ! Variables
        double precision a(1:5),b(1:4)
        real :: x,y(1:8)=5
        integer i
        real,external :: callpy
        

        ! 循环50次
        do i=1,50
        ! 定义一个数组a(1:5)=0.0
        a(1:5)=0.d0
        ! 输出数组的值到屏幕
        write(*,*) a(:)
        ! 以下函数需要编写！
        call py_predict(a,b)  ! 或b(1:4)=py_predict(a)
        ! 输出并检查
        print *, "---------------"
        x = callpy(y)
        write(*,*) x
        write(*,*) b(:)
        end do

        call exit()



end program Fortran_code

real function callpy(y)
        real :: y
        callpy = 100
end function callpy

subroutine py_predict(a,b)
        ! 在该函数中调用Python，函数输入为a，输出为a,b
        double precision a(5)
        double precision b(4)

        !***********some code to communicate with Python*******************
        !***********some code to communicate with Python*******************
        !***********some code to communicate with Python*******************
        !***********some code to communicate with Python*******************

end subroutine py_predict
