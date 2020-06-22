/*You are given an empty chess board of size N*N. Find the number of ways to place N queens on the board, such that no two queens can kill each other in one move. A queen can move vertically, horizontally and diagonally.

Input Format
A single integer N, denoting the size of chess board.

Constraints
1<=N<=11

Output Format
A single integer denoting the count of solutions.

Sample Input
4
Sample Output
2*/

#include <iostream>
#include<bitset>
using namespace std;

bitset<11> d1,d2,col;

void countNQueen(int r,int n,int &ans)
{
    //Base case
    if(r==n)
    {
        ans++;
        return;
    }
    //Recursive case
    for(int c=0;c<n;c++)  //try to place the queen in a particular column of the selected row
    {
        if(!col[c] && !d1[r-c+n-1] && !d2[r+c])
        {
            col[c]=1;
            d1[r-c+n-1]=1;
            d2[r+c]=1;
            countNQueen(r+1,n,ans);
            col[c]=0;
            d1[r-c+n-1]=0;
            d2[r+c]=0;
        }
    }
}

int main() {
    int n;
    cin>>n;  //chess board size
    int ans=0;
    int r=0;  //starting row
    countNQueen(r,n,ans);
    cout<<ans;
}
