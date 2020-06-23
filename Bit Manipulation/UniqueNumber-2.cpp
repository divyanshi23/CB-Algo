/*We are given an array containg n numbers. All the numbers are present twice except for two numbers which are present only once. Find the unique numbers in linear time without using any extra space. ( Hint - Use Bitwise )

Input Format
First line contains the number n. Second line contains n space separated number.

Constraints
n < 10^5

Output Format
Output a single line containing the unique numbers separated by space

Sample Input
4
3 1 2 1
Sample Output
2 3
Explanation
Smaller number comes before larger number*/

#include<iostream>
using namespace std;

void findUnique(int *a,int n)
{
    int t=a[0];
    for(int i=1;i<n;i++)
    {
        t=t^a[i];
    }
    int temp=t;
    int i=0;
    while(temp>0)
    {
        if(temp&1)
        {
            break;
        }
        i++;
        temp=temp>>1;
    }
    int p=0;
    for(int j=0;j<n;j++)
    {
        if(a[j]&(1<<i))
        {
            p=p^a[j];
        }
    }
    //cout<<p<<" ";
    t=t^p;
	if(p<t)
		cout<<p<<" "<<t;
	else
    	cout<<t<<" "<<p;
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    findUnique(a,n);
	return 0;
}