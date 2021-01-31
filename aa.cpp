#include <iostream>

using namespace std;

int main()
{
   int ar[3][3];
   int arr[3][3];
   
   cout<<"Enter the values";
   for(int i=0; i<3; i++)
   {
       for(int j=0; j<3; j++)
       {
           cin>>ar[i][j];
       }
   }
   
   for (int k=0; k<3; k++)
   {
       for(int l=0; l<3; l++)
       {
           arr[l][k]=ar[k][l];
       }
       
   }
   for (int p=0; p<3; p++)
   {
       for(int q=0; q<3; q++)
       {
           cout<<arr[p][q];
       }
   }
   
   return 0;
}
