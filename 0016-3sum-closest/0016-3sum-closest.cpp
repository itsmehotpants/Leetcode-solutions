class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans;
        int n = nums.size();
        int diff =INT_MAX;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
            int d = abs(sum-target);
            if(diff>d){
                diff=d;
                ans =sum;
            }
            if(sum==target) return sum;
            if(sum>target) r--;
            if(sum<target) l++;
                
        }
        }
        return ans;
    }
};