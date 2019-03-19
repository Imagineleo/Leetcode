/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 *
 * https://leetcode-cn.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (41.80%)
 * Total Accepted:    2.9K
 * Total Submissions: 6.9K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或
 * -中选择一个符号添加在前面。
 * 
 * 返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums: [1, 1, 1, 1, 1], S: 3
 * 输出: 5
 * 解释: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * 一共有5种方法让最终目标和为3。
 * 
 * 
 * 注意:
 * 
 * 
 * 数组的长度不会超过20，并且数组中的值全为正数。
 * 初始的数组的和不会超过1000。
 * 保证返回的最终结果为32位整数。
 * 
 * 
 */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        const int n = nums.size();
        const int sum = std::accumulate(nums.begin(),nums.end(),0);
        if(sum < S)  return 0;
        const int offset = sum;
        vector<vector<int>> ways(n+1,vector<int>(sum + offset +1,0));
        ways[0][offset] = 1;
        for(int i =0;i<n;++i)
        {
            for(int j = nums[i];j<2*sum+1 - nums[i]; ++j)
                if(ways[i][j])
                {
                    ways[i+1][j+nums[i]] += ways[i][j];
                    ways[i+1][j-nums[i]] += ways[i][j];
                }
        }
        return ways.back()[S+offset];
    }
};

