class Solution {
public:
    int reverseDegree(string s) {
        int pro =0;
        int len = s.length();
        for(int i=0;i<len;i++){
            pro = pro + ((i+1)*(26-(s[i]-'a')));
        }
        return pro;
    }
};