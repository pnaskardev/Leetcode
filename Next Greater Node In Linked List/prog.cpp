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
    vector<int> nextLargerNodes(ListNode* head) 
    {
        vector<int>res;
        ListNode*p=head,*q=NULL;
        while(p->next!=NULL)
        {
            q=p->next;
            while(q!=NULL)
            {
                if(p->val<q->val)
                {
                    res.push_back(q->val);
                    break;
                }
                else
                {
                    q=q->next;
                }
            }
            if(q==NULL)
            {
                res.push_back(0);
            }
            p=p->next;
        }
        res.push_back(0);
        return res;
    }
};
void create(ListNode *&first, ListNode *&rear, vector<int>arr);
void display(ListNode *&first, ListNode *&rear);
int main(void)
{
    ListNode *first=NULL,*rear=NULL;
    vector<int>arr={2,1,5};
    vector<int>arr1={2,7,4,3,5};
    create(first,rear,arr);
    display(first,rear);
    Solution ob;
    auto res=ob.nextLargerNodes(first);
    for(auto i:res)
    {
        cout<<i<<" ";
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