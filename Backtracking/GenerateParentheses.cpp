/*Given an integer 'n'. Print all the possible pairs of 'n' balanced parentheses.
The output strings should be printed in the sorted order considering '(' has higher value than ')'.

Input Format
Single line containing an integral value 'n'.

Constraints
1<=n<=11

Output Format
Print the balanced parentheses strings with every possible solution on new line.

Sample Input
2
Sample Output
()() 
(()) */

#include<iostream>
#include <string>
using namespace std;

void generateParentheses(int n,int openC,int closeC,string out)
{
	if(openC==n && closeC==n)
	{
		cout<<out<<endl;
		return;
	}
	if(closeC<openC)
	{
		generateParentheses(n,openC,closeC+1,out+")");
	}
	if(openC<n)
	{
		generateParentheses(n,openC+1,closeC,out+"(");
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int openC=0;
	int closeC=0;
	string out="";
	generateParentheses(n,openC,closeC,out);
	return 0;
}