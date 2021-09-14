#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class ListNode
{
    public:
    int data;
    ListNode* next;
};
class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode *p=head,*q=head;
        while(p!=NULL && p->next!=NULL)
        {
            p=p->next->next;
            q=q->next;
        }
        return q;
    }
};
void create(ListNode *&first, ListNode *&rear, vector<int>arr);
void display(ListNode *&first, ListNode *&rear);
int main(void)
{
    ListNode *first=NULL,*rear=NULL;
    vector<int>arr={1,2,3,4,5};
    vector<int>arr1={1,2,3,4,5,6};
    create(first,rear,arr1);
    display(first,rear);
    Solution ob;
    ListNode *p=ob.middleNode(first);
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void create(ListNode *&first,ListNode*&rear,vector<int>arr)
{
    first=new ListNode();
    first->data=arr[0];
    first->next=NULL;
    rear=first;
    ListNode *temp;
    for(int i=1;i<arr.size();i++)
    {
        temp=new ListNode();
        temp->data=arr[i];
        temp->next=NULL;
        rear->next=temp;
        rear=temp;
    }
}
void display(ListNode *&first,ListNode *&rear)
{
    ListNode *p;
    p=first;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}