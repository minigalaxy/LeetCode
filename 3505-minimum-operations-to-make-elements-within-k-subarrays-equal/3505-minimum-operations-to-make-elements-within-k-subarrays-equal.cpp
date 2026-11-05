class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int>> right;

        unordered_map<int, int> removed;

        long long l_sum = 0, r_sum = 0;
        int l_size = 0, r_size = 0;

        auto cost = [&](){
            return 1LL * left.top() * l_size - l_sum + r_sum - 1LL * left.top() * r_size;
        };

        auto remove = [&](auto &heap){
            while(!heap.empty()){
                if(removed[heap.top()]){
                    removed[heap.top()]--;
                    heap.pop();
                }
                else break;
            }
        };

        auto balance = [&](){
            if(l_size > r_size + 1){
                int m = left.top();

                l_sum -= m, r_sum += m;
                l_size--, r_size++;

                left.pop();
                right.push(m);

                remove(left);
            } else if(r_size > l_size){
                int m = right.top();

                r_sum -= m, l_sum += m;
                r_size--, l_size++;

                right.pop();
                left.push(m);

                remove(right);
            }
        };

        long long oper[100'000];

        for(int i = 0; i < x; i++){
            if(left.empty() || nums[i] <= left.top()){
                l_sum += nums[i];
                l_size++;

                left.push(nums[i]);
            } else {
                r_sum += nums[i];
                r_size++;

                right.push(nums[i]);
            }
            
            balance();
        }

        oper[0] = cost();

        for(int i = x; i < n; i++){
            int l = nums[i - x], r = nums[i];

            removed[l]++;

            if(l <= left.top()){
                l_sum -= l;
                l_size--;

                if(l == left.top()) remove(left);
            } else {
                r_sum -= l;
                r_size--;

                if(l == right.top()) remove(right);
            }

            balance();

            if(left.empty() || r <= left.top()){
                l_sum += r;
                l_size++;

                left.push(r);
            } else {
                r_sum += r;
                r_size++;

                right.push(r);
            }

            balance();

            oper[i - x + 1] = cost();
        }

        const long long MAX = 100'000'000'000;

        long long min_oper[100'001][16];

        fill(&min_oper[0][0], &min_oper[100'000][16], MAX);

        min_oper[0][k] = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < 16; j++) min_oper[i + 1][j] = min(min_oper[i + 1][j], min_oper[i][j]);
            if(i + x <= n)
                for(int j = 1; j < 16; j++)
                    min_oper[i + x][j - 1] = min(min_oper[i + x][j - 1], oper[i] + min_oper[i][j]);
        }

        return min_oper[n][0];
    }
};