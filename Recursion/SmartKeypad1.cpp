/*You will be given a numeric string S. Print all the possible codes for S.

Following vector contains the codes corresponding to the digits mapped.

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

For example, string corresponding to 0 is " " and 1 is ".+@$"

Input Format
A single string containing numbers only.

Constraints
length of string <= 10

Output Format
All possible codes one per line in the following order.

The letter that appears first in the code should come first

Sample Input
12
Sample Output
.a
.b
.c
+a
+b
+c
@a
@b
@c
$a
$b
$c
Explanation
For code 1 the corresponding string is .+@$ and abc corresponds to code 2.*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

vector<string> keypad(string s)
{
	if(s.size()==0)
	{
		vector<string> v;
		v.push_back("");
		return v;
	}
	vector<string> smallAns=keypad(s.substr(1));
	int n=smallAns.size();
	vector<string> ans;
	for(int i=0;i<table[s[0]-'0'].size();i++)
	{
		for(auto j:smallAns)
		{
			ans.push_back(table[s[0]-'0'][i]+j);
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	vector<string> v=keypad(s);
	for(auto i:v)
	{
		cout<<i<<endl;
	}
	return 0;
}