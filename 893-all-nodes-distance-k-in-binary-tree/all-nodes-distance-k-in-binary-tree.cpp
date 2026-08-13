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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    mp[node->left] = node;
                }
                if(node->right){
                    q.push(node->right);
                    mp[node->right] = node;
                }
            }
        }
        q.push(target);
        int counter = 0;
        unordered_map<TreeNode*, int> vis;
        vis[target]++;
        while(!q.empty()){
            int size = q.size();
            if(counter==k){
                vector<int> ans;
                while(!q.empty()){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(mp.find(node)!=mp.end() && vis.find(mp[node])==vis.end()){
                    q.push(mp[node]);
                    vis[mp[node]]++;
                }
                if(node->left && vis.find(node->left)==vis.end()){
                    q.push(node->left);
                    vis[node->left]++;
                }
                if(node->right && vis.find(node->right)==vis.end()){
                    q.push(node->right);
                    vis[node->right]++;
                }
            }
            counter++;
        }
        return {};
    }
};