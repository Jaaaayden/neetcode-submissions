class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int cols = matrix[0].size();
        int rows = matrix.size();

        int top_row = 0;
        int bottom_row = rows - 1; 

        int ans_row = -1;

        while (top_row <= bottom_row)
        {
            int row = (top_row + bottom_row) / 2;
            if (matrix[row][cols - 1] < target)
                top_row = row + 1;
            else if (matrix[row][0] > target)
                bottom_row = row - 1;
            else {
                ans_row = row;
                break; // they're equal
            }
        }

        if (ans_row == -1)
            return false;

        int left_col = 0;
        int right_col = cols - 1;

        while (left_col <= right_col)
        {
            int col = (left_col + right_col) / 2;
            if (matrix[ans_row][col] == target)
                return true;
            else if (matrix[ans_row][col] < target)
                left_col = col + 1;
            else 
                right_col = col - 1;
        }
        return false;
        /*
        int left_col = 0;
        int left_row = 0;   

        int right_col = matrix[0].size() - 1;
        int right_row = matrix.size() - 1;

        while (left_row <= right_row && left_col <= right_col) 
        {
            int mid_col = (left_col + right_col) / 2;
            int mid_row = (left_row + right_row) / 2;

            if (matrix[mid_row][mid_col] == target)
                return true;
            else if (matrix[mid_row][mid_col] < target) {
                left_col = mid_col + 1;
                left_row = mid_row;
            }
            else {
                right_col = mid_col - 1;
                right_row = mid_row;
            }
            // cout << matrix[mid_row][mid_col] << endl;
        }
        return false;
        */
    }
};
