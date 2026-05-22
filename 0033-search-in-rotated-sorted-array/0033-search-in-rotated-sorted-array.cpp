class Solution {
public:
    int search(vector<int>& nums, int x) {
        int n = nums.size();
        int l = 0, h = n - 1;
        while (l < h) {
         int mid  =   l+(h-l)/2;
         if(nums[mid]==x) return mid;
         else if(nums[mid]<=nums[n-1]){
            if(x>nums[mid]&&x<=nums[n-1]) l=mid+1;
            else h=mid;
         } else{
            if(x>=nums[0]&&x<nums[mid]) h=mid;
            else l=mid+1;
         }

        }
        if (nums[l] == x) return l;
        return -1;
    }
};
