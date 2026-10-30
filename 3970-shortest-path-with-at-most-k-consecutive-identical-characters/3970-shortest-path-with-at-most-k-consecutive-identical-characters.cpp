class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<pair<int, int>> edge[50'000];
        
        for(int i = 0; i < edges.size(); i++){
            edge[edges[i][0]].push_back({ edges[i][1], edges[i][2] });
        }

        priority_queue<tuple<int, int, int>> visit;
        
        int dist[50'000][50];

        fill(&dist[0][0], &dist[49'999][50], 500'000'000);

        visit.push({ 0, 0, 0 });
        dist[0][0] = 0;

        while(!visit.empty()){
            tuple<int, int, int> cur = visit.top();
            visit.pop();

            for(pair<int, int> e: edge[get<1>(cur)]){
                if(labels[get<1>(cur)] == labels[e.first]){
                    if(get<2>(cur) + 1 < k && -get<0>(cur) + e.second < dist[e.first][get<2>(cur) + 1]){
                        visit.push({ get<0>(cur) - e.second, e.first, get<2>(cur) + 1 });
                        dist[e.first][get<2>(cur) + 1] = -get<0>(cur) + e.second;
                    }
                } else {
                    if(-get<0>(cur) + e.second < dist[e.first][0]){
                        visit.push({ get<0>(cur) - e.second, e.first, 0 });
                        dist[e.first][0] = -get<0>(cur) + e.second;
                    }
                }
            }
        }

        int res = 500'000'000;

        for(int i = 0; i < 50; i++){
            res = min(res, dist[n - 1][i]);
        }

        if(res == 500'000'000) return -1;
        else return res;
    }
};