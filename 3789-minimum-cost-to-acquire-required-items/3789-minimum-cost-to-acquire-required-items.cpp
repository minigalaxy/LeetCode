class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        return 1LL * min(need1, need2) * min(cost1 + cost2, costBoth) + 1LL * abs(need1 - need2) * ((need1 > need2) ?  min(cost1, costBoth) : min(cost2, costBoth));
    }
};