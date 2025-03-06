class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> count(n * n + 1, 0);
        
        // Count occurrences of each number
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                count[grid[i][j]]++;
            }
        }
        
        int repeated = -1, missing = -1;
        
        // Find the repeated and missing numbers
        for (int i = 1; i <= n * n; i++) {
            if (count[i] == 2) {
                repeated = i;
            } else if (count[i] == 0) {
                missing = i;
            }
            
            // Break early if we found both values
            if (repeated != -1 && missing != -1) {
                break;
            }
        }
        
        return {repeated, missing};
    }
};