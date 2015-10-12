#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
        public:
                vector<vector<int> > creMatrix (int m, int n) {
                        vector<vector<int> > matrix;
                        for (int i = 0; i < n; ++i) {
                                vector<int> sub_mat;
                                for (int j = 0; j < m; ++j) {
                                        sub_mat.push_back(rand() % 10);
                                }
                                matrix.push_back(sub_mat);
                        }

                        cout << "Original:\n";
                        printMatrix(matrix);
                        return matrix;
                }

                void printMatrix(const vector<vector<int> > &mat) {
                        for (size_t i = 0; i < mat.size(); ++i) {
                                cout << i + 1 << ": ";
                                for (size_t j = 0; j < mat[i].size(); ++j) 
                                        cout << mat[i][j] << " ";
                                cout << endl;
                        }
                }

                void setOs(vector<vector<int> > &matrix) {
                        size_t m = matrix[0].size();
                        size_t n = matrix.size();

                        //check zeroes
                        vector<bool> row(n, false);
                        vector<bool> col(m, false);
                        for (size_t i = 0; i < n; ++i) {
                                for (size_t j = 0; j < matrix[i].size(); ++j) {
                                        if (matrix[i][j] == 0) {
                                                row.at(i) = true;
                                                col.at(j) = true;
                                        }
                                }
                        }

                        //set zeroes
                        //set row
                        for (size_t i = 0; i < row.size(); ++i) {
                                if (row.at(i)) {
                                        for (size_t j = 0; j < matrix[i].size(); ++j) 
                                                matrix[i][j] = 0;
                                }
                        }
                        //set column
                        for (size_t i = 0; i < col.size(); ++i) {
                                if (col.at(i)) {
                                        for (size_t j = 0; j < n; ++j)
                                                matrix[j][i] = 0;
                                }
                        }
                }

};



                                


int main () {
        Solution solution;

        vector<vector<int> > matrix = solution.creMatrix(5, 4);
        solution.setOs(matrix);
        cout << "Result:\n";
        solution.printMatrix(matrix);

        return 0;
}
