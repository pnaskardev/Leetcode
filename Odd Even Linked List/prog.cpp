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
    private:
    int count(ListNode* head)
    {
        int c=0;
        ListNode *p=head;
        while(p!=NULL)
        {
            c++;
            p=p->next;
        }
        return c;
    }
public: 
    ListNode* oddEvenList(ListNode* head) 
    {
        ListNode *ev=NULL;
        if(head==NULL)
        {
            return NULL;
        }
        int c=count(head);
        if(c==1)
        {
            return head;
        }
        else if(c>1)
        {
            ListNode *p=head;
            ev=head->next;
            ListNode *q=ev;
            ListNode *s=head;
            // cout<<c<<endl;
            if(c%2==0)
            {
                while(q->next!=NULL)
                {
                    p->next=q->next;
                    p=p->next;
                    if(p->next!=NULL)
                    {
                        q->next=p->next;
                        q=q->next;
                    }
                    else 
                    {
                        q->next=NULL;
                        break;
                    }
                }
            }
            if(c%2!=0)
            {
                while(q->next!=NULL)
                {
                    p->next=q->next;
                    p=p->next;
                    if(p->next!=NULL)
                    {
                        q->next=p->next;
                        q=q->next;
                    }
                    else 
                    {
                        q->next=NULL;
                        break;
                    }
                }
                cout<<endl;
            }
            p->next=ev;
        }
        return head;
    }
};
void create(ListNode *&first, ListNode *&rear, vector<int>arr);
void display(ListNode *&first, ListNode *&rear);
int main(void)
{
    ListNode *first=NULL,*rear=NULL;
    vector<int>arr={2,1,3,5,6,4,7};
    vector<int>arr1={1,2,3,4,5,6};
    create(first,rear,arr1);
    display(first,rear);
    Solution ob;
    ListNode *res=ob.oddEvenList(first);
    if(res==NULL)
    {
        cout<<"res->NULL"<<endl;
    }
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