给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1:
输入: s = "anagram", t = "nagaram"
输出: true

class Solution {
public: 
    static bool cmp(const char&a,const char&b)
        {
            return a<b;
        }

    
    bool isAnagram(string s, string t) {
       if(s.size()!=t.size()) 
           return false;
        
        sort(s.begin(),s.end(),cmp);
        sort(t.begin(),t.end(),cmp);
        
        for(int i=0,j=0;i<s.length()&&j<t.length();i++,j++)
        {
            if(s[i]!=t[j])
                return false;
        }
        return true;
            
    }
};
