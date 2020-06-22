/*You are given an array of numbers and a target number(T) , print all unique combinations in the array 
whose sum equals the target number T. Note that each number in the array may only be used once in the 
combination.
Note:

All numbers (including target) will be positive integers
Elements in the combination must be in non-descending order
There should be no duplicate combinations
Input Format
The first line will contain N indicating the number of elements in the array.
The second line will contain space separated N integers , A[i].
The third line will contain the target number T.

Constraints
N <= 15 1<= A[I] <= 100

Output Format
Print all unique combinations of the numbers satisfying the above constraints in a separate line in 
lexicographic manner.

Sample Input
7
10 1 2 7 6 1 5
8
Sample Output
1 1 6 
1 2 5 
1 7 
2 6 */

#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> v;

//t is target
//s is starting index of remaining array
bool sumItUp(int *arr,int n,int t,int s,int* &visited)
{
    //base case
    if(t==0)
    {
        vector<int> v1;
        for(int i=0;i<n;i++)
        {
            if(visited[i])
                v1.push_back(arr[i]);
        }
        v.push_back(v1);
        //return true;
        return false;
    }
    for(int i=s;i<n;i++)
    {
        
        if(arr[i]<=t)
        {
            
            visited[i]=1;
            
            bool ans=sumItUp(arr,n,t-arr[i],i+1,visited);
            if(ans)
                return true;
            visited[i]=0;  //backtrack
        }
    }
    return false;
}

int main() {
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int t;
    cin>>t;
    sort(arr,arr+n);
    int *visited=new int[n]();
    sumItUp(arr,n,t,0,visited);
    //to get unique sets sort the vector v
    //then use unique to find all unique vectors 
    //then erase the reamining
    sort(v.begin(),v.end());
    v.erase( unique(v.begin(),v.end()) , v.end());
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}