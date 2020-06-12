/*You are given N elements, a1,a2,a3….aN. Find the number of good sub-arrays.
A good sub-array is a sub-array [ai,ai+1,ai+2….aj] such that (ai+ai+1+ai+2+….+aj) is divisible by N.



Input Format
The first line contains the number of test cases T. First line of each test case contains an integer N denoting the number of elements. Second line of each test case contains N integers, a1, a2, a3….aN, where ai denotes the ith element of the array.

Constraints
1<=T<=10
1<=N<=10^5
|ai|<=10^9

Output Format
Output a single integer denoting the number of good sub-arrays.

Sample Input
2
5
1 1 1 1 1
5
5 5 5 5 5
Sample Output
1
15
Explanation
In first test case, there is only one sub-array [1, 1, 1, 1, 1], such that 1+1+1+1+1=5, which is divisible by N=5*/



//Using pigeon hole principle
#include<iostream>
using namespace std;
#define ll long long

int main() {
	int q;
	cin>>q;
	while(q--)
	{
		ll int n;
		cin>>n;
		ll int* arr=new ll int[n];
		for(ll int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		ll int* div=new ll int[n+1];
		ll int* pre=new ll int[n]();
		div[0]=0;
		pre[0]++;
		for(ll int i=0;i<n;i++)
		{
			div[i+1]=(div[i]%n+arr[i]%n+n)%n;
			pre[div[i+1]]++;
		}
		ll int ans=0;
		for(ll int i=0;i<n;i++)
		{
			ans+=((pre[i]*(pre[i]-1))/2);
		}
		cout<<ans<<endl;
	}
	return 0;
}