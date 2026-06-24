class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // move r pointer if sum is > move l pointer if sum is <

        int l = 0;
        int r = numbers.size() - 1;

        for (int i = 0; i < numbers.size(); i++)
        {
            if (numbers[l] + numbers[r] > target)
                r--;
            else if (numbers[l] + numbers[r] < target)
                l++;
            else
                return {l + 1, r + 1};
        }

        return {0};
    }
};
