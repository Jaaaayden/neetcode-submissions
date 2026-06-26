class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        
        unordered_set<char> window;
        int res = 0;
        int l = 0;

        // clearly for lengths of >2, we need to find a way to
        // expand the curr max substring without checking every other character before
        // otherwise brute force of O(n^2) would be just as optimal

        for (int i = 0; i < s.length(); i++)
        {
            while (window.count(s[i]))
            {
                window.erase(s[l]);
                l++;
            }
            window.insert(s[i]);

            if (res < i - l + 1)
                res = i - l + 1;
        }

        return res;
    }
};
