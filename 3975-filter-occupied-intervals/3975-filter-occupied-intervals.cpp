class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occ, int fs, int fe) {
        sort(occ.begin(),occ.end());
        vector<vector<int>>ans;
        for(auto&v: occ){
            if(ans.empty()||v[0]>ans.back()[1]+1){
                ans.push_back(v);
            }
            else{
                ans.back()[1]=max(ans.back()[1],v[1]);
            }
        }
        
        vector<vector<int>>res;
        for(auto& a:ans){
            int s = a[0],e=a[1];
            if(s<fs &&e>=s){
                res.push_back({s,min(e,fs-1)});
            }
            if(e>fe && s<=e){
                res.push_back({max(s,fe+1),e});
            }
            if(e<fs ||s>fe){
                if(res.empty()||res.back()!=vector<int>{s,e}){
                    res.push_back({s,e});
                }
            }
        }
        return res;
    }
};