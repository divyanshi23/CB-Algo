/*Given three numbers a,b,c. Calculate (a^b)mod c.

Input Format
Single line containing three integers a,b,c separated by space.

Constraints
1<=a,b,c<=100000

Output Format
Print (a^b)mod c.

Sample Input
2 2 3
Sample Output
1
Explanation
(2^2)mod 3=4 mod 3 = 1*/


#include<iostream>
using namespace std;
#define ll long long

ll fastPowerMod(int a,int b,int c)
{
	if(b==0)
		return 1;
	if(b==1)
		return a%c;
	ll temp=fastPowerMod(a,b/2,c);
	ll ans;
	if(b&1)
	{
		ans=((temp%c)*(temp%c)*(a%c))%c;
	}
	else
	{
		ans=((temp%c)*(temp%c))%c;
	}
	return ans;
}

int main() {
	int a,b,c;
	cin>>a>>b>>c;
	ll ans=fastPowerMod(a,b,c);
	cout<<ans;
	return 0;
}