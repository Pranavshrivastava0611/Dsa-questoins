class Solution {
public:
    int smallestNumber(int n) {
        int f = 0;
        int s = 1;
        if(n==1) return 1;
        while(true){
            f = f | s;
            if(f >= n){
                return f;
            }
            s = s<<(1);
        }
        return 0;
    }
};