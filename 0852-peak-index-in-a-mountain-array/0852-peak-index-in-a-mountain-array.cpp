class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n =arr.size();
        // for(int i =1;i<n-1;i++){
        //     if((arr[i]>arr[i-1])&&(arr[i]>arr[i+1])) return i;
        // }
        // return -1;
        int l =0,r=n-1;
        while(l<r){
            int mid  =l+(r-l)/2;
            if(arr[mid]<arr[mid+1]) l=mid+1;
            else r = mid;
        }
        return r;
    }
};