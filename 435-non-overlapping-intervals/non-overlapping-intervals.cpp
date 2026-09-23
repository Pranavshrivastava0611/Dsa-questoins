class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const auto& a,const auto& b){
            if(a[0]==b[0]){
                return a[1] < b[1];
            }else{
                return a[0] < b[0];
            }
        });
        int size = intervals.size();
        if(size==1) return 0;
        int start = intervals[0][0];
        int finish = intervals[0][1];
        int count = 0;
        for(int i=1;i<size;i++){
            if(intervals[i][0]==start){
                count++;
            }else{
                if(intervals[i][1] < finish){
                    count++;
                    start = intervals[i][0];
                    finish = intervals[i][1];
                }else if(intervals[i][0] < finish){
                    count++;
                    finish = min(finish,intervals[i][1]);
                }else{
                    start = intervals[i][0];
                    finish = intervals[i][1];
                }
            }
        }
        return count;
        
    }
};