/*Take as input x and n, two numbers. Write a function to calculate x raise to power n. Target complexity is O(logn). NOTE: Try both recursive and bitmasking approach.

Input Format
Enter the number N and its power P

Constraints
None

Output Format
Display N^P

Sample Input
2
3
Sample Output
8*/

#include<iostream>
using namespace std;

int fastExponentiation(int a,int b)
{
	int ans=1, x=a;
	while(b>0)
	{
		int last_bit=(b&1);
		if(last_bit==1)
			ans=ans*x;
		x=x*x;
        b=b>>1;
	}
	return ans;
}

int main()
{
	int a,b;
	cin>>a>>b;
	cout<<fastExponentiation(a,b);
}