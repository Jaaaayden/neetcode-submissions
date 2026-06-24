class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map_s;
        unordered_map<char, int> map_t;

        if (s.size() != t.size())
            return false;

        for (int i = 0; i < s.size(); i++)
        {
            if (map_s.find(s.at(i)) != map_s.end())
                map_s.at(s.at(i)) += 1;
            else
                map_s.insert({s.at(i), 1});
            
            if (map_t.find(t.at(i)) != map_t.end())
                map_t.at(t.at(i)) += 1;
            else
                map_t.insert({t.at(i), 1});
        }

        if (map_s == map_t)
            return true;
        return false;
    }
};
