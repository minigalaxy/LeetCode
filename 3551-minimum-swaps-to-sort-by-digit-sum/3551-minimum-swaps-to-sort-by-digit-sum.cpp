class Solution {
public:
    struct Num {
        int n, sum, idx;
    };

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        Num arr[100'000];

        for (int i = 0; i < n; ++i) {
            int x = nums[i], sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            arr[i] = {nums[i], sum, i};
        }

        sort(arr, arr + n, [](const Num& a, const Num& b) {
            if (a.sum != b.sum)
                return a.sum < b.sum;
            return a.n < b.n;
        });

        int res = 0;

        for (int i = 0; i < n; ++i) {
            while (arr[i].idx != i) {
                int j = arr[i].idx;
                swap(arr[i], arr[j]);
                ++res;
            }
        }

        return res;
    }
};