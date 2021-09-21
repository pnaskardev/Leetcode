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
    ListNode* rev(ListNode *head)
    {
        ListNode *curr=head,*pre=NULL,*next=NULL;
        while(curr)
        {
            next=curr->next;
            curr->next=pre;
            pre=curr;
            curr=next;
        }
        return pre;
    }
public:
    bool isPalindrome(ListNode* head) 
    {
        ListNode *p=head,*q=head;
        while(p&&p->next && p->next->next)
        {
            q=q->next;
            p=p->next->next;
        }
        ListNode *t2=rev(q->next);
        ListNode *t1=head;
        while(t2)
        {
            if(t1->val!=t2->val)
            {
                return false;
            }
            t1=t1->next;
            t2=t2->next;
        }
        return true;
    }
};
void create(ListNode *&first, ListNode *&rear, vector<int>arr);
void display(ListNode *&first, ListNode *&rear);
int main(void)
{
    ListNode *first=NULL,*rear=NULL;
    vector<int>arr={1,2,2,1};
    vector<int>arr1={1,2};
    vector<int>arr2={1};
    create(first,rear,arr2);
    display(first,rear);
    Solution ob;
    cout<<ob.isPalindrome(first)<<endl;
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