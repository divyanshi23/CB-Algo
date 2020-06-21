/*Take as input a two-d array. Wave print it column-wise.

Input Format
Two integers M(row) and N(colomn) and further M * N integers(2-d array numbers).

Constraints
Both M and N are between 1 to 10.

Output Format
All M * N integers seperated by commas with 'END' wriiten in the end(as shown in example).

Sample Input
4 4
11 12 13 14
21 22 23 24
31 32 33 34
41 42 43 44
Sample Output
11, 21, 31, 41, 42, 32, 22, 12, 13, 23, 33, 43, 44, 34, 24, 14, END */


#include<iostream>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    int a[10][10];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int c=0;c<m;c++)
    {
        for(int r=0;r<n;r++)
        {
            if(c%2==0)
            	cout<<a[r][c]<<", ";
            else
            	cout<<a[n-r-1][c]<<", ";
        }
    }
    cout<<"END";
	return 0;
}