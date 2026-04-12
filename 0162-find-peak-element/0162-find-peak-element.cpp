class Solution {
public:
    int findPeakElement(vector<int>& nums) {
         int n = nums.size();

        // if (n == 1) {
        //     return 0; 
        // }
        // if (n == 2) {
        //     return (nums[0] > nums[1]) ? 0 : 1;
        // }

        // if (nums[0] > nums[1]) {
        //     return 0;
        // }
        // if (nums[n - 1] > nums[n - 2]) {
        //     return n - 1;
        // }

        // for (int i = 1; i < n - 1; i++) {
        //     if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
        //         return i;
        //     }
        // }
        // return -1;
        int l =0,r=n-1;
        while(l<r){
            int mid  =l+(r-l)/2;
            if(nums[mid]<nums[mid+1]) l=mid+1;
            else r = mid;
        }
        return l;
    }
};
