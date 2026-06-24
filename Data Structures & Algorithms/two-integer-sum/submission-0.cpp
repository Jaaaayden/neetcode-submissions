class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_index;
        int complement;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            complement = target - nums[i];
            if (num_index.count(complement))
            {
                ans.push_back(num_index.at(complement));
                ans.push_back(i);
                break;
            }
            num_index.insert({nums[i], i});
        }
        return ans;
    }
};
