class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 1);
        int prev = INT_MAX;
        int cnt = 1;
        map<int, vector<int>> mp;
        for(int i = 0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        for(auto it:mp){
            int num = it.first;
            vector<int> pos = it.second;
            int size = pos.size();
            for(int i=0;i<size;i++){
                ans[pos[i]] = cnt;
            }
            cnt++;
        }
        return ans;
    }
};