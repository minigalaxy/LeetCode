int seg_avail[800'000];

int update(int target, int val, int idx, int l, int r){
    if(target < l || r < target) return seg_avail[idx];
    if(l == r) return seg_avail[idx] = val;

    int m = (l + r) / 2;

    return seg_avail[idx] = min(update(target, val, idx * 2, l, m), update(target, val, idx * 2 + 1, m + 1, r));
}

int query(int time, int idx, int l, int r){
    if(seg_avail[idx] > time) return 200'000;
    if(l == r) return l;

    int m = (l + r) / 2;

    if(seg_avail[idx * 2] <= time) return query(time, idx * 2, l, m);
    if(seg_avail[idx * 2 + 1] <= time) return query(time, idx * 2 + 1, m + 1, r);
    else return 200'000;
}

int search(int time, int i, int j, int idx, int l, int r){
    if(j < l || r < i) return 200'000;
    if(i <= l && r <= j) return query(time, idx, l, r);

    int m = (l + r) / 2;

    return min(search(time, i, j, idx * 2, l, m), search(time, i, j, idx * 2 + 1, m + 1, r));
}

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        fill(seg_avail, seg_avail + 800'000, 0);

        int handle_nums[100'000] = { 0, };

        for(int i = 0, time = 0; i < arrival.size(); i++){
            time = arrival[i];
            
            int req = search(time, i % k, i % k + k - 1, 1, 0, 2 * k - 1);

            if(req == 200'000) continue;

            update(req % k, time + load[i], 1, 0, 2 * k - 1);
            update(req % k + k, time + load[i], 1, 0, 2 * k - 1);

            handle_nums[req % k]++;
        }

        int busiest = *max_element(handle_nums, handle_nums + k);

        vector<int> res;

        for(int i = 0; i < k; i++)
            if(handle_nums[i] == busiest) res.push_back(i);
        
        return res;
    }
};