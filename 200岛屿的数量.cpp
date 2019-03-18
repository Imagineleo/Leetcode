#include<iostream>
#include<vector>
using namespace std;

class solution{
    public:
    int numIslands(vector<vector<char>>& grid)
    {
        int m =grid.size();
        if(m==0) return 0;
        int n=grid[0].size();
        if(n==0) return 0;
        int sum =0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
            if(grid[i][j]=='1')
            {
                sum ++;
                setOne(grid,i,j);
            }
            }
        }
        return sum;
    }
    void setOne(vector<vector<char>> &grid,int row, int col){
        int m= grid.size();
        int n=grid[0].size();
        if(row<0 || row>=m || col<0 || col >=n || grid[row][col]!='1')
        return ;
        grid[row][col] =2;
        setOne(grid,row+1,col);
        setOne(grid,row-1,col);
        setOne(grid,row,col+1);
        setOne(grid,row,col-1);

    }
};