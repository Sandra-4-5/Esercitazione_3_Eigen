#include<iostream>
#include "Eigen/Eigen"
#include<Eigen/Dense>
#include<iomanip>

using namespace Eigen;
using namespace std;

Vector2d SolvePALU(const Matrix2d& A,const Vector2d& b)
{
 
    PartialPivLU<Matrix2d> lu(A);
    Vector2d x=lu.solve(b);
    return x;
}

Vector2d SolveQR(const Matrix2d& A,const Vector2d& b)
{
 
    HouseholderQR<Matrix2d> qr(A);
    Vector2d x=qr.solve(b);
    return x;
}


int main()
{   Matrix2d A1, A2,A3;
   // Vector2d b1,b2, b3, x_es;
    double er1 ,er2, er3;

    A1<<5.547001962252291e-01, -3.770900990025203e-02,  8.320502943378437e-01,-9.992887623566787e-01;
    Vector2d b1(-5.169911863249772e-01, 1.672384680188350e-01);
 
    A2 <<5.547001962252291e-01,-5.540607316466765e-01,  8.320502943378437e-01,-8.324762492991313e-01;
    Vector2d b2(-6.394645785530173e-04, 4.259549612877223e-04);

    A3<<5.547001962252291e-01, -5.547001955851905e-01,  8.320502943378437e-01, -8.320502947645361e-01;
    Vector2d b3(-6.400391328043042e-10, 4.266924591433963e-10);

    Vector2d x_es(-1.0e+0,-1.0e+0);
   

    
    Vector2d x1_lu =SolvePALU(A1,b1);
    Vector2d x1_qr=SolveQR(A1,b1);
    er1=(x1_lu.norm()-x_es.norm())/(x_es.norm()); 

    Vector2d x2_lu =SolvePALU(A2,b2);
    Vector2d x2_qr=SolveQR(A2,b2);
    er2=(x2_lu.norm()-x_es.norm())/(x_es.norm());

    Vector2d x3_lu =SolvePALU(A3,b3);
    Vector2d x3_qr=SolveQR(A3,b3);
    er3=(x3_lu.norm()-x_es.norm())/(x_es.norm());
     return 0;
}
