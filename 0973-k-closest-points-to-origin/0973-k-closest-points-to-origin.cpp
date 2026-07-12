class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        priority_queue<pair<int,vector<int>>>pq;
        for(auto  a:arr){
            int dis=  a[0]*a[0] +a[1]*a[1];
            if(pq.size()<k) pq.push({dis,a});
            else if(pq.top().first>dis){
                pq.pop();
                pq.push({dis,a});
            }
        }
        vector<vector<int>>ans;
        //for(auto i:pq) ans.push_back(i.second);
    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }
        return ans;
    }
};