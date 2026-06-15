// // // class Solution {
// // // public:
// // // int n;
// // // void solve(int idx,vector<int>&nums,vector<int>&res,vector<int>&temp,int prev){
// // //     if(idx>=n) return 0;


// // // }

// // //     vector<int> largestDivisibleSubset(vector<int>& nums) {
// // //          n =nums.size();
// // //         vector<int>ans;
// // //         sort(nums.begin(),nums.end());
// // //         // for(int i =0;i<n;i++){
// // //         //     for(int j =i+1;j<n;j++){
// // //         //         if((nums[j]%nums[i]==0)||(nums[i]%nums[j]==0)){
// // //         //            ans.push_back(nums[i]);
// // //         //          //   ans.push_back(nums[j]);
                   
// // //         //         }
// // //         //     }
// // //         // }

// // //         // return ans;

// // //         vector<int>res;
// // //         vector<int>temp;
// // //         return solve(0,nums,res,-1);
// // //     }
// // // };




// // class Solution {
// // public:
    
// //     void solve(int idx, vector<int>& nums, vector<int>& res, vector<int>& temp, int prev) {
// //         if(idx >= nums.size()) {
// //             if(temp.size() > res.size()) {
// //                 res = temp;
// //             }
// //             return;
// //         }
        
// //         if(prev == -1 || nums[idx] % prev == 0) {
// //             temp.push_back(nums[idx]);
// //             solve(idx+1, nums, res, temp, nums[idx]);
// //             temp.pop_back();
// //         }
        
// //         solve(idx+1, nums, res, temp, prev);
// //     }
    
// //     vector<int> largestDivisibleSubset(vector<int>& nums) {
// //         sort(begin(nums), end(nums));
        
// //         vector<int> res;
// //         vector<int> temp;
// //         solve(0, nums, res, temp, -1);
        
// //         return res;
// //     }
// // };
// class Solution {
// public:
//     vector<int> dp[1001][1001];
//     bool vis[1001][1001];

//     vector<int> solve(int idx, int prev, vector<int>& nums) {
//         if(idx == nums.size()) return {};

//         if(vis[idx][prev + 1])
//             return dp[idx][prev + 1];

//         vis[idx][prev + 1] = true;

//         vector<int> notTake = solve(idx + 1, prev, nums);
//         vector<int> take;

//         if(prev == -1 || nums[idx] % nums[prev] == 0) {
//             take = solve(idx + 1, idx, nums);
//             take.insert(take.begin(), nums[idx]);
//         }

//         return dp[idx][prev + 1] =
//             (take.size() > notTake.size() ? take : notTake);
//     }

//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         return solve(0, -1, nums);
//     }
// };


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int n = nums.size();
        vector<int> t(n, 1);

        vector<int> prev_idx(n, -1);
        int last_chosen_index = 0;
        int maxL = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i]%nums[j] == 0) {
                    if(t[i] < t[j]+1) {
                        t[i] = t[j]+1;
                        prev_idx[i] = j;
                    }

                    if(t[i] > maxL) {
                        maxL = t[i];
                        last_chosen_index = i;
                    }
                }
            }
        }

        vector<int> res;
        while(last_chosen_index >= 0) {
            res.push_back(nums[last_chosen_index]);
            last_chosen_index = prev_idx[last_chosen_index];
        }

        return res;
    }
};