class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}}; // when we add this next element
        // we pull every subset and create a new subset with that new element

        for (int num : nums)
        {
            // what is the current size of the result so that we can add to everything
            int size = res.size(); // initially 1

            for (int i = 0; i < size; i++)
            {
                vector<int> subset = res[i]; // the pulled subset
                subset.push_back(num);
                res.push_back(subset);
            }
        }
        return res;
    }
};
