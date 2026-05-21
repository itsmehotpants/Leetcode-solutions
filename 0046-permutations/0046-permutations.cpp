class Solution {
public:
    void f(vector<int>& nums, vector<vector<int>>& res, int idx) {
    if(idx==nums.size()){
        res.push_back(nums);
        return;

    }
    for(int i = idx; i<nums.size();i++){
        swap(nums[i],nums[idx]);
        f(nums,res,idx+1);
        swap(nums[i],nums[idx]);
    }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        f(nums, res, 0);
        return res;
    }
};