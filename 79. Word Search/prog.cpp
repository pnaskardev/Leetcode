#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
        int n,m;
        string ans;
        bool recurse(int i,int j,int index,vector<vector<char>>& board,string word)
        {
            // cout<<ans<<endl;
            if(index==word.size())
            {
                return true;
            }
            if(i>=n||j>=m||i<0||j<0||board[i][j]!=word[index])
            {
                return false;
            }
           ans.push_back(board[i][j]);
           char temp=board[i][j];
           board[i][j]='$';
            bool validPath= recurse(i+1,j,index+1,board,word)==true||
                recurse(i-1,j,index+1,board,word)==true||
                recurse(i,j+1,index+1,board,word)==true||
                recurse(i,j-1,index+1,board,word)==true;

            ans.pop_back();
            board[i][j]=temp;

            return validPath;
            
        }
    public:
        bool exist(vector<vector<char>>& board, string word) 
        {
            n=board.size();
            m=board[0].size();
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(board[i][j]==word[0])
                    {
                        if(recurse(i,j,0,board,word))
                        {
                            return true;
                        }
                    }
                }
            }
            return false;
        }   
};
int main(void)
{
    vector<vector<char>>arr=
    {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    Solution ob;
    cout<<ob.exist(arr,"ABCCED")<<endl;
}