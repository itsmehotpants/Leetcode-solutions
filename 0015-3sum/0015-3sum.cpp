class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>res;
        int n =nums.size();
        for(int i =0;i<n-2;i++){
            int l = i+1,r=n-1;
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                if(sum==0){
                    res.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
                else if(sum>0) r--;
                else l++;
            }

        }
        vector<vector<int>>ans(res.begin(),res.end());
        return ans;
        
    }
};