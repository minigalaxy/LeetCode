class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<int> row[250], col[250];
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] > 0){
                    row[i].push_back(j);
                    col[j].push_back(i);
                }

        queue<pair<int, int>> visit;
        bool visited[250][250] = { false, };

        int res = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && grid[i][j] > 0){
                    visit.push({ i, j });
                    visited[i][j] = true;

                    int cnt = 0;

                    while(!visit.empty()){
                        pair<int, int> v = visit.front();
                        visit.pop();

                        cnt++;

                        for(int c: row[v.first]){
                            if(grid[v.first][c] == 0) continue;
                            if(visited[v.first][c]) continue;

                            visit.push({ v.first, c });
                            visited[v.first][c] = true;
                        }
                        for(int r: col[v.second]){
                            if(grid[r][v.second] == 0) continue;
                            if(visited[r][v.second]) continue;

                            visit.push({ r, v.second });
                            visited[r][v.second] = true;
                        }
                    }

                    if(cnt > 1) res += cnt;
                }
            }
        }

        return res;
    }
};