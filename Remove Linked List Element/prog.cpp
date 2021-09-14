#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class ListNode
{
    public:
    int val;
    ListNode* next;
};
class Solution 
{
    public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode *p=head,*q=head;
        if(p==NULL || (p->next==NULL && p->val==val))
        {
            return NULL;
        }
        while(p)
        {
            if(head->val==val)
            {
                head=head->next;
            }
            else if(p->val==val)
            {
                q->next=p->next;
                p=p->next;
                continue;
            }
            q=p;
            p=p->next;
        }
        return head;
    }
};
void create(ListNode *&first, ListNode *&rear, vector<int>arr);
void display(ListNode *&first, ListNode *&rear);
int main(void)
{
    ListNode *first=NULL,*rear=NULL;
    vector<int>arr1={1,2,6,3,4,5,6};
    vector<int>arr2={1,2};
    vector<int>arr3={7,7,7,7};
    create(first,rear,arr3);
    display(first,rear);
    Solution ob;
    ListNode *res=ob.removeElements(first,7);
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