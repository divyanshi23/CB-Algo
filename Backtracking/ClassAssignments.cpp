/*In a mathematics class, Teacher ask Alice to find the number of all n digit distinct integers 
which is formed by the two distinct digits ai and bi but there is a rule to form n digit integer.

Rule: She has to form n digit integer by using two digits ai and bi without consecutive bi.

Alice is very weak in maths section. Help her to find the number of such n digit integers.

Input Format
The first line contains T, the number of test cases. Further T lines contains the value n which 
is the number of digit in the integer.

Constraints
1<=T<=20
1<=n<=25

Output Format
For each test case print the number of such n digit integer.

Sample Input
3
1
2
3
Sample Output
#1 : 2
#2 : 3
#3 : 5
Explanation
For n=1 : integers = a, b . For n=2 : integers = aa, ab, ba For n=3 : integers = aaa, aab, aba, 
baa, bab

*/

#include <iostream>
using namespace std;

void classAssignment(int l,char* out,int& ans,int n)
{
	if(l==0)
	{
		ans++;
		return;
	}
	if(l==n)
	{
		out[l-1]='a';
		classAssignment(l-1,out,ans,n);
		out[l-1]='b';
		classAssignment(l-1,out,ans,n);
		return;
	}
	out[l-1]='a';
	classAssignment(l-1,out,ans,n);
	if(out[l]=='b')
	{
		return;
	}
	out[l-1]='b';
	classAssignment(l-1,out,ans,n);
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		char* out=new char[n+1];
		out[n]='\0';
		int ans=0;
		classAssignment(n,out,ans,n);
		cout<<"#"<<i<<" : "<<ans<<endl;
	}
	return 0;
}