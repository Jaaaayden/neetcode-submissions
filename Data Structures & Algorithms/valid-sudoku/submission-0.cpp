class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> dupe_rows;
        unordered_map<int, unordered_set<char>> dupe_cols;
        map<pair<int, int>, unordered_set<char>> dupe_box;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == '.')
                    continue;
                pair<int, int> box = make_pair(i/3, j/3);

                if (dupe_rows[i].contains(board[i][j]) || 
                dupe_cols[j].contains(board[i][j]) || 
                dupe_box[box].contains(board[i][j]))
                    return false;
                
                dupe_rows[i].insert(board[i][j]);
                dupe_cols[j].insert(board[i][j]);
                dupe_box[box].insert(board[i][j]);
                
            }

        }
        return true;
    }
};
