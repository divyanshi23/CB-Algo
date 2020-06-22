/*A knight is a piece used in the game of chess. The chessboard itself is square array of cells. Each time a 
night moves, its resulting position is two rows and one column, or two columns and one row away from its 
starting position. Thus a knight starting on row r, column c – which we’ll denote as (r,c) – can move to 
any of the squares (r-2,c-1), (r-2,c+1), (r-1,c-2), (r-1,c+2), (r+1,c-2), (r+1,c+2), (r+2,c-1), or (r+2,c+1). 
Of course, the knight may not move to any square that is not on the board.

Suppose the chessboard is not square, but instead has rows with variable numbers of columns, and with each 
row offset zero or more columns to the right of the row above it. The figure to the left illustrates one 
possible configuration. How many of the squares in such a modified chessboard can a knight, starting in the 
upper left square (marked with an asterisk), not reach in any number of moves without resting in any square 
more than once? Minimize this number.

Imgur

If necessary, the knight is permitted to pass over regions that are outside the borders of the modified 
chessboard, but as usual, it can only move to squares that are within the borders of the board.

Input Format
First line contains an integer n, representing the side of square of chess board. The next n line contains 
n integers separated by single spaces in which jjth integer is 1 if that cell(i,j) is part of chessboard 
and 0 otherwise.

Constraints
The maximum dimensions of the board will be 10 rows and 10 columns. That is, any modified chessboard 
specified by the input will fit completely on a 10 row, 10 column board.

Output Format
Print the minimum number of squares that the knight can not reach.

Sample Input
3
1 1 1
1 1 1
1 1 1
Sample Output
1*/

#include <iostream>
using namespace std;

int dr[]={-2,-2,-1,-1,1,1,2,2};
int dc[]={-1,1,-2,2,-2,2,-1,1};

//2-> represents that we have landed in that cell
int funkyChessBoard(int** board,int r,int c,int n)
{
	//out of the board
	if(r>=n || c>=n || r<0 || c<0)
		return 0;

	//not a part of the valid board or already visited
	if(board[r][c]==0 || board[r][c]==2)
		return 0;

	//(r-2,c-1), (r-2,c+1), (r-1,c-2), (r-1,c+2), (r+1,c-2), (r+1,c+2), (r+2,c-1), or (r+2,c+1)
	int maxVisited=0;
	if(board[r][c]==1)
	{
		board[r][c]=2;
		for(int i=0;i<8;i++)
		{
			int visited=1+funkyChessBoard(board,r+dr[i],c+dc[i],n);
			maxVisited=max(maxVisited,visited);
		}
	}
	//backtracking
	board[r][c]=1;
	return maxVisited;
}


int main()
{
	int n;
	cin>>n;
	int c=0;
	int** board=new int*[n];
	for(int i=0;i<n;i++)
	{
		board[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			cin>>board[i][j];
			if(board[i][j]==1)
				c++;
		}
	} 
	int ans=funkyChessBoard(board,0,0,n);
	//min places not visited=total valid positions-max places visited
	cout<<c-ans;
}