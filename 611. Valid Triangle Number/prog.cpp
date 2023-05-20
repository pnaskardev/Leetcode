#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = n - 1; i >= 2; i--)
        {
            int low = 0;
            int high = i - 1;
            while (low < high)
            {
                if ((nums[low] + nums[high]) > nums[i])
                {
                    ans += (high - low);
                    // cout << nums[i] << " " << nums[low] << " " << nums[high] << endl;
                    // low++;
                    high--;
                }
                else
                {
                    low++;
                    // high++;
                }
            }
        }
        return ans;
    }
};

int main(void)
{
    vector<int> num = {2, 2, 3, 4};
    // vector<int> num = {2, 3, 4, 4};
    Solution ob;
    cout << ob.triangleNumber(num) << endl;
}

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class ListNode
{
    public:
    int val;
    ListNode* next;
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