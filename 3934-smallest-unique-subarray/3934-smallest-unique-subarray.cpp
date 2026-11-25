const int p = 1'000'000'007LL;
long long b[100'000] = { 1LL, };

bool is_identical(int len, vector<int>& nums){
    if(len == 0) return false;

    int H[100'001] = { 0, };

    unordered_map<int, int> cnt;

    int res = 0;

    for(int i = 1; i <= nums.size(); ++i){
        H[i] = H[i - 1];
        if(i > len) H[i] += p - (nums[i - 1 - len] * b[len - 1]) % p;
        H[i] = (H[i] * b[1] + nums[i - 1]) % p;

        if(i >= len){
            if(cnt[H[i]] == 0) ++res;
            else if(cnt[H[i]] == 1) --res;
            
            ++cnt[H[i]];
        }
    }

    return (res > 0);
}

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        for(int i = 1; i < 100'000; i++) b[i] = (b[i - 1] * 987'654'321LL) % p;

        int l = 0, r = nums.size();

        while(l + 1 < r){
            int m = (l + r) / 2;
            
            cout << l << ' ' << m << ' ' << r << '\n';

            if(is_identical(m, nums)) r = m;
            else l = m;
        }

        return r;
    }
};