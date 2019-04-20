#include<bits/stdc++.h>
using namespace std;

double horner(double x[],int degree,int q){
    double p[degree+2];
    p[degree+1]=x[degree+1];
    for(int i=degree;i>=1;i--){
        p[i]=x[i]+q*p[i+1];
    }
    return p[1];

}

void GaussElemination(double c[10][10],double b[],int m){
    double x[m];

    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(i>j){
                double factor=c[i][j]/c[j][j];
                for(int k=1;k<=m;k++){
                    c[i][k]=c[i][k]-factor*c[j][k];
                }
                b[i]=b[i]-factor*b[j];
            }
        }
    }
    double sum;
    x[m]=b[m]/c[m][m];
    for(int i=m-1;i>=1;i--){
        sum=0.0;
        for(int j=i+1; j<=m; j++)        {
            sum=sum+c[i][j]*x[j];
        }
        x[i]=(b[i]-sum)/c[i][i];
    }
    int it=1;
    for(int i=1;i<=m;i++){
        cout<<"a"<<it++<<" ="<<x[i]<<endl;
    }
    cout<<horner(x,m-1,2)<<endl;

}

int main()
{

    int n,order;
    cin>>n>>order;
    double x[n+1],y[n+1],c[10][10],b[10];

    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    int m=order+1;

    for(int j=1;j<=m;j++){
        for(int k=1;k<=m;k++){
            c[j][k]=0.0;
            for(int l=1;l<=n;l++){
                c[j][k]+=pow(x[l],j+k-2);
            }
        }
    }
    for(int j=1;j<=m;j++){
        b[j]=0.0;
        for(int l=1;l<=n;l++){
            b[j]+=pow(x[l],j-1)*y[l];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<b[i]<<endl;
    }
    cout<<endl;
    GaussElemination(c,b,m);

}
