#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
        public:
                vector<vector<int> > creMatrix (int n) {
                        //create a n*n matrix
                        //randomly assign values to the matrix
                        vector<vector<int> > matrix;
                        for (int i = 0; i < n; ++i) {
                                vector<int> sub_mat;
                                for (int j = 0; j < n; ++j) {
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

                void swap(int &x, int &y) {
                        int temp = x;
                        x = y;
                        y = temp;
                }

                void rttImg(vector<vector<int> > &matrix) {
                        size_t n = matrix.size();
                        //ensure matrix is n*n
                        if (n == 0) return;
                        if (n != matrix[0].size()) return;

                        //fold the matrix diagonally
                        for (size_t i = 0; i < n; ++i) {
                                for (size_t j = 0; (i+j) < (n-1); ++j) {
                                        //cout << "i = " << i << ", j = " << j << endl;
                                        swap(matrix[i][j], matrix[n-j-1][n-i-1]);
                                }
                        }

                        //fold the matrix horizontally
                        for (size_t i = 0; i < (n-1)/2; ++i) {
                                for(size_t j = 0; j < n; ++j) 
                                        swap(matrix[i][j], matrix[n-i-1][j]);
                        }

                }

};



                                


int main () {
        Solution solution;

        vector<vector<int> > matrix = solution.creMatrix(3);
        solution.rttImg(matrix);
        cout << "Result:\n";
        solution.printMatrix(matrix);

        return 0;
}
