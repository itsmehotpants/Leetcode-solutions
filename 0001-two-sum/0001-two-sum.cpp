class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i =0;i<nums.size();i++){
            int f =target-nums[i];
            if(mp.find(f)!=mp.end())  return{mp[f],i};
            mp[nums[i]] = i; 
        }
        return {};
    }
};