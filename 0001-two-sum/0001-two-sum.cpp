class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // brute
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target) return{i,j};
            }
        }
        return {};
    //     //better
    //     unordered_map<int, int> mp;
    //     for (int i = 0; i < nums.size(); i++) {
    //         mp[nums[i]] = i;
    //     }
    //     for (int i = 0; i < nums.size(); i++) {
    //         int x = target - nums[i];
    //         if (mp.find(x) != mp.end() && mp[x] != i) {
    //             return {i, mp[x]};
    //         }
    //     }
    //     return {};
        
    //     //best
    //     unordered_map<int,int>mp;
    //     for(int i =0;i<nums.size();i++){
    //         int x = target-nums[i];
    //         if(mp.find(x)!=mp.end()) return {mp[x],i};
        
    //     mp[nums[i]]=i;
    //     }
    // return {};

    }
};