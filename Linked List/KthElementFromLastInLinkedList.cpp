/*Given a linked list with n nodes. Find the kth element from last without computing the length of the linked list.

Input Format
First line contains space separated integers representing the node values of the linked list. The list ends when the input comes as '-1'. The next line contains a single integer k.

Constraints
n < 10^5

Output Format
Output a single line containing the node value at the kth element from last.

Sample Input
1 2 3 4 5 6 -1
3
Sample Output
4
Explanation
The linked list is 1 2 3 4 5 6. -1 is not included in the list. So the third element from the last is 4

*/
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


int kElement(node* head,int k)
{
    if(head==NULL)
    {
        return -1;
    }
    int jump=1;
    node* fast=head;
    while(jump!=k)
    {
        fast=fast->next;
        jump++;
    }
    node* slow=head;
    while(fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }
    return slow->data;

}

void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}


int main() {
    node* head=NULL;
    int k;
    buildLinkedList(head);
    cin>>k;
    int ele=kElement(head,k);
    //print(head);
    cout<<ele;
    return 0;
}
