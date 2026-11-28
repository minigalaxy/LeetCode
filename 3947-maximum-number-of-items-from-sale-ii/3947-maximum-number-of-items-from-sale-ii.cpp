class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        int min_cost = 1'000'000'001;

        for(int i = 0; i < n; ++i) min_cost = std::min(min_cost, items[i][1]);

        int factors[100'001] = { 0, };
        int divides[100'001] = { 0, };

        for(int i = 0; i < n; ++i) factors[items[i][0]]++;

        for(int i = 1; i <= 100'000; ++i)
            for(int j = i; j <= 100'000; j += i)
                divides[i] += factors[j];

        vector<pair<int, int>> free;

        for(int i = 0; i < n; ++i)
            if(divides[items[i][0]] - 1 > 0 && items[i][1] < min_cost * 2) free.push_back({ items[i][1], divides[items[i][0]] - 1 });

        sort(free.begin(), free.end());

        int res = 0;

        for(int i = 0; i < free.size(); ++i){
            int buy = min(budget / free[i].first, free[i].second);

            res += buy * 2;
            budget -= buy * free[i].first;

            if(buy < free[i].second) break;
        }

        res += budget / min_cost;

        return res;
    }
};