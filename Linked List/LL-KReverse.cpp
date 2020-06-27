/*Given a head to Linked List L, write a function to reverse the list taking k elements at a time. Assume k is a factor of the size of List.

You need not have to create a new list. Just reverse the old one using head.

Input Format
The first line contains 2 space separated integers N and K

The next line contains N space separated integral elements of the list.

Constraints
0 <= N <= 10^6 0 <= K <= 10^6

Output Format
Display the linkedlist after reversing every k elements

Sample Input
9 3
9 4 1 7 8 3 2 6 5
Sample Output
1 4 9 3 8 7 5 6 2
Explanation
N = 9 & K = 3

Original LL is : 9 -> 4 -> 1 -> 7 -> 8 -> 3 -> 2 -> 6 -> 5

After k Reverse : 1 -> 4 -> 9 -> 3 -> 8 -> 7 -> 5 -> 6 -> 2

*/

#include <iostream>
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

void insertAtHead(node*& head,int n)
{
    node* temp=new node(n);
    temp->next=head;
    head=temp;
    return;
}

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

int len(node* head)
{
    int length=0;
    while(head!=NULL)
    {
        head=head->next;
        length++;
    }
    return length;
}

void insertInMiddle(node*& head,int n,int p)
{
    if(p==0 || head==NULL)
    {
        insertAtHead(head,n);
        return;
    }
    if(p>len(head))
    {
        insertAtTail(head,n);
        return;
    }
    int jump=1;
    node* temp=head;
    while(jump!=p)
    {
        temp=temp->next;
        jump++;
    }
    node* newNode=new node(n);
    newNode->next=temp->next;
    temp->next=newNode;
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

void buildLinkedList(node*& head)
{
    int d;
    cin>>d;
    while(d!=-1)
    {
        insertAtTail(head,d);
        cin>>d;
    }
}

void reverse(node*& head)
{
    node* n=NULL;
    node* p=NULL;
    node* c=head;
    while(c!=NULL)
    {
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    head=p;
}

node* kReverse(node* head,int k)
{
    if(head==NULL)
    {
        return head;
    }
    node* temp=head;
    int jump=1;
    while(jump!=k)
    {
        temp=temp->next;
        jump++;
    }
    node* nextNode=temp->next;
    temp->next=NULL;
    node* n=NULL;
    node* c=head;
    node* p=kReverse(nextNode,k);
    while(c!=NULL)
    {
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    head=p;
    return head;
}

int main() {
    node* head=NULL;
    int n,k;
    cin>>n>>k;
    int d;
    for(int i=0;i<n;i++)
    {
        cin>>d;
        insertAtTail(head,d);
    }
    head=kReverse(head,k);
    print(head);
    return 0;
}