class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret(temperatures.size(), 0);
        
        for (int i = temperatures.size() - 2; i >= 0; i--)
        {   
            int j = i + 1;
            while (j < temperatures.size() && temperatures[j] <= temperatures[i])
            {
                if (ret[j] == 0)
                {
                    j = temperatures.size();
                    break;
                }
                j += ret[j];
            }
            if (j < temperatures.size())
                ret[i] = j - i;
        }
        return ret;
    }
};
