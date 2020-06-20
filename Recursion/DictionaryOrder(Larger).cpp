/*Take as input str, a string. Write a recursive function which prints all the words possible by rearranging the characters 
of this string which are in dictionary order larger than the given string.
The output strings must be lexicographically sorted.

Input Format
Single line input containing a string

Constraints
Length of string <= 10

Output Format
Display all the words which are in dictionary order larger than the string entered in a new line each. The output strings
 must be sorted.

Sample Input
cab

Sample Output
cba
Explanation
The possible permutations of string "cab" are "abc" , "acb" ,"bac" , "bca" , "cab" and "cba" . Only one of them is 
lexicographically greater than "cab". We only print "cba".*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void getPermute(string& str,int s,vector<string>& ans)
    {
        if(s==str.size())
        {
            ans.push_back(str);
            return;
        }
        
        for(int i=s;i<str.size();i++)
        {
            swap(str[s],str[i]);
            getPermute(str,s+1,ans);
            swap(str[i],str[s]);
        }
    }


int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	vector<string> ans;
	getPermute(str,0,ans);
	sort(ans.begin(),ans.end());
	for(auto i:ans)
	{
		if(i>str)
			cout<<i<<endl;
	}
	return 0;
}