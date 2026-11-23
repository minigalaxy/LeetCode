class ProductOfNumbers {
public:
    vector<int> s;

    ProductOfNumbers() {
        this->s.clear();
    }
    
    void add(int num) {
        s.push_back(num);
    }
    
    int getProduct(int k) {
        int ret = 1;

        for(int i = 0; i < k; i++) ret *= s[s.size() - 1 - i];

        return ret;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */