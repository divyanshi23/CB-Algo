/*Given an array A, of N elements. Sort the array using mergesort algorithm.

Input Format
A single integer, N, denoting the number of elements in array. Next line contains N integers, denoting the elements of 
array.

Constraints
1<=N<=2*10^5 |Ai|<=10^9

Output Format
Print in a single line, N spaced integers, denoting the elements of array A in sorted order.

Sample Input
5
3 6 4 1 2
Sample Output
1 2 3 4 6 */


#include <iostream>
using namespace std;

void merge(int* arr,int s,int e)
{
	int mid=s+(e-s)/2;
	int* out=new int[e-s+1];
	int i=s,j=mid+1,k=0;
	while(i<=mid && j<=e)
	{
		if(arr[i]<=arr[j])
		{
			out[k++]=arr[i++];
		}
		else
			out[k++]=arr[j++];
	}
	while(i<=mid)
		out[k++]=arr[i++];
	while(j<=e)
		out[k++]=arr[j++];
	k=0;
	for(int i=s;i<=e;i++)
	{
		arr[i]=out[k++];
	}
}

void mergeSort(int* arr,int s,int e)
{
	if(s<e)
	{
		int mid=s+(e-s)/2;
		mergeSort(arr,s,mid);
		mergeSort(arr,mid+1,e);
		merge(arr,s,e);
	}
}

int main()
{
	int n;
	cin>>n;
	int* arr=new int [n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	mergeSort(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}