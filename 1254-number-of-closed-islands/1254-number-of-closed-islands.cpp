int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int island[100][100] = { 0, };

        int cnt = 0;

        bool is_opened[10'001] = { false, };

        queue<pair<int, int>> visit;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(island[i][j] == 0 && grid[i][j] == 0){
                    visit.push({ i, j });
                    island[i][j] = ++cnt;

                    while(!visit.empty()){
                        pair<int, int> cur = visit.front();
                        visit.pop();

                        for(int d = 0; d < 4; d++){
                            int nx = cur.first + dx[d], ny = cur.second + dy[d];

                            if(nx < 0 || n <= nx || ny < 0 || m <= ny) is_opened[cnt] = true;
                            else if(grid[nx][ny] == 0 && island[nx][ny] == 0){
                                visit.push({ nx, ny });
                                island[nx][ny] = cnt;
                            }
                        }
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) cout << island[i][j] << ' ';
            cout << '\n';
        }

        return count(is_opened + 1, is_opened + cnt + 1, false);
    }
};