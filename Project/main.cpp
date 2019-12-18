#include <iostream>
#include <cmath>
#include <math.h>
#include <stdio.h>


using namespace std;

double func(double x)
{
    return (pow(x, 2) + 3) * exp(x-5) - 2; // вольфрам
}

double funcPrim(double x)
{
    return 2*x*exp(x-5)+(x*x+3)*exp(x-5);
}

double U(double x)
{
    return func(x)/funcPrim(x);
}

/**
Функции со своим уровнением
*/
double func2(double x)
{
    return 4*pow(x,3)-12*pow(x,2)+6; // вольфрам
}

double funcPrim2(double x)
{
    return 12*pow(x,2)-24*x;
}

double U2(double x)
{
    return func2(x)/funcPrim2(x);
}
/// ////////////////////////////////
double Newton2(double x, double epsilon)
{
    int k = 0;
    double h;

    do
    {
        h = -U2(x);
        x += h;
        k++;
    }
    while(fabs(h) >= epsilon);
    cout<<"k: "<<k<<"  ";
    return x;
}

double wielopunkt2(double x, double elipson)
{
    int k = 0;
    double h;

    do
    {
        h = -((1/4.0) * ( U2(x) + ( (3*func2(x)) / funcPrim2(x - (2/9.0) * (2*U2(x) + (func2(x) / funcPrim2(x-U2(x))))) )));
        x += h;
        k++;
    }
    while(fabs(h) >= elipson);
    cout<<"k: "<<k<<"  ";
    return x;
}
/// ////////////////////////////

double newton(double x, double epsilon)
{
    int k = 0;
    double h;

    do
    {
        h = -U(x);
        x += h;
        k++;
    }
    while(fabs(h) >= epsilon);
    cout<<"k: "<<k<<"  ";
    return x;
}

double wielopunktowa(double x, double elipson)
{
    int k = 0;
    double h;

    do
    {
        h = -((1/4.0) * ( U(x) + ( (3*func(x)) / funcPrim(x - (2/9.0) * (2*U(x) + (func(x) / funcPrim(x-U(x))))) )));
        x += h;
        k++;
    }
    while(fabs(h) >= elipson);
    cout<<"k: "<<k<<"  ";
    return x;
}

int main()
{
    cout.precision(15);

    double eps;
    double rez;
    cout<<"metoda wielopunktowa, X-const"<<endl;
    for(int i = 3; i <= 15; i++) // приближена
    {
        eps = pow(10, -i);
        cout<<"e = "<<eps<<" ";
        rez = wielopunktowa(i, eps);
        cout<<"x = "<<rez<<endl;
    }
    cout<<"*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*//*/*/"<<endl;
    cout<<"metoda wielopunktowa, E-const"<<endl;
    for(float i = -3; i <= 3; i+=0.4)
    {
        eps = pow(10, -6);
        cout<<"x0 =  "<<i<<"  ";
        rez = wielopunktowa(i,eps);
        cout<<"x = "<<rez<<endl;

    }

    cout<<"*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*//*/*/"<<endl;
    cout<<"metoda wielopunktowa, z bladem, X-const"<<endl;
    double x1 = 3.1393661328361496816;  /// x1
    double blad = 0;
    for(int i = 3; i <= 15; i++)
    {
        eps = pow(10, -i);
        cout<<"e = "<<eps;
        rez = wielopunktowa(i, eps);
        cout<<"x = "<<rez;
        if(rez<0) blad = fabs(rez - x1)/fabs(x1);
       // else if(rez>0) blad = fabs(rez - x1)/fabs(x1);

        cout<<"  blad = "<<blad<<endl;// wzgledny blad
    }

    cout<<"*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*//*/*/"<<endl;
    cout<<"metoda wielopunktowa, z bladem, E-const"<<endl;
    //x1 = 0;
    blad = 0;
    for(float i = -3; i <= 3; i+=0.4)
    {
        eps = pow(10, -6);
        cout<<"x0 =  "<<i<<"  ";
        rez = wielopunktowa(i,eps);
        cout<<"x = "<<rez;
        //blad = fabs(rez - x1);/// wzgledny blad
        blad = fabs((rez - x1)/x1);
        cout<<"  blad = "<<blad<<endl;
    }

    cout<<"*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*//*/*/"<<endl;
    cout<<"metoda newtona, X-const"<<endl;

    for(int i = 3; i <= 15; i++) // приближена
    {
        eps = pow(10, -i);
        cout<<"e = "<<eps<<" ";
        rez = newton(i, eps);
        cout<<"x = "<<rez<<endl;
    }
    cout<<"*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*//*/*/"<<endl;
    cout<<"metoda newtona, E-const"<<endl;
    for(float i = -3; i <= 3; i+=0.4)
    {
        eps = pow(10, -6);
        cout<<"x0 =  "<<i<<"  ";
        rez = newton(i,eps);
        cout<<"x = "<<rez<<endl;
    }
    cout<<"*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*//*/*/"<<endl;
    cout<<"metoda newtona, z bladem, X-const"<<endl;
    //x1 = 0;
    blad = 0;
    for(int i = 3; i <= 15; i++)
    {
        eps = pow(10, -i);
        cout<<"e = "<<eps;
        rez = newton(i, eps);
        cout<<"x = "<<rez;
        blad = fabs((rez - x1)/x1);
        cout<<"  blad = "<<blad<<endl;// wzgledny blad
    }
    cout<<"*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*//*/*/"<<endl;
    cout<<"metoda newtona, z bladem, E-const"<<endl;
    //x1 = 0;
    blad = 0;
    for(float i = -3; i <= 3; i+=0.4)
    {
        eps = pow(10, -6);
        cout<<"x0 =  "<<i<<"  ";
        rez = newton(i,eps);
        cout<<"x = "<<rez;
        blad = fabs((rez - x1)/x1);
        cout<<"  blad = "<<blad<<endl;// wzgledny blad
    }


    /// ниже должно быть свое уравнение


    cout << endl << "ROWNANIE: " << endl; /// 4*x^3 - 12*x^2 + 6
    //PIERWIASTKI ROWNANIA
    x1 = -0.641783527452926;
    double x2 = 0.831745598218973;
    double x3 = 2.81003792923395;
    cout << "Metoda wielopunktowa: " << endl;

    cout << "A (x-const):" << endl;

    for(int i=3; i<15; i++)
    {
        eps = pow(10, -i);
        cout << "e: " << eps <<endl;
        double w = wielopunkt2(i, eps);
         cout << "x:" <<w << endl << endl;

    }

    cout << "/------------------------------------------------------/" << endl;
    cout << "B (e-const): " << endl;

    for(float i=-3; i<=3; i=i+0.4)
    {
        eps = pow(10, -6);
        cout << "x0: " << i <<endl;
        double w = wielopunkt2(i, eps);
        cout << "x:" <<w << endl << endl;

    }

    cout << "/------------------------------------------------------/" << endl;
    cout << "C (x-const): " << endl;

    blad = 0;
    for(int i=3; i<15; i++)
    {
        eps = pow(10, -i);
        cout << "e: " << eps <<endl;
        double w = wielopunkt2(i, eps);
        cout << "x:" <<w <<endl;
        if(w<0) blad = (fabs(w-x1)/fabs(x1));
        else if(w>1) blad = (fabs(w-x2)/fabs(x2));
        else blad = (fabs(w-x3)/fabs(x3));
        cout << "blad:" << blad <<endl << endl;

    }

     cout << "/------------------------------------------------------/" << endl;
    cout << "D (e-const): " << endl;
    //x1 = 0;//pierwiastek rownania
    blad = 0;
    for(float i=-3; i<=3; i=i+0.4)
    {
        eps = pow(10, -6);
        cout << "x0: " << i <<endl;
        double w = wielopunkt2(i, eps);
         cout << "x:" <<w <<endl;
         if(w<0) blad = (fabs(w-x1)/fabs(x1));
         else if(w>1) blad = (fabs(w-x2)/fabs(x2));
         else blad = (fabs(w-x3)/fabs(x3));
         cout << "blad:" << blad <<endl << endl;

    }

    cout << "/------------------------------------------------------/" << endl;
    cout << "Metoda Newtona: " << endl;
    cout << "A (x-const):" << endl;

    for(int i=3; i<15; i++)
    {
        eps = pow(10, -i);
        cout << "e: " << eps <<endl;
        double w = Newton2(i, eps);
         cout << "x:" <<w << endl << endl;

    }

    cout << "/------------------------------------------------------/" << endl;
    cout << "B (e-const):" << endl;

    for(float i=-3; i<=3; i=i+0.4)
    {
        eps = pow(10, -6);
        cout << "x0: " << i <<endl;
        double w = Newton2(i, eps);
        cout << "x:" <<w << endl << endl;

    }

    cout << "/------------------------------------------------------/" << endl;
    cout << "C (x-const): " << endl;
    //x1 = 0;//pierwiastek rownania
    blad = 0;
    for(int i=3; i<15; i++)
    {
        eps = pow(10, -i);
        cout << "e: " << eps <<endl;
        double w = Newton2(3, eps);
        cout << "x:" <<w <<endl;
        if(w<0) blad = (fabs(w-x1)/fabs(x1));
        else if(w>1) blad = (fabs(w-x2)/fabs(x2));
        else blad = (fabs(w-x3)/fabs(x3));
        cout << "blad:" << blad <<endl << endl;

    }


     cout << "/------------------------------------------------------/" << endl;
    cout << "D (e-const): " << endl;
    //x1 = 0;//pierwiastek rownania
    blad = 0;
    for(float i=-3; i<=3; i=i+0.4)
    {
        eps = pow(10, -6);
        cout << "x0: " << i <<endl;
        double w = Newton2(i, eps);
        cout << "x:" <<w <<endl;
        if(w<0) blad = (fabs(w-x1)/fabs(x1));
        else if(w>1) blad = (fabs(w-x3)/fabs(x3));
        else blad = (fabs(w-x2)/fabs(x2));
        cout << "blad:" << blad <<endl << endl;

    }

    return 0;
}















