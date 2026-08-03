class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        if(n==1) return 10;
        if(n==2) return 91;
        long long sum = 9*9*8;
        long long str = 91 + (9*9*8);
        int index = 7;
        for(int i=3;i<n;i++){
            sum = sum * index ;
            str = str + sum;
            index--;
        }
        return str;
    }
};