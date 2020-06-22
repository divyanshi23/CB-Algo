/*You are given an N*M grid. Each cell (i,j) in the grid is either blocked, or empty. The rat 
can move from a position towards left, right, up or down on the grid.
Initially rat is on the position (1,1). It wants to reach position (N,M) where it's cheese is 
waiting for. There exits a unique path in the grid . Find that path and help the rat reach its 
cheese.

Input Format
First line contains 2 integers N and M denoting the rows and columns in the grid.
Next N line contains M characters each. An 'X' in position (i,j) denotes that the cell is blocked 
and ans 'O' denotes that the cell is empty.

Constraints
1 <= N , M <= 10

Output Format
Print N lines, containing M integers each. A 1 at a position (i,j) denotes that the (i,j)th cell 
is covered in the path and a 0 denotes that the cell is not covered in the path.
If a path does not exits then print "NO PATH FOUND"

Sample Input
5 4
OXOO
OOOX
XOXO
XOOX
XXOO
Sample Output
1 0 0 0 
1 1 0 0 
0 1 0 0 
0 1 1 0 
0 0 1 1 
*/

#include <iostream>
using namespace std;


bool solveMaze(char** grid, int n,int m,int i,int j)
{
	//reached the final destination
	if(i==n-1 && j==m-1)
	{
		if(grid[i][j]=='O')
		{
			grid[i][j]='1';
			return true;
		}
		else
		{
			return false;
		}
	}

	//out of the bounds of the board
	if(i<0 || j<0 || i>=n || j>=m)
		return false;

	//solve recursively
	if(grid[i][j]=='O')
	{
		grid[i][j]='1';
		bool aageSolveHuaRight=solveMaze(grid,n,m,i,j+1);
		if(aageSolveHuaRight)
		{
			return true;
		}
		bool aageSolveHuaDown=solveMaze(grid,n,m,i+1,j);
		if(aageSolveHuaDown)
		{
			return true;
		}
		bool aageSolveHuaLeft=solveMaze(grid,n,m,i,j-1);
		if(aageSolveHuaLeft)
		{
			return true;
		}
		bool aageSolveHuaUp=solveMaze(grid,n,m,i-1,j);
		if(aageSolveHuaUp)
		{
			return true;
		}
		grid[i][j]='O';
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	char** grid=new char*[n];
	for(int i=0;i<n;i++)
	{
		grid[i]=new char[m];
		for(int j=0;j<m;j++)
		{
			cin>>grid[i][j];
		}
	}
	bool ans=solveMaze(grid,n,m,0,0);
	if(ans)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(grid[i][j]=='1')
					cout<<"1 ";
				else
					cout<<"0 ";
			}
			cout<<endl;
		}
	}
	else
		cout<<"NO PATH FOUND";
	return 0;
}