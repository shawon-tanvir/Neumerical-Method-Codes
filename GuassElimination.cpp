#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Enter the order of matrix : ";
    int n;
    cin>>n;
    cout<<"Input elements row wise : "<<endl;
    float a[10][10];
    float x[10];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n+1; j++){
            //printf("A[%d][%d]: ", i, j);
            cin>>a[i][j];
        }
    }


    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i>j){
                float c = a[i][j]/a[j][j];
                for(int k=1; k<=n+1; k++){
                    a[i][k] -= c*a[j][k];
                }
            }
        }
    }

    x[n] = a[n][n+1]/a[n][n];
    float sum;
    for(int i=n-1; i>=1; i--){
        sum = 0;
        for(int j=i+1; j<=n; j++){
            sum += a[i][j]*x[j];
        }
        x[i] = (a[i][n+1]-sum)/a[i][i];
    }

    for(int i=1; i<=n; i++){
        cout<<"x"<<i<<" : "<<x[i]<<endl;
    }

    return 0;
}
