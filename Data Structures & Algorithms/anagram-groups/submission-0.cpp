class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;

        for (int i = 0; i < strs.size(); i++)
        {
            int charOccurences[26] = {0};
            string key = "";
            for (int j = 0; j < strs[i].size(); j++)
                charOccurences[strs[i][j] - 'a']++;
            for (int j = 0; j < 26; j++)
                key += "," + to_string(charOccurences[j]);
            ans[key].push_back(strs[i]);
        }
        vector<vector<string>> ret;
        for (pair<const string, vector<string>>& entry : ans)
            ret.push_back(entry.second);

        return ret;
    }
};
