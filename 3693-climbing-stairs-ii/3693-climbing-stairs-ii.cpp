class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int total[100'001];
        total[0] = 0;
        fill(total + 1, total + n + 1, 1'010'000'000);

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j <= min(n, i + 3); j++)
                total[j] = min(total[j], total[i] + costs[j - 1] + (j - i) * (j - i));
        
        return total[n];
    }
};