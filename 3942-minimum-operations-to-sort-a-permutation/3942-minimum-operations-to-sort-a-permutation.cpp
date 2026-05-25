class Solution {
public:
    bool check(vector<int>& a){
        int c = 0, n = a.size();

        for(int i = 0; i < n; i++)
            c += a[i] > a[(i + 1) % n];

        return c <= 1;
    }

    int minOperations(vector<int>& nums) {

        int n = nums.size();

        if(check(nums)){
            int p = find(nums.begin(), nums.end(), 0) - nums.begin();
            return min(p, n - p + 2);
        }

        reverse(nums.begin(), nums.end());

        if(check(nums)){
            int p = find(nums.begin(), nums.end(), 0) - nums.begin();
            return min(p, n - p) + 1;
        }

        return -1;
    }
};