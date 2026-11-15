class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int parity[100'001];
        for(int i = 1; i <= arr.size(); i++) parity[i] = (arr[i - 1] & 1);

        int odd[100'001] = { 0, }, even[100'001] = { 0, };
        long long res = 0;

        for(int i = 1; i <= arr.size(); i++){
            if(parity[i] == 1){
                odd[i] = even[i - 1] + 1;
                even[i] = odd[i - 1];
            } else {
                odd[i] = odd[i - 1];
                even[i] = even[i - 1] + 1;
            }

            res = (res + odd[i]) % (1'000'000'000 + 7);
        }

        return res;
    }
};