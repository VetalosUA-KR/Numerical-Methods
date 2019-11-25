#include <iostream>
#include <cmath>

using namespace std;

int main ()
{

    /*float a = 2.0;
    cout.precision(17);
    for(int i = 1; i < 100; i++)
    {
        cout<<1+pow(a, -i)<<" = "<<i<<endl;
    }*/

    cout.precision(17);
    float l = 0.0;
    float p = 0.0;
    for(int i = 1; i < 20; i++)
    {
        l = sqrt(pow(pow(3, -i), 2) + 1) - 1;
        p = pow(pow(3, -i), 2)/sqrt(pow(pow(3, -i), 2) + 1) + 1;
        cout<<l<<"  ==   "<<p<<endl;

    }

    return 0;
}
