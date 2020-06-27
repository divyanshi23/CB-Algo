/*Given a linked list of length N and an integer K , append the last K elements of a linked list to the front. Note that K can be greater than N.

Input Format
First line contains a single integer N denoting the size of the linked list.
Second line contains N space separated integers denoting the elements of the linked list.
Third line contains a single integer K denoting the number of elements that are to be appended.

Constraints
1 <= N <= 10^4
1 <= K <= 10^4

Output Format
Display all the elements in the modified linked list.

Sample Input
7
1 2 2 1 8 5 6
3
Sample Output
8 5 6 1 2 2 1
Explanation
Initially the linked list is
1→ 2→ 3 → 4 → 5 → 6→ null
and k = 2. After appending the last two elements to the front , the new linked list looks like
5→ 6→ 1→ 2→ 3 → 4 → null*/

#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
};


void insertAtTail(node*& head,int n)
{
    if(head==NULL)
    {
        node* c =new node(n);
        //head->data=n;
        //head->next=NULL;
        head=c;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    node* c= new node(n);
    temp->next=c;
    return;
}


void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}


void kAppend(node*& head,int n,int k)
{
    if(head==NULL || k==n)
    {
        return;
    }
    k=k%n;
    node* fast=head;
    int jump=0;
    while(jump!=k)
    {
        fast=fast->next;
        jump++;
    }
    node* slow=head;
    while(fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    fast->next=head;
    head=slow->next;
    slow->next=NULL;
}

int main() {
    node* head=NULL;
    int n,k;
    cin>>n;
    int d;
    for(int i=0;i<n;i++)
    {
        cin>>d;
        insertAtTail(head,d);
    }
    cin>>k;
    kAppend(head,n,k);
    print(head);
    return 0;
}