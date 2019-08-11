给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
            return true;
        
        return isSymmetric(root->left,root->right);
    }
    
    bool isSymmetric(TreeNode* root1,TreeNode* root2)
    {
        if(root1==nullptr&&root2==nullptr)
        {
            return true;
        }
         if(root1==nullptr||root2==nullptr)
        {
            return false;
        }
        if(root1->val!=root2->val)
            return false;
        return isSymmetric(root1->left,root2->right)&&isSymmetric(root1->right,root2->left);
    }
};
