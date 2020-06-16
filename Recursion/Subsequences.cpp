/*Take as input str, a string. We are concerned with all the possible subsequences of str. E.g.

a. Write a recursive function which returns the count of subsequences for a given string. Print the value returned.

b. Write a recursive function which prints all possible subsequences for a “abcd” has following subsequences “”, “d”, “c”, “cd”, “b”, “bd”, “bc”, “bcd”, “a”, “ad”, “ac”, “acd”, “ab”, “abd”, “abc”, “abcd”.given string (void is the return type for function).
Note: Use cin for input for C++

Input Format
Enter a string

Constraints
None

Output Format
Display the total no. of subsequences and also print all the subsequences in a space separated manner

Sample Input
abcd
Sample Output
 d c cd b bd bc bcd a ad ac acd ab abd abc abcd 
16
Explanation
Print all possible subsequences of the given string.

*/

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

vector<string> subsequence(string s)
{
	if(s.size()==0)
	{
		vector<string> v;
		v.push_back("");
		return v;
	}
	vector<string> smallAns=subsequence(s.substr(1));
	int n=smallAns.size();
	for(int i=0;i<n;i++)
	{
		smallAns.push_back(s[0]+smallAns[i]);
	}
	return smallAns;
}


int main()
{
	string s;
	cin>>s;
	vector<string> ans=subsequence(s);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	int count=pow(2,s.size());
	cout<<count;
	return 0;
}