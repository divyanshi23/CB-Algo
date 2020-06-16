/*We are given a hashmap which maps all the letters with number. Given 1 is mapped with A, 2 is mapped with B…..26 is mapped with Z. Given a number, you have to print all the possible strings.

Input Format
A single line contains a number.

Constraints
Number is less than 10^6

Output Format
Print all the possible strings in sorted order in different lines.

Sample Input
123
Sample Output
ABC
AW
LC
Explanation
'1' '2' '3' = ABC
'1' '23' = AW
'12' '3' = LC

*/


#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char m[]={'.','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

vector<string> mappedString(int n)
{
	if(n==0)
	{
		std::vector<string> v;
		v.push_back("");
		return v;
	}
	int r1=n%10;
	vector<string>smallAns1=mappedString(n/10);
	int n1=smallAns1.size();
	for (int i = 0; i < n1; ++i)
	{
		smallAns1[i]=(smallAns1[i]+m[r1]);
	}
	int r2=n%100;
	if(r2>=10 && r2<=26)
	{
		vector<string>smallAns2=mappedString(n/100);
		int n2=smallAns2.size();
		for (int i = 0; i < n2; ++i)
		{
			smallAns2[i]=(smallAns2[i]+m[r2]);
		}
		for(auto i:smallAns2)
		{
			smallAns1.push_back(i);
		}
	}
	return smallAns1;
}


int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	std::vector<string> v=mappedString(n);
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<endl;
	}
	return 0;
}