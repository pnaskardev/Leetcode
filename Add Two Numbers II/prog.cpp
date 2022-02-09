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
    private:
    void reverse(ListNode *&list)
    {
        ListNode *curr=list,*prev=NULL,*next=NULL;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        list=prev;
}
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        reverse(l1);
        reverse(l2);
    }
};
void create(ListNode *&first, ListNode *&rear, vector<int>arr);
void display(ListNode *&first, ListNode *&rear);
void reverse(ListNode *&list);
int main(void)
{
    ListNode *first=NULL,*rear=NULL,*second=NULL,*rear2=NULL;
    vector<int>arr={7,2,4,3};
    vector<int>arr1={5,6,4};
    create(first,rear,arr);
    create(second,rear2,arr1);
    display(first,rear);
    display(second,rear2);
    Solution ob;
    auto res=ob.addTwoNumbers(first,second);
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
void reverse(ListNode *&list)
{
    ListNode *curr=list,*prev=NULL,*next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    list=prev;
}