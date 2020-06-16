/*Take as input N, the size of array. Take N more inputs and store that in an array. Take as input M, a number. Write a recursive function which returns an array containing indices of all items in the array which have value equal to M. Print all the values in the returned array.

Input Format
Enter a number N(size of the array) and add N more numbers to the array Enter number M to be searched in the array

Constraints
1 <= Size of array <= 10^5

Output Format
Display all the indices at which number M is found in a space separated manner

Sample Input
5
3
2
1
2
3
2
Sample Output
1 3
Explanation
2 is found at indices 1 and 3.*/

#include<iostream>
#include<vector>
using namespace std;

void allIndices(int*arr,int s,int n,int m,vector<int>& ans)
{
	if(n==0)
		return;
	if(arr[s]==m)
	{
		ans.push_back(s);
		//return;
	}
	allIndices(arr,s+1,n-1,m,ans);
}

int main()
{
	int n;
	cin>>n;
	int* arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int m;
	cin>>m;
	vector<int> ans;
	allIndices(arr,0,n,m,ans);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	delete[] arr;
	return 0;
}