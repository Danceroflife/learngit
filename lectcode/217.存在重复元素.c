给定一个整数数组，判断是否存在重复元素。
如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

示例 1:
输入: [1,2,3,1]
输出: true

示例 2:
输入: [1,2,3,4]
输出: false

示例 3:
输入: [1,1,1,3,3,4,3,2,4,2]
输出: true

题解一：
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       
        if(nums.size()<=1)
            return false;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-1;i++)
        {
           if(nums[i]==nums[i+1])
               return true;
        }
        return false;
    }
};

题解二：
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> set(nums.begin(),nums.end());
        
        return set.size()!=nums.size();       
    }
};

题解三：
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       
        if(nums.size()<=1)
            return false;
        unordered_set<int> hashset;
        
        for(int i=0;i<nums.size();i++)
        {
           if(hashset.count(nums[i])>0)
               return true;
            else
                hashset.insert(nums[i]);
        }
        return false;
    }
};
