/*Given an array A, of N elements. Sort the array using quicksort algorithm.(Note : Use randomized quicksort,
 otherwise worst case will not pass).

Input Format
A single integer, N, denoting the number of elements in array. Next line contains N integers, denoting the elements 
of array.

Constraints
1<=N<=2*10^5 |Ai|<=10^9

Output Format
Print in a single line, N spaced integers, denoting the elements of array A in sorted order.

Sample Input
5
3 6 4 1 2
Sample Output
1 2 3 4 6*/

#include <iostream>
using namespace std;

int partition(int *arr,int s,int e)
{
	int r=s+(rand()%(e-s+1));
	swap(arr[r],arr[e]);
	int i=s,j=s;
	while(j<e)
	{
		if(arr[j]<arr[e])
		{
			swap(arr[j++],arr[i++]);
		}
		else
			j++;
	}
	swap(arr[i],arr[e]);
	return i;
}


void sortQuick(int *arr,int s,int e)
{
	if(s<e)
	{
		int pivot=partition(arr,s,e);
		sortQuick(arr,s,pivot-1);
		sortQuick(arr,pivot+1,e);
	}
}


int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int* arr=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	sortQuick(arr,0,n-1);
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}