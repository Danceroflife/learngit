实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        int i=0,j=0;
        while(haystack[i]!='\0'&&needle[j]!='\0')
        {
            if(haystack[i]==needle[j])
            {
                i++;
                j++;
            }
            else
            {
                i=i-j+1;
                j=0;
                
            }
                
        }
        if(needle[j]=='\0')
            return i-j;
         return -1;
        
    }
};
