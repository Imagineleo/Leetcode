/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿的个数
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (41.50%)
 * Total Accepted:    9.7K
 * Total Submissions: 23.3K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给定一个由 '1'（陆地）和
 * '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
 * 
 * 示例 1:
 * 
 * 输入:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * 输出: 3
 * 
 * 
 */
class Solution
{
  public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    sum++;
                    setOne(grid, i, j);
                }
            }
        }
        return sum;
    }
    void setOne(vector<vector<char>> &grid, int row, int col)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] != '1')
            return;
        grid[row][col] = 2;
        setOne(grid, row + 1, col);
        setOne(grid, row - 1, col);
        setOne(grid, row, col + 1);
        setOne(grid, row, col - 1);
    }
};
