class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n =nums.size();
       
         int sum = 0;
         for(int i=0;i<k;i++){
            sum+=nums[i];
         }
        //  double avg = (double)sum/k;
        //  double curravg= 0;
        int maxsum  = sum;
         for(int i =k;i<n;i++){
            sum = sum+nums[i]-nums[i-k];
            maxsum =max(maxsum,sum);
            // curravg= (double)sum/k;
            // avg= max(avg,curravg);
         }
         return (double)maxsum/k;
    }
};