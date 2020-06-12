/*Prateek recently graduated from college. To celebrate, he went to a candy shop and bought all the candies. The total cost was a number upto which there are n prime numbers (starting from 2). Since Prateek wants to minimize his cost, he calls you to help him find the minimum amount that needs to be paid. Being a student of Prateek bhaiya it is now your job to help him out :)

Input Format
First line contains a single integer denoting the number of test cases T. Next T lines contains a single integer N, denoting the number of primes required.

Constraints
T <= 10000

It is guaranteed that the answer does not exceed 10^6.

Output Format
Print the minimum cost that needs to be paid.

Sample Input
2
5
1
Sample Output
11
2
Explanation
In the first case there are 5 primes upto 11(2,3,5,7,11).*/


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
	vector<int> primes;
	primes.push_back(2);
	for(int i=3;i<s;i+=2)
	{
		if(seive[i])
		{
			primes.push_back(i);
		}
	}
	return primes;
}

int main() {
	int t;
	cin>>t;
	vector<int> p=primeSeive();
	while(t--)
	{
		int n;
		cin>>n;
		cout<<p[n-1]<<endl;
	}
	return 0;
}