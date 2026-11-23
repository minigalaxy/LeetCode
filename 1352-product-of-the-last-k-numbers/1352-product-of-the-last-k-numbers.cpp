class ProductOfNumbers {
public:
    int p[40'001];
    long long i = 0, z = -1;

    ProductOfNumbers() {
        fill(p, p + 40'001, 1);
    }
    
    void add(int num) {
        if(num == 0){
            num = 1;
            z = i;
            p[i + 1] = 1;
        }
        else p[i + 1] = num * p[i];

        i++;
    }
    
    int getProduct(int k) {
        return (z < i - k) ? p[i] / p[i - k] : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */