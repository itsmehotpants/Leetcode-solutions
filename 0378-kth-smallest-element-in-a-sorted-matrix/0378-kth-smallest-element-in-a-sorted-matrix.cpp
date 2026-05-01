class Solution {
public:
    int count(vector<vector<int>>& a,int mid){
        int n = a.size(),r = n-1,c = 0,cnt = 0;

        while(r >= 0 && c < n){
            if(a[r][c] <= mid){
                cnt += r+1;
                c++;
            }
            else r--;
        }
        return cnt;
    }

    int kthSmallest(vector<vector<int>>& a, int k) {
        int n = a.size();
        int l = a[0][0], h = a[n-1][n-1];

        while(l < h){
            int mid = l + (h-l)/2;

            if(count(a,mid) < k) l = mid+1;
            else h = mid;
        }

        return l;
    }
};