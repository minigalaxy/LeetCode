class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd[2] = { 0, }, even[2] = { 0, };
        long long res = 0;

        for(int i = 1, j = 1; i <= arr.size(); i++, j = 1 - j){
            if((arr[i - 1] & 1) == 1){
                odd[j] = even[1 - j] + 1;
                even[j] = odd[1 - j];
            } else {
                odd[j] = odd[1 - j];
                even[j] = even[1 - j] + 1;
            }

            res += odd[j];
        }

        return res % (1'000'000'000 + 7);
    }
};