/*Piyush and Nimit are playing a coin game. They are given n coins with values x1, x2 …. xn where 'n' is always even.
They take alternate terms. In each turn, a player picks either the first coin or the last coin from the row and removes 
it from the row. The value of coin is received by that player. Determine the maximum value that Piyush can win with if 
he moves first. Both the players play optimally.

Input Format
First line contains the number of coins 'n'.
Second line contains n space separated integers where ith index denotes the value of ith coin.

Constraints
1 < N <= 30 , N is always even
0 <= Ai <= 1000000

Output Format
Print a single line with the maximum possible value that Piyush can win with.

Sample Input
4
1 2 3 4
Sample Output
6
Explanation
Piyush will pick the coin 4. Then Nimit can pick either 1 or 3. In both the cases piyush picks coin 2 and wins with a total 
of 6.*/

#include <iostream>
using namespace std;

//0-> represents turn is of Piyush
//1-> represents turn is of Nimit

pair<int,int> optimalGame(int* arr,int s,int e,int turn)
{
	//base case
	if(s==e)
	{
		pair<int,int> p;
		p.first=0;
		p.second=arr[s];
		return p;
	}

	if(turn==0)
	{
		pair<int,int> op1=optimalGame(arr,s+1,e,turn+1);
		pair<int,int> op2=optimalGame(arr,s,e-1,turn+1);
		if(op1.first+arr[s]>op2.first+arr[e])
		{
			op1.first+=arr[s];
			return op1;
		}
		else{
			op2.first+=arr[e];
			return op2;
		}
	}
	else
	{
		pair<int,int> op1=optimalGame(arr,s+1,e,turn-1);
		pair<int,int> op2=optimalGame(arr,s,e-1,turn-1);
		if(op1.second+arr[s]>op2.second+arr[e])
		{
			op1.second+=arr[s];
			return op1;
		}
		else
		{
			op2.second+=arr[e];
			return op2;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	int* arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int turn =0;
	pair<int,int> ans=optimalGame(arr,0,n-1,turn);
	cout<<ans.first;
	return 0;
}