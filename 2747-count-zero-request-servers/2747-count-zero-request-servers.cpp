class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](vector<int> &a, vector<int> &b){
            return (a[1] < b[1]);
        });

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

            while(r < logs.size() && logs[r][1] <= query)
                if(cnt[logs[r++][0]]++ == 0) cur++;

            while(l < r && logs[l][1] < query - x)
                if(--cnt[logs[l++][0]] == 0) cur--;

            res[order[i]] = n - cur;
        }

        return res;
    }
};