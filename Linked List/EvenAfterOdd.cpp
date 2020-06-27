/*Arrange elements in a Linked List such that all even numbers are placed after odd numbers.

Input Format
Enter N space separated Elements

Constraints
None

Output Format
Linked list with all the odd numbers before even numbers

Sample Input
5
1 2 2 2 1
Sample Output
1 1 2 2 2*/



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


void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}


void evenAfterOdd(node*& head)
{
	if(head==NULL || head->next==NULL)
		return;
    node* evenHead=NULL;
	node* oddHead=NULL;
	node* evenTail=NULL;
	node* oddTail=NULL;
	while(head)
	{
		//data is odd
		if(head->data&1)
		{
			if(oddTail)
			{
				oddTail->next=head;
				oddTail=oddTail->next;
			}
			else
			{
				oddHead=head;
				oddTail=oddHead;
			}
		}
		else
		{
			if(evenTail)
			{
				evenTail->next=head;
				evenTail=evenTail->next;
			}
			else
			{
				evenHead=head;
				evenTail=evenHead;
			}
		}
		head=head->next;
	}
	if(oddHead)
	{
		if(evenTail)
			evenTail->next=NULL;
		oddTail->next=evenHead;
		head= oddHead;
	}
	else
	{
		if(evenTail)
			evenTail->next=NULL;
		head=evenHead;
	}
}


int main() {
    node* head=NULL;
    int n;
    cin>>n;
    int d;
    for(int i=0;i<n;i++)
    {
        cin>>d;
        insertAtTail(head,d);
    }
    evenAfterOdd(head);
    print(head);
    //cout<<"Hello World!";
}
