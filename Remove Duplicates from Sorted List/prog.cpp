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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode *p=NULL,*q=NULL;
        p=head;
        if(p)
        {
            q=p->next;
        }
        while(q!=NULL)
        {
            if(q->val!=p->val)
            {
                p=q;
                q=q->next;
            }
            else
            {
                p->next=q->next;
                delete q;
                q=p->next;
            }
        }
        return head;
    }
};
void create(ListNode *&first, ListNode *&rear, vector<int>arr);
void display(ListNode *&first, ListNode *&rear);
int main(void)
{
    ListNode *first=NULL,*rear=NULL;
    vector<int>arr={1,2,3,4,5};
    vector<int>arr1={1,1,2,3,3};
    create(first,rear,arr1);
    display(first,rear);
    Solution ob;
    ListNode *res=ob.deleteDuplicates(first);
    while(res!=NULL)
    {
        cout<<res->val<<" ";
        res=res->next;
    }
    cout<<endl;
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