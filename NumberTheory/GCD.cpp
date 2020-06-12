/*Take the following as input.

A number (N1)
A number (N2)
Write a function which returns the GCD of N1 and N2. Print the value returned.

*/




#include<iostream>
using namespace std; 

//Iterartive implementation
/*int main() {
	int n1,n2;
	cin>>n1>>n2;
	if(n1>n2)
	{
		swap(n1,n2);
	}
	while(n1!=0)
	{
		int temp=n1;
		n1=n2%n1;
		n2=temp;
	}
	cout<<n2;
	return 0;
}*/


//Recursive Implementation
int gcd(int a, int b)
{
	if(b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}

int main() {
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b);
	return 0;
}