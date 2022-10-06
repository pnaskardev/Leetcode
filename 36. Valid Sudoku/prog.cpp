#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    private:
        bool isValid(vector<int>values)
        {
            vector<int>c(10,0);
            for(int i=0;i<values.size();i++)
            {
                c[values[i]]++;
            }
            for(auto i:c)
            {
                if(i>1)
                {
                    return false;
                }
            }
            return true;
        }

        bool columns(vector<vector<char>> &board)
        {
            vector<int>values;
            for(int col=0;col<9;col++)
            {
                for(int row=0;row<9;row++)
                {
                    if(board[row][col]!='.')
                    {
                        values.push_back(board[row][col]-'0');
                    }
                }
                if(isValid(values)==false)
                {
                    return false;
                }
            }
            
            return true;
        }
        bool rows(vector<vector<char>> &board)
        {
            vector<int>values;
            for(int row=0;row<9;row++)
            {
                for(int col=0;col<9;col++)
                {
                    if(board[col][row]!='.')
                    {
                        values.push_back(board[row][col]-'0');
                    }
                }
                if(isValid(values)==false)
                {
                    return false;
                }
            }
           
            return true;
        }

        bool box(vector<vector<char>>&board)
        {
            for(int row=0;row<8;row+=3)
            {
                for(int col=0;col<8;col+=3)
                {
                    vector<int>values;
                    for(int i=row;i<row+3;i++)
                    {
                        for(int j=col;j<col+3;col++)
                        {
                            if(board[i][j]!='.')
                            {
                                values.push_back(board[i][j]-'0');
                            }
                        }
                    }
                    if(isValid(values)==false)
                    {
                        return false;
                    }
                    
                }
                
            }
            return true;
        }

    public:
        bool isValidSudoku(vector<vector<char>>& board) 
        {
            if(rows(board)==true and columns(board)==true and box(board)==true)
            {
                return true;
            }
            return false;
        }
};

int main(void)
{
    vector<vector<char>>arr=
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},

    };
    Solution ob;
    cout<<ob.isValidSudoku(arr)<<endl;
}