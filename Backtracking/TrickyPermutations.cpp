/*Given a string containing duplicates, print all its distinct permutations such that there are no 
duplicate permutations and all permutations are printed in a lexicographic order.

Input Format
The first and only line of the test case contains the input string.

Constraints
Length of the string <= 8

Output Format
Print all the distinct permutations in a lexicographic order such that each permutation is in a new line. 
Note that there should not be any duplicate permutations.

Sample Input
ABA
Sample Output
AAB
ABA
BAA
Explanation
The possible permutations for the given string are { "AAB" , "AAB" , "ABA" , "BAA" } . We skip the repeating 
AAB" permutation and only print it in once. Also we print the final output in lexicographical order.*/

#include <iostream>
#include <set>
#include <string>
using namespace std;

void permute(string s,int i,int n,set<string>& permutations)
{
	if(i==n)
	{
		permutations.insert(s);
		return;
	}
	for(int j=i;j<n;j++)
	{
		swap(s[i],s[j]);
		permute(s,i+1,n,permutations);
		swap(s[i],s[j]);
	}
}

int main()
{
	string str;
	cin>>str;
	set<string> permutations;
	permute(str,0,str.size(),permutations);
	//need not to sort as set already stores uniques items and in sorted fashion
	//sort(permutations.begin(),permutations.end());
	for(auto i:permutations)
	{
		cout<<i<<endl;
	}
	return 0;
} 