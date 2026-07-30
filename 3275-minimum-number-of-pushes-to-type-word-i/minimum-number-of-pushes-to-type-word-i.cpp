class Solution {
public:
    int minimumPushes(string word) {
        int size = word.length();
        if(size <= 8) return size ;
        int div = size/8;
        int rem = size%8;
        int check = (div*(div+1))/2;
        return (8*check) + (rem*(div+1));
    }
};