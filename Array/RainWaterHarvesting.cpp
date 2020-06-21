/* Apoorvaa has created an elevated roof. She wants to know how much water can she save during rain.

Given n non negative integers representing the elevation map where width of every bar is 1, Find the maximum water that she can save.

Explanation for the Sample input Testcase:
Elevation Map

So the total units of water she can save is 5 units

Input Format
First line contains an integer n. Second line contains n space separated integers representing the elevation map.

Constraints
1 <= N <= 10^6

Output Format
Print a single integer containing the maximum unit of waters she can save.

Sample Input
10
0 2 1 3 0 1 2 1 2 1
Sample Output
5
Explanation
Refer to the image for explanation. Count the number of cells having water in them.*/

//time- O(n)
//space- O(2n)

#include<iostream>
using namespace std;


int main() {
	int n;
	cin>>n;
	int* arr=new int[n];
	int* l=new int[n];  //l[i] stores the max height to the left of ith position including i
	int* r=new int[n];  //r[i] stores the max height to the right of ith position including i
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	//making l array
	l[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		l[i]=max(l[i-1],arr[i]);
	}
	//filling r array
	r[n-1]=arr[n-1];
	for(int i=n-2;i>=0;i--)
	{
		r[i]=max(r[i+1],arr[i]);
	}
	int ans=0;
	//calc the water trapped
	for(int i=0;i<n;i++)
	{
		ans+=(min(l[i],r[i])-arr[i]);
	}
	cout<<ans;

	delete[] arr;
	return 0;
}