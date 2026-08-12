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
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==p || root==q) return root;
        TreeNode* left=NULL;
        TreeNode* right=NULL;
        if(root->left){
            left = helper(root->left, p, q);
        }
        if(root->right){
            right = helper(root->right, p, q);
        }
        if(left==NULL) return right;
        if(right==NULL) return left;
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p, q);
    }
};