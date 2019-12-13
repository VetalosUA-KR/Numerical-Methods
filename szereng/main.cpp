#include <iostream>
#include <cmath>

#define size 10

using namespace std;


int main()
{
    double arr[size][size];



    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            arr[i][j] = 0;
        }
    }

    arr[0][0] =  1;

    for(int i = 0; i < size; i++)
    {
        arr[i][0] = arr[i-1][0]+pow(-1, (i+1)-1) * 1.0/(i+1);
        for(int j = 1; j < size; j++)
        {
            if(j <= i)
            {
                arr[i][j] = (arr[i][j-1] + arr[i-1][j-1]) / 2 ;
            }
        }
    }

    cout<<endl;
    for(int i = 0; i < size; i++)
    {
        cout<<arr[i][0]<<endl;
        for(int j = 0; j < size; j++)
        {
            if(i = j) cout<<arr[i][j];

            //else cout<<" ";
        }
    }


    return 0;
}
