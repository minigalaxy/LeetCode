class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        pair<int, int> req[100'000];
        for(int i = 0; i < logs.size(); i++) req[i] = { logs[i][1], logs[i][0] };
        sort(req, req + logs.size());

        int order[100'000];

        for(int i = 0; i < queries.size(); i++) order[i] = i;

        sort(order, order + queries.size(), [&](int a, int b){
            return queries[a] < queries[b];
        });

        int l = 0, r = 0;
        int cnt[100'001] = { 0, };
        int cur = 0;

        vector<int> res(queries.size());

        for(int i = 0; i < queries.size(); i++){
            int query = queries[order[i]];

            while(r < logs.size() && req[r].first <= query)
                if(cnt[req[r++].second]++ == 0) cur++;

            while(l < r && req[l].first < query - x)
                if(--cnt[req[l++].second] == 0) cur--;

            res[order[i]] = n - cur;
        }

        return res;
    }
};