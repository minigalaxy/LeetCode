class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<pair<int, int>> sorted_log;

        for(int i = 0; i < logs.size(); i++) sorted_log.push_back({ logs[i][1], logs[i][0] });

        sort(sorted_log.begin(), sorted_log.end());

        queue<pair<int, int>> req;
        for(pair<int, int> p: sorted_log) req.push(p);

        queue<pair<int, int>> cur;
        int cnt[100'001] = { 0, };

        int arr[1'000'001] = { 0, };

        for(int i = req.front().first; (!cur.empty() || !req.empty()) && i <= 1'000'000; i++){
            arr[i] = arr[i - 1];

            if(i > x){
                while(!cur.empty() && i - x - 1 == cur.front().first){
                    if(--cnt[cur.front().second] == 0) arr[i]--;
                    cur.pop();
                }
            }

            while(!req.empty() && i == req.front().first){
                if(cnt[req.front().second]++ == 0) arr[i]++;
                cur.push(req.front());
                req.pop();
            }
        }

        vector<int> res;

        for(int query: queries) res.push_back(n - arr[query]);

        return res;
    }
};