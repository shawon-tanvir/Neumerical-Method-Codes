#include<bits\stdc++.h>
using namespace std;
int main(){

    int x[10],y[10];
    int i,j,a,n;
    float s,t,k=0;

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

 printf("\nEnter the value of X to find the value of respective Y:");
    cin>>a;

    for(i=1;i<=n;i++){
        s=1;
        t=1;
        for(j=1;j<=n;j++){
            if(j!=i){
                s=s*(a-x[j]);
                t=t*(x[i]-x[j]);
            }
        }
        k=k+((s/t)*y[i]);

    }
    printf("\nSo for X=%d, Y = %f",a,k);
    return 0;
}
