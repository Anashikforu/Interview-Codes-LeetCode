/*
Author: Md Ashik Khan
Problem: Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        double inf = INFINITY;
        return valid(root,-inf,inf);
    }

private:
    bool valid(TreeNode* node,double left,double right){
        int i =0;
        if(!node)
            return true;
        if(node->val < right && node->val > left)
            i = 1;
        else
            return false;
        return (valid(node->right,node->val,right) && valid(node->left,left,node->val));
    }
};