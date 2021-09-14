#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class ListNode
{
    public:
    int val;
    ListNode* next;
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* p, ListNode* q) 
    {
        ListNode *last,*third=NULL;
        if(p==NULL)
        {
            return q;
        }
        if(q==NULL)
        {
            return p;
        }
        if(p->val<q->val)
        {
            third=p;
            last=p;
            p=p->next;
            third->next=NULL;
        }
        else
        {
            third=q;
            last=q;
            q=q->next;
            third->next=NULL;
        }
        while(p && q)
        {
            if(p->val<q->val)
            {
                last->next=p;
                last=p;
                p=p->next;
                last->next=NULL;
            }
            else
            {
                last->next=q;
                last=q;
                q=q->next;
                last->next=NULL;
            }
        }
        if(p!=NULL)
        {
            last->next=p;
        }
        if(q!=NULL)
        {
            last->next=q;
        }
        return third;
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
}
void create(ListNode *&first,ListNode*&rear,vector<int>arr)
{
    first=new ListNode();
    first->val=arr[0];
    first->next=NULL;
    rear=first;
    ListNode *temp;
    for(int i=1;i<arr.size();i++)
    {
        temp=new ListNode();
        temp->val=arr[i];
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
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}