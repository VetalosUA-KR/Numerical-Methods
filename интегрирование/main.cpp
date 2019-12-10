
#include <iostream>
#include <cmath>

using namespace std;

double fun(double x){ return exp(x); }

double FUN (double x) { return exp(x);  }

double Q(double N[], double a, double b)
{
    double q = 0;
    double x;
    double h;

    double sum = 0;
    h = (b-a)/3;
    for(int i = 0; i < 4; i++)
    {
        x = a + (i * h);
        sum += N[i] * fun(x);
    }
    q = (b-a)*sum;
    return q;
}

int main ()
{
    double a,b;

    cout<<"podaj a -> "; cin>>a;
    cout<<endl<<"podaj b -> "; cin>>b;
    double N[4] = { static_cast<double>(1)/8, static_cast<double>(3)/8, static_cast<double>(3)/8, static_cast<double>(1)/8 };


    double q = Q(N, a,b);

    double I = FUN(b) - FUN(a);

    double delta = fabs((I - q) / I);

    cout<<"q = "<<q<<endl;
    cout<<"delta = "<<delta<<endl;


    return 0;
}















