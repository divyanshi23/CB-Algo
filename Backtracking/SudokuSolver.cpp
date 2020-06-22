/*You are given an N*N sudoku grid (N is a multiple of 3). Solve the sudoku and print the solution.
To learn more about sudoku, go to this link Sudoku-Wikipedia.

Input Format
First line contains a single integer N. Next N lines contains N integers each, where jth integer int ith line denotes the value at ith row and jth column in sudoku grid. This value is 0, if the cell is empty.

Constraints
N=9 Solution exists for input matrix.

Output Format
Print N lines containing N integers each, where jth integer int ith line denotes the value at ith row and jth column in sudoku grid, such that all cells are filled.

Sample Input
9
5 3 0 0 7 0 0 0 0 
6 0 0 1 9 5 0 0 0 
0 9 8 0 0 0 0 6 0 
8 0 0 0 6 0 0 0 3 
4 0 0 8 0 3 0 0 1 
7 0 0 0 2 0 0 0 6 
0 6 0 0 0 0 2 8 0 
0 0 0 4 1 9 0 0 5 
0 0 0 0 8 0 0 7 9 
Sample Output
5 3 4 6 7 8 9 1 2 
6 7 2 1 9 5 3 4 8 
1 9 8 3 4 2 5 6 7 
8 5 9 7 6 1 4 2 3 
4 2 6 8 5 3 7 9 1 
7 1 3 9 2 4 8 5 6 
9 6 1 5 3 7 2 8 4 
2 8 7 4 1 9 6 3 5 
3 4 5 2 8 6 1 7 9 
*/

#include <iostream>
#include<math.h>
using namespace std;

bool canWePlace(int** sudoku,int n,int i,int j,int t)
{
    //row check
    for(int x=0;x<n;x++)
    {
        if(sudoku[i][x]==t)
            return false;
    }
    //column check
    for(int x=0;x<n;x++)
    {
        if(sudoku[x][j]==t)
            return false;
    }
    //grid check
    int rn=sqrt(n);
    int sx=(i/rn)*rn;
    int sy=(j/rn)*rn;
    for(int x=sx;x<sx+rn;x++)
    {
        for(int y=sy;y<sy+rn;y++)
        {
            if(sudoku[x][y]==t)
                return false;
        }
    }
    return true;
}

bool sudokuSolver(int** sudoku,int n,int i,int j)
{
    //Base Case
    if(i==n)
    {
        //print sudoku
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<sudoku[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    //row end reached
    if(j==n) 
        return sudokuSolver(sudoku,n,i+1,0);

    //skip pre-filled cells
    if(sudoku[i][j]!=0)
        return sudokuSolver(sudoku,n,i,j+1);

    //Recursive case
    //try to fill cell with all possible values
    for(int t=1;t<=n;t++)
    {
        if(canWePlace(sudoku,n,i,j,t))
        {
            //assume we can place t at sudoku[i][j]
            sudoku[i][j]=t;
            //try to solve remaining sudoku
            bool couldWeSolve=sudokuSolver(sudoku,n,i,j+1);
            if(couldWeSolve)
                return true;
        }
    }

    //backtrack here, if after trying all possible values 
    sudoku[i][j]=0;
    return false;
}

int main() {
    int n;
    cin>>n;
    int **sudoku=new int*[n];
    for(int i=0;i<n;i++)
    {
        sudoku[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>sudoku[i][j];
        }
    }
    bool ans=sudokuSolver(sudoku,n,0,0);
    delete [] sudoku;
    sudoku=0;
}