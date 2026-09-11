class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zerocnt=0;
        int n =nums.size();
        int prod =1;
        for(int i=0;i<n;i++){
            if(nums[i]==0) continue;
            prod*=nums[i];
        }
        for(int i:nums){
            if(!i) zerocnt++;
        }
        vector<int>ans(n);
        int flag;
        if(zerocnt>1) flag=2;
       else if(zerocnt==1) flag=1;
        else flag =0;
//int prod=1
        for(int i = 0;i<n;i++){
            if(flag==2){
                ans[i]=0;
            }
            else if(flag==1){
               if(nums[i]==0){
                ans[i]=prod;
               }
               else ans[i]=0;

            }
            else{
                ans[i]=prod/nums[i];
            }
        }
        return ans;
    }
};