class Solution {
public:

    string encode(vector<string>& strs) {
        int length = 0;
        string encoded = "";

        for (int i = 0; i < strs.size(); i++)
        {
            length = strs[i].length();
            encoded += (to_string(length) + "#" + strs[i]);
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;

        string str = "";
        int index = 0;
        int length;
        int hashtag;

        while (index < s.length())
        {
            hashtag = s.find('#', index);
            length = stoi(s.substr(index, hashtag - index));
            str = s.substr(hashtag + 1, length);
            decoded.push_back(str);
            index = hashtag + 1 + length;
        }

        return decoded;
    }
};
