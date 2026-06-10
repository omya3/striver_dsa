#include <vector>
using namespace std;

class Solution {
private:
    void dfs_color(vector<vector<int>> &img, vector<vector<int>> &img2, int sr, int sc, 
                   int i_col, int f_col, vector<int> &del_row, vector<int> &del_col) {
        
        // Color the current pixel in the output image
        img2[sr][sc] = f_col;
        
        int n = img2.size();
        int m = img2[0].size();
        
        // Explore 4-directional neighbors
        for (int i = 0; i < 4; i++) {
            int currrow = sr + del_row[i];
            int currcol = sc + del_col[i];
            
            // Boundary checks
            if (currrow >= 0 && currrow < n && currcol >= 0 && currcol < m) {
                // Check if neighbor has original color AND hasn't been changed yet
                if (img[currrow][currcol] == i_col && img2[currrow][currcol] != f_col) {
                    dfs_color(img, img2, currrow, currcol, i_col, f_col, del_row, del_col);
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
        // If target color matches initial color, return image to prevent infinite loop
        if (image[sr][sc] == color) return image;
        
        int n = image.size();
        int m = image[0].size();
        
        // Clone the original matrix
        vector<vector<int>> image2 = image;
        
        vector<int> del_row = {-1, 0, 1, 0};
        vector<int> del_col = {0, 1, 0, -1};
        
        dfs_color(image, image2, sr, sc, image[sr][sc], color, del_row, del_col);
        
        return image2;
    }
};
