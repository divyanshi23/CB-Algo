/*Take as input str, a string. Write a recursive function which moves all ‘x’ from the string to its end.
E.g. for “abexexdexed” return “abeedeedxxx”.
Print the value returned

Input Format
Single line input containing a string

Constraints
Length of string <= 1000

Output Format
Single line displaying the string with all x's moved at the end

Sample Input
axbxc
Sample Output
abcxx
Explanation
All x's are moved to the end of string while the order of remaining characters remain the same.

*/

#include <iostream>
#include <string>
using namespace std;

string moveAtEnd(string s)
{
	int n=s.size();
	if(n==1 || n==0)
		return s;
	string smallAns=moveAtEnd(s.substr(1));
	if(s[0]=='x')
		return smallAns+s[0];
	return s[0]+smallAns;
}

int main()
{
	string s;
	cin>>s;
	string ans=moveAtEnd(s);
	cout<<ans;
	return 0;
}