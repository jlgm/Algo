class Solution {
public:

    pair<int,int> down(int i, int j) {
        return pair<int,int>(i+1,j);
    }

    pair<int,int> up(int i, int j) {
        return pair<int,int>(i-1, j+1);
    }

    string convert(string s, int numRows) {
        int k = s.size();

        if (numRows == 1) return s;

        char grid[numRows][k];
        memset(grid,0,sizeof(grid));

        pair<int,int> cur = pair<int,int>(0,0);
        int idx = 0;

        bool isdown = 1;

        while(idx < k) {
            int i = cur.first, j = cur.second;
            grid[i][j] = s[idx++];

            if (i == numRows-1) isdown = 0;
            else if (i == 0) isdown = 1;

            if (isdown) cur = down(i, j);
            else cur = up(i,j);

        }

        string ans = "";
        for(int i = 0; i < numRows; i++)
            for(int j = 0; j < k; j++)
                if (grid[i][j] != 0) ans.push_back(grid[i][j]);

        return ans;

    }
};
