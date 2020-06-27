/*Check if a linked list is a palindrome.( Boolean return type )

Input Format
Add N space separated elements in the list

Constraints
None

Output Format
Boolean answer( true or false)

Sample Input
5
1 2 3 6 8
Sample Output
false
*/

#include <iostream>
#include <stack>
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


bool palindrome(node* head)
{
	if(head==NULL)
	{
		return false;
	}
    node* fast=head;
    node* slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    stack<node*> s;
    node* ptr=head;
    while(ptr!=slow)
    {
        s.push(ptr);
        ptr=ptr->next;
    }
    if(fast!=NULL)
    {
        slow=slow->next;
    }
    while(slow!=NULL)
    {
        node* temp=s.top();
        s.pop();
        if(temp->data!=slow->data)
        {
            return false;
        }
		slow=slow->next;
    }
    return true;
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
    
    bool ans=palindrome(head);
    if(ans)
    cout<<"True";
    else
    cout<<"False";
    return 0;
}