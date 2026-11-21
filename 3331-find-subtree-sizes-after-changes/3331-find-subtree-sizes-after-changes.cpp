class Solution {
public:
    void change(int cur, const string &s, vector<int> &closest, const vector<vector<int>> &child, vector<int> &parent){
        if(closest[s[cur] - 'a'] != -1) parent[cur] = closest[s[cur] - 'a'];

        int tmp = closest[s[cur] - 'a'];
        closest[s[cur] - 'a'] = cur;

        for(int c: child[cur]) change(c, s, closest, child, parent);

        closest[s[cur] - 'a'] = tmp;
    }

    int get_sub(int cur, vector<int> &answer, const vector<vector<int>> &child){
        for(int c: child[cur]) answer[cur] += get_sub(c, answer, child);
        
        return ++answer[cur];
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> child(n, vector<int>());
        for(int i = 1; i < n; i++) child[parent[i]].push_back(i);

        vector<int> closest(26, -1);

        change(0, s, closest, child, parent);

        for(int i = 0; i < n; i++) child[i].clear();
        for(int i = 1; i < n; i++) child[parent[i]].push_back(i);

        vector<int> answer(n, 0);

        get_sub(0, answer, child);

        return answer;
    }
};