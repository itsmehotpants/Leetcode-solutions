class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //better
        // if (nums.empty()) return 0;

        // sort(nums.begin(), nums.end());

        // int cnt = 1, ans = 1;

        // for (int i = 1; i < nums.size(); i++) {
        //     if (nums[i] == nums[i - 1]) continue;

        //     if (nums[i] == nums[i - 1] + 1) {
        //         cnt++;
        //     } else {
        //         ans = max(ans, cnt);
        //         cnt = 1;
        //     }
        // }

        // ans = max(ans, cnt); 
        // return ans;

        // optimal
        unordered_set<int>set;
        for(int i:nums){
            set.insert(i);
        }
        int ans=0;
        for(auto i:set){
            if(set.find(i-1)==set.end()){
                int currnum = i;
                int cnt = 1;
                while(set.find(currnum+1)!=set.end()){
                    currnum++;
                    cnt++;
                }
                ans= max(ans,cnt);
            }
        }
        return ans;
    }
};
