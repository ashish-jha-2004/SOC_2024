#include <iostream>
#include <vector>

using namespace std;

bool hasUniform2x2(const vector<string>& grid, int x, int y) {
    char first = grid[x][y];
    return grid[x][y] == first && grid[x][y + 1] == first && grid[x + 1][y] == first && grid[x + 1][y + 1] == first;
}

string canPassIQTest(vector<string>& grid) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (hasUniform2x2(grid, i, j)) {
                return "YES";
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            char original = grid[i][j];
            char newColor = (original == '.') ? '#' : '.';
            grid[i][j] = newColor;
            for (int x = max(0, i - 1); x <= min(2, i); ++x) {
                for (int y = max(0, j - 1); y <= min(2, j); ++y) {
                    if (hasUniform2x2(grid, x, y)) {
                        grid[i][j] = original;
                        return "YES";
                    }
                }
            }
            grid[i][j] = original;
        }
    }
    
    return "NO";
}

int main() {
    vector<string> grid(4);
    for (int i = 0; i < 4; ++i) {
        cin >> grid[i];
    }

    cout << canPassIQTest(grid) << endl;

    return 0;
}

