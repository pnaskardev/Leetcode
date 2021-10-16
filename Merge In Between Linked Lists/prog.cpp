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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        int c=1;
        ListNode *p=list1,*q=list1,*r=list2;
        while(c!=a)
        {
            c++;
            p=p->next;
        }
        c=1;
        while(c!=b+1)
        {
            c++;
            q=q->next;
        }
        while(r->next!=NULL)
        {
            r=r->next;
        }
        // cout<<p->val<<endl;
        // cout<<q->val<<endl;
        // cout<<r->val<<endl;
        p->next=list2;
        r->next=q->next;
        return list1;
    }
};
void create(ListNode *&first, ListNode *&rear, vector<int>arr);
void display(ListNode *&first, ListNode *&rear);
int main(void)
{
    ListNode *first=NULL,*second=NULL,*rear=NULL,*rear1=NULL;
    vector<int>arr={0,1,2,3,4,5};
    vector<int>arr1={1000000,1000001,1000002};
    vector<int>arr2={0,1,2,3,4,5,6};
    vector<int>arr3={1000000,1000001,1000002,1000003,1000004};
    create(first,rear,arr);
    create(second,rear1,arr1);
    display(first,rear);
    display(second,rear1);
    int a=3,b=4;
    Solution ob;
    ListNode *ans=ob.mergeInBetween(first,a,b,second);
    while(ans!=NULL)
    {
        cout<<ans->val<<" ";
        ans=ans->next;
    }
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