class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        bool dist[500];

        for(int i = 0; i < arr1.size(); i++){
            dist[i] = true;

            for(int j = 0; j < arr2.size(); j++){
                if(abs(arr1[i] - arr2[j]) <= d) dist[i] = false;
            }
        }

        return count(dist, dist + arr1.size(), true);
    }
};