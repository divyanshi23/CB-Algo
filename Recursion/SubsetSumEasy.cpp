/*Mike is a very passionate about sets. Lately, he is busy solving one of the problems on sets. He has to find whether 
if the sum of any of the non-empty subsets of the set A is zero.

Input Format
The first line contains an integer T, which is the total number of test cases.
T test cases follow.
Each test case consists of two lines.
The first line consists of a single integer N, which is the number of elements present in the set A.
The second line contains N space separated integers denoting the elements of the set A.

Constraints
1 ≤ T ≤10
1 ≤ N ≤ 4
-10^5 ≤ A[i] ≤ 10^5

Output Format
Print the answer for each testcase in a new line.
If the sum of any of the subset is zero, then print “Yes” (without quotes) else print “No”(without quotes).

Sample Input
1
4
1 3 2 -3
Sample Output
Yes
Explanation
The sum of the subset {3,-3} is zero.*/

#include <iostream>
using namespace std;
#define ll long long

bool subsetSumZero(ll *arr,ll n,ll sum,ll k)
{
    if(n==0)
    {
        if(sum==0 && k!=0)
            return true;
        return false;
    }
    bool a=subsetSumZero(arr,n-1,sum,k);
    k++; //last element of arr passed to func is included
    bool b=subsetSumZero(arr,n-1,sum+arr[n-1],k);
    return a || b;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll *arr=new ll [n];
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        ll sum=0,k=0;
        bool ans=subsetSumZero(arr,n,sum,k);
        if(ans)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}


