class Solution {
public:
    bool canAliceWin(int n) {
        for(int i = 10; i > 0; --i){
            n -= i;

            if(n < 0) return (i & 1 == 1);
        }

        return false;
    }
};