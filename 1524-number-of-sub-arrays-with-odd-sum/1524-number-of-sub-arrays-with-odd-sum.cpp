class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0, even = 0;
        long long res = 0;

        for(int i = 0; i < arr.size(); ++i){
            if((arr[i] & 1) == 1){
                swap(odd, even);
                ++odd;
            }
            else ++even;

            res += odd;
        }

        return res % (1'000'000'000 + 7);
    }
};