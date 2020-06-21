/*Take as input N, the size of array. Take N more inputs and store that in an array. Take as input “target”, a number. Write a function which prints all pairs of numbers which sum to target.

Input Format
The first line contains input N. Next N lines contains the elements of array and (N+1)th line contains target number.

Constraints
Length of the arrays should be between 1 and 1000.

Output Format
Print all the pairs of numbers which sum to target. Print each pair in increasing order.

Sample Input
5
1
3
4
2
5
5
Sample Output
1 and 4
2 and 3
Explanation
Find any pair of elements in the array which has sum equal to target element and print them.*/


#include<iostream>
#include<algorithm>

using namespace std;

void printPairs(int *a,int n,int t)
{
    sort(a,a+n);
    int l=0,r=n-1;
    while(l<r)
    {
        int s=a[l]+a[r];
        if(s==t)
        {
            cout<<a[l]<<" and "<<a[r]<<endl;
            l++;
            r--;
        }   
        else if(s>t)
            r--;
        else
            l++;
    }
}

int main() {
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int t;
    cin>>t;
    printPairs(a,n,t);
	return 0;
}