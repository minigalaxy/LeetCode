class Solution {
public:
    struct num
    {
        int n, sum, idx;
    };

    int minSwaps(vector<int>& nums) {
        vector<num> nums_2;

        for(int i = 0; i < nums.size(); i++){
            string n_str = to_string(nums[i]);

            int n_sum = 0;

            for(char c: n_str) n_sum += c - '0';

            nums_2.push_back({ nums[i], n_sum, i });
        }

        sort(nums_2.begin(), nums_2.end(), [&](num &a, num &b){
            if(a.sum == b.sum) return a.n < b.n;
            else return a.sum < b.sum;
        });

        int indices[100'000];

        for(int i = 0; i < nums.size(); i++) indices[nums_2[i].idx] = i;

        int res = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums_2[i].idx != i){
                res++;

                indices[nums_2[i].idx] = indices[i];
                swap(nums_2[i], nums_2[indices[i]]);

                cout << '\n';
            }
        }

        return res;
    }
};