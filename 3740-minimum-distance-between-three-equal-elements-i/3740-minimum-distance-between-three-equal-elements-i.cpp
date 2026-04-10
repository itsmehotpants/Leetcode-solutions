class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n  =nums.size();
        int res =INT_MAX;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++) {
            mp[nums[i]].push_back(i);
        }
        for(auto &[p,q]:mp){
            if(q.size()>=3){
                for(int  i =0;i<=(int)q.size()-3;i++){
                    int a = q[i],b=q[i+1],c=q[i+2];
                    int dist = b-a+c-b+c-a;
                    res = min(res,dist);
                }
            }
        }
        return res==INT_MAX?-1:res;
    }
};