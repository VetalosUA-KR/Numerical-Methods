
#include <iostream>
#include <cmath>

using namespace std;

double fun(double x){ return exp(x); }

double FUN (double x) { return exp(x);  }

double Q(double a, double b)
{
    double N[4] = { static_cast<double>(1)/8, static_cast<double>(3)/8, static_cast<double>(3)/8, static_cast<double>(1)/8 };
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



    double q = Q(a, b);

    double I = FUN(b) - FUN(a);

    double delta = fabs((I - q) / I);

    cout<<"q = "<<q<<endl;
    cout<<"delta = "<<delta<<endl<<endl;

    //int j = 1;
    for(int j = 1; j <= 30 ; j++)
    {
        long int N = pow(2, j);

        double H = (b-a)/N;

        q = 0;
        for(long int k = 0;  k <= N - 1; k++)
        {
            q = q + Q(a+k*H, a + (k+1)*H);
        }
        delta = fabs(I - q) / fabs(I);
        cout<<"\tN = "<<N<<"\t a = "<<a<<"\t delta = "<<delta<<endl;
    }

    return 0;
}















