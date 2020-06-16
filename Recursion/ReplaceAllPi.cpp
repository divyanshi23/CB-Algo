/*Replace all occurrences of pi with 3.14

Input Format
Integer N, no of lines with one string per line

Constraints
0 < N < 1000
0 <= len(str) < 1000

Output Format
Output result one per line

Sample Input
3
xpix
xabpixx3.15x
xpipippixx
Sample Output
x3.14x
xab3.14xx3.15x
x3.143.14p3.14xx
Explanation
All occurrences of pi have been replaced with "3.14".

*/

#include <iostream>
#include <string>
using namespace std;


string removePi(string s)
{
	int n=s.size();
	if(n==1 || n==0)
		return s;
	string smallAns=removePi(s.substr(1,n-1));
	if(s[0]=='p' && smallAns[0]=='i')
	{
		return "3.14"+smallAns.substr(1);
	}
	return s[0]+smallAns;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		string ans=removePi(s);
		cout<<ans<<endl;
	}
	return 0;
}