class Solution {
public:
    bool check(int n , int t){
        long long product = 1;
        while(n){
            product = product * (n%10);
            n/=10;
        }
        return (product%t)==0;
    }
    int smallestNumber(int n, int t) {
        int ro = t;
        while(true){
            if(ro >= n && check(ro,t)){
                return ro;
            }
            ro = ro+1;
        }
        return 0;
    }
};