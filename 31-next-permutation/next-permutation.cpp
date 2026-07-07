class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                j = i;
                break;
            }
        }
        if (j != 0) {
            for (int i = n - 1; i > 0; i--) {
                if (nums[i] > nums[j - 1]) {
                    swap(nums[i], nums[j-1]);
                    break;
                }
            }
        }
        reverse(nums.begin() + j, nums.end());
    }
};