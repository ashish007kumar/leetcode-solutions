class Solution {
public:

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix;
        matrix.resize(n, std::vector<int>(n, -1));
        
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;
        int val = 1;
        while (left<=right) {
            
            for (int i = left;i<=right;i++) {
                matrix[left][i] = val++;
            }
            top++;
            
            for (int i = top;i<=bottom;i++) {
                matrix[i][right] = val++;
            }
            right--;
            for (int i = right;i>=left;i--) {
                matrix[bottom][i] = val++;
            }
            bottom--;
            for (int i = bottom;i>=top;i--) {
                matrix[i][left] = val++;
            }
            left++;
        }
        return matrix;
    }
};