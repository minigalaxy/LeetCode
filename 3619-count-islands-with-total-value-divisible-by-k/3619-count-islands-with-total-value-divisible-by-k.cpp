int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        
        queue<pair<int, int>> visit;
        bool visited[1'000][1'000] = { false, };

        int res = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && grid[i][j] > 0){
                    int total = 0;

                    visit.push({ i, j });
                    visited[i][j] = true;

                    while(!visit.empty()){
                        pair<int, int> cur = visit.front();
                        visit.pop();

                        total = (total + grid[cur.first][cur.second]) % k;

                        for(int d = 0; d < 4; d++){
                            int nx = cur.first + dx[d], ny = cur.second + dy[d];

                            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                            if(visited[nx][ny]) continue;
                            if(grid[nx][ny] == 0) continue;

                            visit.push({ nx, ny });
                            visited[nx][ny] = true;
                        }
                    }

                    if(total == 0) res++;
                }
            }
        }

        return res;
    }
};