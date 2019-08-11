给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:
输入: 1->1->2
输出: 1->2

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* p=head;
        while(p!=NULL&&p->next!=NULL)
        {
            if(p->val==p->next->val)
            {
                p->next=p->next->next;
               
            }
            else
            {
                 p=p->next;
            }
           
        }
        return head;
        
    }
};
