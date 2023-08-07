class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> start(m);
        for (int i = 0; i < m; i++) {
            start[i] = matrix[i][0];
        }
        int row = upper_bound(start.begin(), start.end(), target) - start.begin() - 1;
        if (row < 0) { return false; }
        return binary_search(matrix[row].begin(), matrix[row].end(), target);
    }
};