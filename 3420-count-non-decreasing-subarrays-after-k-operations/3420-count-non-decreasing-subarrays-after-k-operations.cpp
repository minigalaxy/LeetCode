class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0, j = 0;
        int min_oper = 0;

        priority_queue<pair<int, int>> cur;
        cur.push({ nums[0], 0 });

        stack<int> s;
        s.push(0);

        int near_right[100'000] = { 0, };
        vector<int> rights[100'000];

        long long res = 0;

        while(i <= j){
            if(min_oper <= k){
                res += j - i + 1;

                if(j + 1 < n){
                    j++;

                    if(!cur.empty() && nums[j] < cur.top().first) min_oper += cur.top().first - nums[j];
                    cur.push({ nums[j], j });

                    while(!s.empty() && nums[s.top()] <= nums[j]){
                        near_right[s.top()] = j;
                        s.pop();
                    }

                    if(!s.empty()) rights[s.top()].push_back(j);

                    s.push(j);
                }
                else break;
            } else {
                for(int r: rights[i]){
                    if(near_right[r] > 0) min_oper -= (nums[i] - nums[r]) * (near_right[r] - r);
                    else min_oper -= (nums[i] - nums[r]) * (j - r + 1);
                }

                i++;

                while(!cur.empty() && cur.top().second < i) cur.pop();
            }
        }

        return res;
    }
};