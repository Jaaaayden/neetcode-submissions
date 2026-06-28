class Solution {
public:
    int trap(vector<int>& height) {
        // clearly we are looking for any 
        // bar at index i whose height h is <i+1 (or i-1 if right pointer)
        // this guarantees we can trap the difference between the heights
        // given that we find a bar eventually that closes it
        // let's keep a running count and modify only when we find another bar

        if (height.size() == 1 || height.size() == 2)
            return 0; // can't trap water with <3

        // int l = 0;
        // int r = height.size() - 1;

        int ans = 0; 
        vector<int> prefixMax(height.size(), 0);
        vector<int> suffixMax(height.size(), 0);

        for (int i = 1; i < height.size() - 1; i++)
            prefixMax[i] = max(prefixMax[i-1], height[i-1]);

        for (int i = height.size() - 2; i >= 1; i--)
            suffixMax[i] = max(suffixMax[i+1], height[i+1]);

        /*
        while (l < r)
        {
            if (height[l] > height[l+1])
            {
                runningWater += (height[l] - height[l+1]);
                l++;
            }
            else if (height[r] > height[r-1])
            {
                runningWater += (height[r] - height[r-1]);
                r--;
            }
        }
        */

        for (int i = 0; i < height.size(); i++)
        {
            ans += max(min(prefixMax[i], suffixMax[i]) - height[i], 0);
        }

        return ans;
    }
};
