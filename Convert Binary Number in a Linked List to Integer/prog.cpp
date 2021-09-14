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
    int getDecimalValue(ListNode* head) 
    {
        ListNode *p=head;
        int c=0,res=0;
        while(p!=NULL)
        {
            c++;
            p=p->next;
        }
        c--;
        p=head;
        while(p!=NULL)
        {
            int mul=pow(2,c)*p->data;
            res=res+mul;
            c--;
            p=p->next;
        }
        return res;
    }
};
void create(ListNode *&first, ListNode *&rear, vector<int>arr);
void display(ListNode *&first, ListNode *&rear);
int main(void)
{
    ListNode *first=NULL,*rear=NULL;
    vector<int>arr={1,0,0,1,0,0,1,1,1,0,0,0,0,0,0};
    vector<int>arr1={0,0};
    create(first,rear,arr1);
    display(first,rear);
    Solution ob;
    cout<<ob.getDecimalValue(first)<<endl;
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