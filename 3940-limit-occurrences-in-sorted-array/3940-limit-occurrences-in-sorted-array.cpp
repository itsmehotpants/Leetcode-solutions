class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int cnt=0;
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i =1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) cnt++;
            else cnt=0;
           
            if(cnt>=k) continue;
            else ans.push_back(nums[i]);
        }
        return ans;

    }
};