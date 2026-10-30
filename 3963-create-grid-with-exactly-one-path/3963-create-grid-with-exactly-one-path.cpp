class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res;

        string top;

        for(int i = 0; i < n; i++) top += '.';

        res.push_back(top);

        string body;

        for(int i = 0; i < n - 1; i++) body += '#';

        body += '.';

        for(int i = 1; i < m; i++) res.push_back(body);

        return res;
    }
};