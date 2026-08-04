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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long width = 1;
        while(!q.empty()){
            int n = q.size();
            long long mini = INT_MAX;
            long long maxi = INT_MIN;
            long long normalize = q.front().second;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front().first;
                long long pos = q.front().second-normalize;
                q.pop();
                mini = min(mini, pos);
                maxi = max(maxi, pos);
                if(node->left){
                    q.push({node->left, 2*pos+1});
                }
                if(node->right){
                    q.push({node->right, 2*pos+2});
                }
            }
            width = max(width, maxi-mini+1);
        }
        return width;
    }
};