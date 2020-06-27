/*Given two intersecting linked lists, write a function to find its point of intersection. If the lists do not intersect , return NULL.

Note : You are required to only write a single function. Do not modify / alter the remaining code.

Input Format
You are given a function which accepts head pointers of two linked lists.

Constraints
Your function should run in linear time.

Output Format
Return the intersection point node.

Sample Input
Consider these linked lists :
1 -> 2 -> 3  -> null
   ↗
4
Sample Output
The two linked lists 1->2->3->null and 4->2->3-> null intersect at node with data 2.
Return the node with data = 2.
Explanation
The two linked lists intersect at 2. Return their intersection point.*/



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


void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

node* intersection2(node* head1,node* head2)
{
    int len1=len(head1);
    int len2=len(head2);
    int d=max(len1,len2)-min(len1,len2);
    node* temp1=head1;
    node* temp2=head2;
    if(len1>len2)
    {
        for(int i=0;i<d;i++)
        {
            temp1=temp1->next;
        }
    }
    else
    {
        for(int i=0;i<d;i++)
        {
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL)
    {
        if(temp1->data==temp2->data)
        {
            return temp1;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return NULL;
}

node* intersection(node* head1,node* head2)
{
    node* temp1=head1;
    node* ans=NULL;
    while(temp1!=NULL)
    {
        node* temp2=head2;
        while(temp2!=NULL)
        {
            if(temp1->data==temp2->data)
            {
               return temp1;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return ans;
}

int main() {
    node* head1=NULL;
    int n1,n2;
    cin>>n1;
    int d;
    for(int i=0;i<n1;i++)
    {
        cin>>d;
        insertAtTail(head1,d);
    }
    node* head2=NULL;
    cin>>n2;
    for(int i=0;i<n2;i++)
    {
        cin>>d;
        insertAtTail(head2,d);
    }
    node* ans=intersection2(head1,head2);
    if(ans)
    cout<<ans->data;
    else
    cout<<"-1";
    return 0;
}