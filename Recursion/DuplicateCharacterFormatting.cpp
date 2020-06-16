/*Take as input str, a string. Write a recursive function which returns a new string in which all duplicate consecutive 
characters are separated by a ‘ * ’. E.g. for “hello” return “hel*lo”. Print the value returned

Input Format
Enter a String

Constraints
1<= Length of string <= 10^4

Output Format
Display the resulting string (i.e after inserting (*) b/w all the duplicate characters)

Sample Input
hello
Sample Output
hel*lo
Explanation
We insert a "*" between the two consecutive 'l' .

*/


#include<iostream>
#include<string>
using namespace std;

string duplicateCharacters(string s)
{
	int n=s.size();
	if(n==1)
		return s;
	string smallAns=duplicateCharacters(s.substr(1));
	if(s[0]==s[1])
		return s.substr(0,1)+'*'+smallAns;
	else
		return s.substr(0,1)+smallAns;
}

int main()
{
	string s;
	cin>>s;
	string ans=duplicateCharacters(s);
	cout<<ans;
	return 0;
}