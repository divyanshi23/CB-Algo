/*Take as input str, a string. str represents keys pressed on a nokia phone keypad. We are concerned with all possible words that can be written with the pressed keys.

Assume the following alphabets on the keys: 1 -> abc , 2 -> def , 3 -> ghi , 4 -> jkl , 5 -> mno , 6 -> pqrs , 7 -> tuv , 8 -> wx , 9 -> yz

E.g. “12” can produce following words “ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf”

a. Write a recursive function which returns the count of words for a given keypad string. Print the value returned.

b.Write a recursive function which prints all possible words for a given keypad string (void is the return type for function).

Input Format
Single line input containing a single integer.

Constraints
1 <= Length of string <= 10^3

Output Format
Print all the words in a space separated manner. Also print the count of these numbers in next line.

Sample Input
12
Sample Output
ad ae af bd be bf cd ce cf
9
Explanation
1 can correspond to 'a' , 'b' or 'c' .
2 can correspond to 'd', 'e' or 'f'.
We print all combinations of these*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> output;

string table[] = { "", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wx","yz" };

int wordCount(string str,int n)
{
    if(n==0)
    {
        return 1;
    }
    int smallCount=wordCount(str,n-1);
    int r=str[n-1]-'0';
    return smallCount*table[r].size();
}

void printWords(string str,int n)
{
    if(n==0)
    {
        output.push_back("");
        return;
    }
    printWords(str,n-1);
    int smallSize=output.size();
    int r=str[n-1]-'0';
    for(int i=0;i<smallSize;i++)
    {
        string temp=output[0];
        output.erase(output.begin());
        for(int j=0;j<table[r].size();j++)
        {
            output.push_back(temp+table[r][j]);
        }
    }
}

int main() {
    string str;
    cin>>str;
    printWords(str,str.size());
    for(int i=0;i<output.size();i++)
    {
        cout<<output[i]<<" ";
    }
    int wc=wordCount(str,str.size());
    cout<<endl<<wc;
    return 0;
    //cout<<"Hello World!";
}