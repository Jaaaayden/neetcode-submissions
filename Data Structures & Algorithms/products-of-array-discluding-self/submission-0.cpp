class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        vector<int> temp(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++)
        {
            ans[i] *= nums[i-1]; // the rightmost value will be correct after this
            ans[i] *= ans[i-1];
            cout << ans[i];
        }

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            temp[i] *= nums[i+1]; 
            temp[i] *= temp[i+1];
            cout << temp[i];
        }

        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] *= temp[i];
        }

        return ans;
    }
};
