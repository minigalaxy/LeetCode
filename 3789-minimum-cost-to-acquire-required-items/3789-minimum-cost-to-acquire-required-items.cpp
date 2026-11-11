class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ret = 0;

        if(need1 > need2){
            if(cost1 + cost2 > costBoth) ret += 1LL * need2 * costBoth;
            else ret += 1LL * need2 * (cost1 + cost2);
            if(cost1 > costBoth) ret += 1LL * (need1 - need2) * costBoth;
            else ret += 1LL * (need1 - need2) * cost1;
        } else {
            if(cost1 + cost2 > costBoth) ret += 1LL * need1 * costBoth;
            else ret += 1LL * need1 * (cost1 + cost2);
            if(cost2 > costBoth) ret += 1LL * (need2 - need1) * costBoth;
            else ret += 1LL * (need2 - need1) * cost2;
        }

        return ret;
    }
};