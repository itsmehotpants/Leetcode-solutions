// class Solution {
// public:
//     int minMoves(vector<int>& nums) {
//    int minm = *min_element(nums.begin(),nums.end());
//    int maxm = *max_element(nums.begin(),nums.end());
//    cout<<minm<<" "<<maxm<<endl;
//    int n =nums.size();
//    if(minm==maxm) return 0;
//    int ops= 0;
//    while(minm!=maxm){
//     int diff= maxm-minm;
//     ops+=diff;
//     for(int i=0;i<n;i++){
//     if(nums[i]!=maxm){
//         nums[i]+=diff;
//     }
//     }

//      minm = *min_element(nums.begin(),nums.end());
//     maxm = *max_element(nums.begin(),nums.end());


//    }
//    return ops;

//     }
// };
class Solution {
public:
    int minMoves(vector<int>& nums) {
         int minm = *min_element(nums.begin(),nums.end());
   int maxm = *max_element(nums.begin(),nums.end());
   cout<<minm<<" "<<maxm<<endl;
   int n =nums.size();
   if(minm==maxm) return 0;

     sort(nums.begin(),nums.end());
     int ops = 0;
     int r= n-1;
     while(r>0){
        ops = ops+nums[r--]-nums[0];
     }
     return ops;
    }
};