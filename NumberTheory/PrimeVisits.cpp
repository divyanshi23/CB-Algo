/*PMO gives two random numbers a & b to the Prime Minister. PM Modi wants to visit all countries between a and b (inclusive) , However due to shortage of time he can't visit each and every country , So PM Modi decides to visit only those countries,for which country number has two divisors. So your task is to find number of countries Mr. Modi will visit.



Input Format
The first line contains N , no of test cases. The next N lines contain two integers a and b denoting the range of country numbers.

Constraints
a<=1000000 & b<=1000000.
N<=1000

Output Format
Output contains N lines each containing an answer for the test case.

Sample Input
2
1 10
11 20
Sample Output
4
4
Explanation
PM Modi chooses countries with numbers 2,3,5 and 7 for the first testcase.
For the second testcase , he chooses countries with numbers 11,13,17 and 19.*/



#include<iostream>
#include<vector>
using namespace std;
#define s 1000000


vector<int> primeSeive()
{
	//int* seive=new int[s]();
	vector<int> seive;
	seive.resize(s);
	seive[2]=1;
	for(int i=3;i<s;i+=2)
	{
		seive[i]=1;
	}
	for(int i=3;i*i<s;i+=2)
	{
		if(seive[i])
		{
			for(int j=i*i;j<s;j+=i)
			{
				seive[j]=0;
			}
		}
	}
	//vector<int> primes;
	//primes.push_back(2);
	for(int i=1;i<s;i++)
	{
		seive[i]+=seive[i-1];
	}
	return seive;
}

int main() {
	int t;
	cin>>t;
	vector<int> p=primeSeive();
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		cout<<p[b]-p[a-1]<<endl;
	}
	return 0;
}