/*Take as input N, the size of an integer array. Take one more input, which is a list of N integers separated by a space,
 and store that in an array. Write a recursive function which prints true if the array is sorted, and false otherwise.

Input Format
N x y z

Constraints
1 < N < 1000
-10^9 < i < 10^9, where i is an element of the array

Output Format
true OR false

Sample Input
5
1 2 3 4 5
Sample Output
true
*/

#include <iostream>
using namespace std;


bool isSorted(int* arr,int n)
{
	if(n==1 || n==0)
		return true;
	if(isSorted(arr+1,n-1) && arr[0]<=arr[1])
		return true;
	return false;
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
	cout<<isSorted(arr,n);
	delete[] arr;
}