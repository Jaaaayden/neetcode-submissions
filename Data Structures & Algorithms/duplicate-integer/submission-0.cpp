class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> nums_set;

        for (int num : nums) {
            if (nums_set.find(num) != nums_set.end())
                return true;  
            nums_set.insert(num);
        }
        return false; 
    }
};