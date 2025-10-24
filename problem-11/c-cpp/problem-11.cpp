#include <iostream>
#include <fstream>

#include "../../utils/cpp/strings.cpp"

using namespace std;

int main() {
    // Open file
    ifstream inputFile("problem-11/numbers.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file." << endl;
        return 1;
    }

    vector<vector<int>> matrix;

    // Fill matrix with values
    string line;
    while (getline(inputFile, line)) {
        vector<string> numberStrs = StringSplit(line, " ");
        vector<int> numbers;
        for (auto numberStr : numberStrs) {
            numbers.push_back(stoi(numberStr));
        }

        matrix.push_back(numbers);
    }

    const int SIZE = 20;
    const int DISPLACE_SIZE = 3;
    const int TRAVERSE_SIZE = SIZE - DISPLACE_SIZE;

    int maxProduct = 0;

    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            if (c < TRAVERSE_SIZE) {
                const int horizontalProduct = matrix[r][c] * matrix[r][c+1] * matrix[r][c+2] * matrix[r][c+3];
                if (horizontalProduct > maxProduct) {
                    maxProduct = horizontalProduct;
                }
            }

            if (r < TRAVERSE_SIZE) {
                const int verticalProduct = matrix[r][c] * matrix[r+1][c] * matrix[r+2][c] * matrix[r+3][c];
                if (verticalProduct > maxProduct) {
                    maxProduct = verticalProduct;
                }
            }

            if (c < TRAVERSE_SIZE && r < TRAVERSE_SIZE) {
                const int diagonalProduct = matrix[r][c] * matrix[r+1][c+1] * matrix[r+2][c+2] * matrix[r+3][c+3];
                if (diagonalProduct > maxProduct) {
                    maxProduct = diagonalProduct;
                }
            }

            if (c >= DISPLACE_SIZE && r < TRAVERSE_SIZE) {
                const int diagonalProduct = matrix[r][c] * matrix[r+1][c-1] * matrix[r+2][c-2] * matrix[r+3][c-3];
                if (diagonalProduct > maxProduct) {
                    maxProduct = diagonalProduct;
                }
            }
        }
    }

    cout << maxProduct << endl;

    // Close file
    inputFile.close();

    return 0;
}