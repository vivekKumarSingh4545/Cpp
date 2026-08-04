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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        mp[0][0].insert(root->val);
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int y = q.front().second.first;
            int x = q.front().second.second;
            q.pop();
            if(node->left){
                q.push({node->left, {y-1, x+1}});
                mp[y-1][x+1].insert(node->left->val);
            }
            if(node->right){
                q.push({node->right, {y+1, x+1}});
                mp[y+1][x+1].insert(node->right->val);
            }
        }
        vector<vector<int>> ans;
        for(auto it:mp){
            vector<int> res;
            for(auto itr:it.second){
                vector<int> temp;
                for(auto i:itr.second){
                    temp.push_back(i);
                }
                sort(temp.begin(), temp.end());
                for(auto el:temp){
                    res.push_back(el);
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};