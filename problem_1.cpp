#include <bits/stdc++.h>

using namespace std;

void floodFill(vector<vector<int>>& image, int sr, int sc, int color, int oldColor) {
    int n = image.size();
    int m = image[0].size();
    
    if (sr < 0  sr >= n  sc < 0  sc >= m  image[sr][sc] != oldColor || image[sr][sc] == color) {
        return;
    }
    
    image[sr][sc] = color;
    
    floodFill(image, sr - 1, sc, color, oldColor); // up
    floodFill(image, sr + 1, sc, color, oldColor); // down
    floodFill(image, sr, sc - 1, color, oldColor); // left
    floodFill(image, sr, sc + 1, color, oldColor); // right
}

vector<vector<int>> solve(vector<vector<int>>& image, int sr, int sc, int color) {
    int oldColor = image[sr][sc];
    
    if (oldColor == color) {
        return image;
    }
    
    floodFill(image, sr, sc, color, oldColor);
    
    return image;
}

// do not modify the code below
int main() {
    int n;
    cin >> n;
    vector<vector<int>> image(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> image[i][j];
        }
    }
    int sr, sc, color;
    cin >> sr >> sc >> color;

    vector<vector<int>> ans = solve(image, sr, sc, color);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {   
            cout << ans[i][j];
            if (j != n - 1) {
                cout << ' ';
            }
        }
        if (i != n - 1) {
            cout << '\n';
        }
    }
    return 0;
}
