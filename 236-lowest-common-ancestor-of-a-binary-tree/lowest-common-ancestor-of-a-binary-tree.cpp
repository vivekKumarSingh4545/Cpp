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
        if(root->val == p->val || root->val == q->val) return root;
        TreeNode* l=NULL;
        TreeNode* r=NULL;
        if(root->left){
            l = helper(root->left, p, q);
        }
        if(root->right){
            r = helper(root->right, p, q);
        }
        if(l&&r) return root;
        else if(l) return l;
        else return r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p, q);
    }
};