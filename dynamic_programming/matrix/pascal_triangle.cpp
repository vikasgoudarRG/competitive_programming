// https://leetcode.com/problems/pascals-triangle/submissions/1646862654/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        pascal.push_back(vector<int>());
        pascal[0].push_back(1);

        for (int i = 1; i < numRows; ++i) {
            vector<int> row;
            vector<int>& prev_row = pascal[i-1];

            row.push_back(1);
            for (int j = 1; j < i; ++j) {
                row.push_back(prev_row[j-1] + prev_row[j]);
            }
            row.push_back(1);
            pascal.push_back(row);
        }
        return pascal;
    }
};
