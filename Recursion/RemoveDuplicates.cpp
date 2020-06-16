/*Take as input S, a string. Write a function that removes all consecutive duplicates. Print the value returned.

Input Format
String

Constraints
A string of length between 1 to 1000

Output Format
String

Sample Input
aabccba
Sample Output
abcba
Explanation
For the given example, "aabccba", Consecutive Occurrence of a is 2, b is 1, and c is 2.

After removing all of the consecutive occurences, the Final ans will be : - "abcba".*/


#include<iostream>
#include<string>
using namespace std;

string removeDuplicates(string s)
{
	int n=s.size();
	if(n==0 || n==1)
		return s;
	string smallAns=removeDuplicates(s.substr(1,n-1));
	if(s[0]==smallAns[0])
		return smallAns;
	else
		return s[0]+smallAns;
}

int main()
{
	string s;
	cin>>s;
	string ans=removeDuplicates(s);
	cout<<ans;
	return 0;
}