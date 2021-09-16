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
    ListNode* getIntersectionNode(ListNode *p, ListNode *q) 
    {
        if(p==NULL || q==NULL)
        {
            return NULL;
        }
        ListNode *res,*h=p;
        unordered_set<ListNode*>st;
        while(h!=NULL)
        {
            st.insert(h);
            h=h->next;
        }
        h=q;
        while(h!=NULL)
        {
            if(st.find(h)!=st.end())
            {
                return h;
            }
            h=h->next;
        }
        return NULL;
    }
};
void create(ListNode *&first, ListNode *&rear, vector<int>arr);
void display(ListNode *&first, ListNode *&rear);
int main(void)
{
    ListNode *first=NULL,*rear1=NULL,*second=NULL,*rear2=NULL;
    vector<int>arr={4,1,8,4,5};
    vector<int>arr1={5,6,1,8,4,5};
    create(first,rear1,arr);
    create(second,rear2,arr1);
    display(first,rear1);
    display(second,rear2);
    Solution ob;
    ListNode *res=ob.getIntersectionNode(first,second);
    cout<<res->val<<endl;
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