class Solution {
public:
    int missingInteger(vector<int>& nums) {
    //    int maxm = *max_element(nums.begin(),nums.ned());
       unordered_map<int,int>mp; 
       for(int i:nums) mp[i]++;
       vector<int>res;
       int ans=nums[0];
       int n =nums.size();
       for(int i = 1;i<n;i++){
        if(nums[i]-nums[i-1]==1) ans+=nums[i]; 
        else{
            break;
        }
       }
        // ans+=nums[i];
        while(mp.count(ans)) ans+=1;

        return ans;


       
       
    }
};