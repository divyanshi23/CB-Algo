/*We are given a linked list which contains a cycle. Detect that cycle and break it. Print the linked list after removing the cycle.

Input Format
The first line contains space separated integers. The integers are such that all the values are distinct but the value start repeating once the cycle gets completed. The list of integers given ends when -1 is input.

Constraints
n < 10^5 where n is the length of list without the cycle

Output Format
Output single line containing space separated integers representing the list

Sample Input
1 2 3 4 5 2 3 -1
Sample Output
1 2 3 4 5
Explanation
Initially the first five elements are unique but starts repeating from 2. This means there is a link from 5 back to 2. So it represents a cycle. We have to break this cycle and print the list after breaking the cycle.*/

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

node* detectLoop(node*& head)
{
    if(head==NULL)
        return head;
    node* s=head;
    node* f=head;
    s=s->next;
    f=f->next->next;
    while(s!=NULL && f!=NULL && f->next!=NULL && s!=f)
    {
        s=s->next;
        f=f->next->next;
    }
    if(s==f)
    {
        return s;
    }
    else
    {
        return NULL;
    }
}


void removeLoop(node*& head)
{
    if(head==NULL)
    {
        return;
    }
    node* detect=detectLoop(head);
    if(detect==NULL)
    {
        return;
    }
    node* f=detect;
    node* s=head;
    while(s!=f)
    {
        s=s->next;
        f=f->next;
    }
    node* ptr=f->next;
    while(ptr->next!=f)
    {
        ptr=ptr->next;
    }
    ptr->next=NULL;
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
    node* temp=head;
    node* temp2=NULL;
    while(d!=-1)
    {
        insertAtTail(head,d);
        cin>>d;
        temp=head;
        temp2=NULL;
        while(temp->next!=NULL)
        {
            if(temp->data==d)
            {
                temp2=temp;
            }
            temp=temp->next;
        }
        if(temp2)
        {
            temp->next=temp2;
            d=-1;
        }
    }
}


int main() {
    node* head=NULL;
    buildLinkedList(head);
    removeLoop(head);
    print(head);
    return 0;
}