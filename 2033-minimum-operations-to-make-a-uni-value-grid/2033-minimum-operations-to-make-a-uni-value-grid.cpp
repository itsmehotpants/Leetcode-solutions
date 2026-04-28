class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
       vector<int> nums;
       for(auto&row : grid){
        for(int k:row){
            nums.push_back(k);
        }
       }
       sort(nums.begin(),nums.end());
       int mid = nums[nums.size()/2];
       int op = 0;
       for(int  k : nums){
        int temp = abs(k-mid);
        if(temp%x!=0) return -1;
        op += temp/x; 
       } 
       return op;
    }
};