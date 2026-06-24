class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_map<int, int> consec; 
        // we want to see if there exists a value 1 less than current 
        // if so we can create a new value 1 higher
        unordered_set<int> nums_set(nums.begin(), nums.end());

        for (int num : nums_set) // Iterate through unique numbers instead of array indices
        {
            if (!nums_set.count(num - 1)) // Only start a sequence if it's the beginning
            {
                int currentNum = num;
                int currentStreak = 1;

                while (nums_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }
                consec[num] = currentStreak;
            }
        }

        int ans = 0;
        for (auto pair : consec)
        {
            if (pair.second > ans)
                ans = pair.second;
        }

        return ans;
    }
};