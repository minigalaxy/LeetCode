long long R = 1'000'000'007;
long long fact[1'000] = { 0, 1, };
    
long long modpow(long long a, long long b, long long  mod) {
    long long result = 1;
    a %= mod;

    while (b > 0) {
        if (b & 1) {
            result = result * a % mod;
        }

        a = a * a % mod;
        b >>= 1;
    }

    return result;
}

class Solution {
public:
    struct BST
    {
        int val, len;
        long long sum;

        BST* left;
        BST* right;

        BST() : val(0), len(0), sum(0), left(nullptr), right(nullptr) {}

        BST* get_left(){
            if(!left) left = new BST();

            return left;
        }

        BST* get_right(){
            if(!right) right = new BST();

            return right;
        }

        int init_len(){
            int c = 1;

            if(left) c += left->init_len();
            if(right) c += right->init_len();

            return len = c;
        }

        long long get_sum(){
            if(left && right) return sum = left->get_sum() * right->get_sum() % R * fact[left->len + right->len] % R * modpow(fact[left->len] * fact[right->len], R - 2, R) % R;
            else if(left) return sum = left->get_sum();
            else if(right) return sum = right->get_sum();
            else return sum = 1LL;
        }
    };

    int numOfWays(vector<int>& nums) {
        for(int i = 2; i < 1'000; i++) fact[i] = (fact[i - 1] * i) % R;

        BST* root = new BST();

        for(int n: nums){
            BST* cur = root;

            while(cur->val > 0){
                if(n < cur->val) cur = cur->get_left();
                else cur = cur->get_right();
            }

            cur->val = n;
        }

        root->init_len();

        return root->get_sum() - 1;
    }
};