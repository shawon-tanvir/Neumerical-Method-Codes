#include<bits/stdc++.h>

using namespace std;

double arr[3][4] =
{
    {2,1,1,10},
    {3,2,3,18},
    {1,4,9,16},
};

void normalize(int row)
{
   //cout<<"normal of row "<<row<<" :   ";
   double divider = arr[row][row];
  for(int i=row;i<=3;i++)
  {
  arr[row][i] = arr[row][i]/divider;
   // printf("%.0lf\t",arr[row][i]);
  }
   //  cout<<endl;

}


void gj()
{
  for(int i=0;i<=2;i++)
  {
    normalize(i);
    for(int j=0;j<=2 ;j++)
    {
      if(j!=i)
      {
      double multiplier = arr[j][i];
       for(int k=0;k<=3;k++)
       {
         arr[j][k] = arr[j][k] - multiplier*arr[i][k];
        // printf("%.0lf\t",arr[j][k]);
       }
      // cout<<endl;
      }


    }
    for(int p=0;p<3;p++){
            for(int q=0;q<=3;q++){
                cout<<arr[p][q]<<" ";
            }
            cout<<endl;
      }
      cout<<endl;
  }
  printf("%.0lf %.0lf %.0lf\n",arr[0][3],arr[1][3],arr[2][3]);

}


int main()
{
 gj();
  return 0;
}
