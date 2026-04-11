class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int n) {
       int ans=0;
        for(int i :nums){
            while(i){
                if(i%10==n)ans++;
                i/=10;
            }
        }
        return ans;
    }
};