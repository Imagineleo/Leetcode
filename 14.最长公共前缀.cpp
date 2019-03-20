/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (32.36%)
 * Total Accepted:    60.4K
 * Total Submissions: 186.7K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      if(strs.empty()) return "";
      for(int inx ;inx<strs[0].size();++inx)
      {
          for(int i =1 ;i<strs.size();++i)
          {
              if(strs[i][inx] != strs[0][inx])
              return strs[0].substr(0,inx);
          }
      } 
      return strs[0]; 
        
    }

};

