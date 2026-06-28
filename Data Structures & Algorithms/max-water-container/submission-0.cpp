class Solution {
public:
    int maxArea(vector<int>& heights) {
        if (heights.size() == 0 || heights.size() == 1)
            return 0;

        int l = 0;
        int r = heights.size() - 1;
        int maxVal = (min(heights[l], heights[r])*(r-l));

        // it's only possible to increase the amount of water in a container
        // if we choose to move towards a larger bar between l and r

        while (l < r)
        {
            int minVal = min(heights[l], heights[r]);
            if (heights[l] == minVal && heights[l+1] > minVal)
                l++;
            else if (heights[r] == minVal && heights[r-1] > minVal)
                r--;
            else 
            {
                if (heights[l] > heights[r])
                    r--;
                else
                    l++;
            }

            if (min(heights[l], heights[r])*(r-l) > maxVal)
                maxVal = min(heights[l], heights[r])*(r-l);
        }

        return maxVal;
    }
};
