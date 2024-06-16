#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to generate grid for a given n
vector<vector<char>> generateGrid(int n) {
    // Base case for n = 0, a 1x1 grid
    if (n == 0) {
        return vector<vector<char>>{{'#'}};
    }
    // Base case for n = 1, a 3x3 grid
    if (n == 1) {
        return vector<vector<char>>{
            {'#', '#', '#'},
            {'#', '.', '#'},
            {'#', '#', '#'}
        };
    }

    // Generate the smaller grid for n-1
    vector<vector<char>> smallerGrid = generateGrid(n - 1);
    int smallerSize = pow(3, n - 1);
    int newSize = 3 * smallerSize;

    // Initialize the new grid
    vector<vector<char>> newGrid(newSize, vector<char>(newSize, ' '));

    // Fill the new grid based on the pattern
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int x = 0; x < smallerSize; ++x) {
                for (int y = 0; y < smallerSize; ++y) {
                    if (i == 1 && j == 1) {
                        newGrid[i * smallerSize + x][j * smallerSize + y] = '.';
                    } else {
                        newGrid[i * smallerSize + x][j * smallerSize + y] = smallerGrid[x][y];
                    }
                }
            }
        }
    }

    return newGrid;
}

// Function to print the grid
void printGrid(const vector<vector<char>>& grid) {
    for (const auto& row : grid) {
        for (char cell : row) {
            cout << cell;
        }
        cout << endl;
    }
}

int main() {
    int n;
    // cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<char>> grid = generateGrid(n);
    printGrid(grid);

    return 0;
}
