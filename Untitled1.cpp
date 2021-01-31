
#include<iostream>
#include<iomanip>
using namespace std;
long long int mergeArrays(int arr[],int beg,int mid,int end)
{
	int i,j,*temp,k=0,p=0;
	long long int count=0;
	temp=new int[end-beg+1];
	i=beg;j=mid+1;
	while(i<=mid && j<=end){
		while(j<=end && arr[i] > arr[j]){temp[k++]=arr[j++];++p;}
		count+=p;
		temp[k++]=arr[i++];
	}
	while(j<=end){
		temp[k++]=arr[j++];
	}
	while(i<=mid){	temp[k++]=arr[i++]; count+=(end-mid);}
	for(i=0;i<k;i++)	arr[beg+i]=temp[i];
return count;
}

long long int countInversion(int arr[],int beg,int end){
	int mid;
	long long int noi=0;
	if(beg<end){
		mid=(beg+end)/2;
		noi=countInversion(arr,beg,mid);
		noi+=countInversion(arr,mid+1,end);
		noi+=mergeArrays(arr,beg,mid,end);
	}
	return noi;
}
int main()
{
	int i, a[100000];
	for(i=0;i<100000;i++)	cin>>a[i];
	cout<<countInversion(a,0,99999)<<endl;

return 0;
}


