class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        int n = nums.size();
        // for(int i = 0;i<n;i++){
        //     for(int j = i+1;j<n;j++){
        //         if(nums[i]+nums[j]==t) return {i,j};
        //     }
        // }
        // return {};
        unordered_map<int,int>mp;
        for(int i =0;i<n;i++){
            int x = t- nums[i];
            if(mp.find(x)!=mp.end()) return{i,mp[x]};
            mp[nums[i]]=i;
        }
        return {};
    }
};