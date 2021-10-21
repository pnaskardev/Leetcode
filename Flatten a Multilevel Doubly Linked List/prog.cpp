#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node 
{
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
class Solution {
    private:
    void att (Node *&p,Node *&q)
    {
        if(p==NULL)
        {
            return;
        }
        Node *nex=p->next;
        Node *child=p->child;
        if(q==NULL)
        {
            q=p;
        }
        else
        {
            q->next=p;
            p->prev=q;
            q->child=NULL;
            q=q->next;
        }
        att(child,q);
        att(nex,q);
        
    }
public:
    Node* flatten(Node* head) 
    {
        Node *p=head;
        Node *q=NULL;
        att(p,q);
        return head;
    }
};
void create(Node *&first,Node*&rear,vector<int>arr);
void display(Node *&first,Node *&rear);
int main(void)
{
    Node *head=NULL,*rear=NULL;
    vector<int>arr={1,2,3,4,5,6,NULL,NULL,NULL,7,8,9,10,NULL,NULL,11,12};
    for(auto i:arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

void create(Node *&first,Node*&rear,vector<int>arr)
{
    first=new Node();
    first->val=arr[0];
    first->next=NULL;
    rear=first;
    Node *temp;
    for(int i=1;i<arr.size();i++)
    {
        temp=new Node();
        temp->val=arr[i];
        temp->next=NULL;
        rear->next=temp;
        rear=temp;
    }
}
void display(Node *&first,Node *&rear)
{
    Node *p;
    p=first;
    while(p!=NULL)
    {
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}