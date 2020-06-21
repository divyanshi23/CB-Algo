/* You are provided n numbers (both +ve and -ve). Numbers are arranged in a circular form. You need to find the maximum sum of consecutive numbers.

Input Format
First line contains integer t which is number of test case.
For each test case, it contains an integer n which is the size of array and next line contains n space separated integers denoting the elements of the array.

Constraints
1<=t<=100
1<=n<=1000
|Ai| <= 10000

Output Format
Print the maximum circular sum for each testcase in a new line.

Sample Input
1
7
8 -8 9 -9 10 -11 12
Sample Output
22
Explanation
Maximum Circular Sum = 22 (12 + 8 - 8 + 9 - 9 + 10)*/


//time- O(n)
//space- O(n)

#include <iostream>
using namespace std;

int kadane(int *arr,int n)
{
    int cs=0,ms=0;
    for(int i=0;i<n;i++)
    {
        cs+=arr[i];
        if(cs<0)
            cs=0;
        ms=max(cs,ms);
    }
    return ms;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int *arr1=new int[n];
        int *arr2=new int[n];  //to store the negative of all the elements of arr to include circular subarray also 
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr1[i];
            arr2[i]=-arr1[i];
            sum+=arr1[i];
        }
        int ans1=kadane(arr1,n);  //normal kadane 
        int ans2=kadane(arr2,n)+sum;  //modified kadane to include circular subarray as well
        if(ans1>ans2)
            cout<<ans1<<endl;
        else
            cout<<ans2<<endl;
    }
}