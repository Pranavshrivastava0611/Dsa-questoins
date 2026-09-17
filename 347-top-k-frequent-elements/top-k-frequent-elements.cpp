class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto i : nums){
            mp[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int index = 0;
        for(auto i : mp){
            if(index < k){
                pq.push({i.second,i.first});
            }else{
                if(pq.top().first < i.second){
                    pq.pop();
                    pq.push({i.second,i.first});
                }
            }
            index++;
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};