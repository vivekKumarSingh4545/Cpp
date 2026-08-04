class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
            mp[nums[i]]++;
        }
        vector<int> ans;
        for(int i=mini;i<maxi;i++){
            if(mp.find(i)==mp.end()) ans.push_back(i);
        }
        return ans;
    }
};