class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // if h == size, min k is max of piles

        // not doable if h < size
        // but if h > size, setting k = max is overkill so we should find the midpoint of arr
        // if we use midpoint of arr as hypothetical k, is this guaranteed to be an upper bound?
        // no, but we can check if h*k >= total_bananas and adjust as needed

        // h will generally be a number in the array when h isn't 2X+ size of array

        // to address these cases, we could simply divide out every element in the array
        // until h < size (using ceiling to not lose precision)

        // if size = 8, h = 25, how should the division happen? if we divide every pile by 3 + hrs by 3
        // we lose an hour of precision so doesn't seem like a real sol

        int size = piles.size();

        // actually if we just check the first instance where it's possible
        // nvm it doesn't really matter if we find when it's possible, we still keep searching the smaller half so thus binary search suffices
        int l = 1; int r = *max_element(piles.begin(), piles.end());
        int ans = r;
        int mid; int t;
        while (l <= r)
        {
            mid = (r-l)/2 + l;
            t = 0;
            for (int i = 0; i < size; i++) 
                t += ceil(static_cast<double>(piles[i])/mid);

            if (t <= h)
            {
                ans = mid;
                r = mid - 1;
            }
            else 
            {
                l = mid + 1;
            }
            
        }


        return ans;
    }
};
