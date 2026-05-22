class Solution {
public:
    int search(vector<int>& nums, int target) {
       int  n=nums.size();
        int k =target;
         for (int i = 0; i < n; i++) {
        if (nums[i] == k)
            return i;
    }
    return -1;
    }
};