class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // able to sort in nlogn (time complexity not dominated by sort)

        vector<int> sorted_nums(nums.begin(), nums.end());
        sort(sorted_nums.begin(), sorted_nums.end());

        vector<vector<int>> ans;

        // iterate over each of the n numbers, use 2 pointer approach to find if there
        // exists a 2sum that sums to 0 - sorted_nums[i]?

        /*
        unordered_map<int, int> num_freq;

        for (int num : nums)
            num_freq[num]++;
        */

        for (int i = 0; i < nums.size(); i++)
        {
            if (sorted_nums[i] > 0)
                break;
            if (i > 0 && sorted_nums[i] == sorted_nums[i-1])
                continue;

            int target = 0 - sorted_nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                if (sorted_nums[l] + sorted_nums[r] > target)
                    r--;
                else if (sorted_nums[l] + sorted_nums[r] < target)
                    l++;
                else {
                    ans.push_back({sorted_nums[i], sorted_nums[l], sorted_nums[r]});
                    l++; r--;
                    while (l < r && sorted_nums[l] == sorted_nums[l-1]) l++;
                    while (l < r && sorted_nums[r] == sorted_nums[r+1]) r--;
                }
            }
        }

        return ans;

    }
};
