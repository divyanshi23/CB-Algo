/*Given 2 sorted linked lists , merge the two given sorted linked list and print the final Linked List.

Input Format
First Line contains T the number of test cases.
For each test case :
Line 1 : N1 the size of list 1
Line 2 : N1 elements for list 1
Line 3 : N2 the size of list 2
Line 4 : N2 elements for list 2

Constraints
1 <= T <= 1000
0<= N1, N2 <= 10^6
-10^7 <= Ai <= 10^7

Output Format
For each testcase , print the node data of merged linked list.

Sample Input
1
4
1 3 5 7
3
2 4 6
Sample Output
1 2 3 4 5 6 7 
Explanation
The two lists after merging give the sorted output as [1,2,3,4,5,6,7] */

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

node* merge(node* head1,node* head2)
{
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    node* a=NULL;
    if(head1->data>head2->data)
    {
        a=head2;
        a->next=merge(head1,head2->next);
    }
    else
    {
        a=head1;
        a->next=merge(head1->next,head2);
    }
	//print(a);cout<<endl;
    return a;
}

//iterative merge function
/*node* merge(node* head1,node* head2)
{
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    node* head=NULL;
    if(head1->data<head2->data)
    {
        head=head1;
        head1=head1->next;
    }
    else{
        head=head2;
        head2=head2->next;
    }
    node* a=head;
    while(head1 && head2)
    {
        if(head1->data<head2->data)
        {
            a->next=head1;
            a=a->next;
            head1=head1->next;
        }
        else
        {
            a->next=head2;
            head2=head2->next;
            a=a->next;
        }
    }
    if(head1)
    {
        a->next=head1;
    }
    if(head2)
    {
        a->next=head2;
    }
    //print(a);cout<<endl;
    return head;
}*/

int main() {
    int t;
    cin>>t;
    for(int q=0;q<t;q++)
    {
        node* head1=NULL;node* head2=NULL;
        int n1,n2;
        cin>>n1;
        int d;
        for(int i=0;i<n1;i++)
        {
            cin>>d;
            insertAtTail(head1,d);
        }
		cin>>n2;
        for(int i=0;i<n2;i++)
        {
            cin>>d;
            insertAtTail(head2,d);
        }
        head1=merge(head1,head2);
        print(head1);
    }
    return 0;
}
