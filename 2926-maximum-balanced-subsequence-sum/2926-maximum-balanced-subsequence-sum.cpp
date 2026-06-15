// // class Solution {
// // public:

// //     typedef long long ll;
// // unordered_map<string,ll>mp;
// //      ll solve(int i,int prev,vector<int>&nums){
// //         if(i>=nums.size()) return 0;

// //         string key  =to_string(prev)+"_"+to_string(i);
// //         if(mp.find(key)!=mp.end()) return mp[key];
// //         ll taken =INT_MIN,notTaken=INT_MIN;
// //         if(prev==-1|| nums[i]-i>=nums[prev]-prev){
// //             taken  = nums[i]+solve(i+1,i,nums);
// //         }
// //         notTaken =solve(i+1,prev,nums);
// //         return mp[key]=max<ll>(taken,notTaken);
// //      }

// //     long long maxBalancedSubsequenceSum(vector<int>& nums) {
// //         int maxele = *max_element(nums.begin(),nums.end());
// //         if(maxele<=0) return maxele;
// //     return solve(0,-1,nums);   
// //     }
// // };


// class Solution {
// public:
//     long long maxBalancedSubsequenceSum(vector<int>& nums) {
//         int n = nums.size();
        
//         int maxEl = *max_element(begin(nums), end(nums));
//         if(maxEl <= 0) {
//             return maxEl;
//         }

//         vector<long long> t(n);
//         for(int i = 0; i<n; i++) {
//             t[i] = nums[i];
//         }

//         long long maxSum = INT_MIN;
//         for(int i = 0; i<n; i++) {

//             for(int j = 0; j<i; j++) {

//                 if(nums[i] - i >= nums[j] - j) {
//                     t[i] = max<long long>(t[i], t[j] + nums[i]);
//                     maxSum = max<long long>(maxSum, t[i]);
//                 }

//             }
//         }

//         return maxSum > maxEl ? maxSum : maxEl;
//     }
// };


class Solution {
public:
    typedef long long ll;

    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        map<int,ll>mp; // nums[i]-i,sum
        ll res =INT_MIN;
       
        for(int i = 0; i<n; i++) {
            auto it = mp.upper_bound(nums[i]-i);
            ll sum =nums[i];
            if(it!=mp.begin()){
                it--;
                sum+=it->second;
            }
            mp[nums[i]-i]  = max(mp[nums[i]-i],sum);
            
            it  = mp.upper_bound(nums[i]-i);
            while(it!=mp.end()&&it->second<=sum) mp.erase(it++);

    res = max(res,sum);
        }

        return res;
    }
};
