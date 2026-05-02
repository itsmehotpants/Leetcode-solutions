class Solution {
public:
bool help(vector<int>& nums, int k, int goal_sum){
    int sum=0,count=1;
    for(int i=0;i<nums.size();i++){
        if(sum+nums[i]<=goal_sum){
            sum += nums[i];
        }
        else{
            sum=nums[i]; 
            count++;

            if(count>k) return false; 
        }
    }
    return true;
}
   
    int splitArray(vector<int>& nums, int k) {
        int min=*max_element(nums.begin(),nums.end());
        int max=accumulate(nums.begin(),nums.end(),0);
        while(min<max){
            int mid=min+(max-min)/2;
            if(help(nums,k,mid)){
                max=mid;
            }
            else{
                min=mid+1;
            }
        }
        return min;
    }
};