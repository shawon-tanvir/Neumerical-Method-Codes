#include<bits\stdc++.h>
using namespace std;

int main(){

    double x[10],y[10],p[10];
    int n,k,j=1,i;
    double f,f2=0,f1=1;
    printf("Enter the number of observations: ");
    cin>>n;

    printf("Enter the values of X: ");
    for(int i = 1; i <= n; i++){
        cin>>x[i];
    }


    printf("Enter the values of corresponding Y: ");
    for(int i = 1; i <= n; i++){
        cin>>y[i];
    }

    f = y[1];


    printf("Enter the value of k for f(k) that would be evaluated: ");
    cin>>k;

    do
    {
        for (i=1;i<=n-1;i++)
        {
            p[i] = ((y[i+1]-y[i])/(x[i+j]-x[i]));
            y[i]=p[i];
        }
        for(int i = 1; i <= n; i++){
        cout<<y[i]<<" ";
        }
        cout<<endl;
        f1=1;
        for(i=1;i<=j;i++){
            f1*=(k-x[i]);
        }
        f2+=(y[1]*f1);
        n--;
        j++;

    }while(n!=1);

    f+=f2;
    printf("\nf(%d) = %lf", k , f);

    return 0;
}
