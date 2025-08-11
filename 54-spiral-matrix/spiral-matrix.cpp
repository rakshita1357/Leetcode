class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int m = matrix.size(), m1 = matrix.size();
        int n = matrix[0].size(), n1 = matrix[0].size();
        int nums = m * n;
        bool drow = true;
        bool dcol = true;
        bool isrow = true;
        vector<int> out;
        int rowno = 0;
        int rrowno = m - 1;
        int colno = n - 1;
        int ccolno = 0;

        for (int i = 0; i < nums; i++) {
            if (isrow == true && drow == true && rowno <= rrowno) {
                for (int j = ccolno; j <= colno; j++) {
                    out.push_back(matrix[rowno][j]);
                }
                rowno += 1;
                isrow = false;
                drow = false;
            }
            else if (isrow == false && dcol == true && ccolno <= colno) {
                for (int j = rowno; j <= rrowno; j++) {
                    out.push_back(matrix[j][colno]);
                }
                colno -= 1;
                isrow = true;
                dcol = false;
            }
            else if (isrow == true && drow == false && rowno <= rrowno) {
                auto& row = matrix[rrowno];
                int s = row.size();
                reverse(row.begin(), row.end());
                int start = s - 1 - colno;
                int end = s - 1 - ccolno;
                for (int j = start; j <= end; j++) {
                    out.push_back(row[j]);
                }
                reverse(row.begin(), row.end());
                rrowno -= 1;
                isrow = false;
                drow = true;
            }
            else if (isrow == false && dcol == false && ccolno <= colno) {
                for (int j = rrowno; j >= rowno; j--) {
                    out.push_back(matrix[j][ccolno]);
                }
                ccolno += 1;
                isrow = true;
                dcol = true;
            }
        }
        return out;
    }
};