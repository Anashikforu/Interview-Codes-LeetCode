/*
Author: Md Ashik Khan
Problem: 101. Symmetric Tree
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root )
            return false;
        if(!root->left && !root->right)
            return true;
        if(!root->left || !root->right)
            return false;
        TreeNode* lt = root->left;
        TreeNode* rt = root->right;
        
        return isSameTree(lt,rt);
    }
    
private:
    bool isSameTree(TreeNode* p,TreeNode* q){
        if(!p)
            return !q;
        if(!q)
            return !p;
        if(p->val != q->val)
            return false;
        
        if(!isSameTree(p->left, q->right))
            return false;
        
        if(!isSameTree(p->right, q->left))
            return false;
        
        return true;
    }
};