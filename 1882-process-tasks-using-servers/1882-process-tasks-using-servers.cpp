class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free;
        for(int i = 0; i < n; i++) free.push({ servers[i], i });

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;

        vector<int> res;

        for(long long i = 0, time = 0; i < m; time++){
            if(free.empty()) time = busy.top().first;

            while(!busy.empty() && busy.top().first <= time){
                free.push({ servers[busy.top().second], busy.top().second });
                busy.pop();
            }
            
            while(!free.empty() && i < m && i <= time){
                res.push_back(free.top().second);
            
                busy.push({ time + tasks[i++], free.top().second });
                free.pop();
            }
        }

        return res;
    }
};