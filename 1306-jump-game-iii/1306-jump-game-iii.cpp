class Solution {
public:

bool f(int i,vector<int>& arr,vector<int>& pos,int n){
           if(i<0 || i>=n || pos[i]) return false;
        if(arr[i]==0) return true;
        pos[i]=1;
        return f(i+arr[i],arr,pos,n) || f(i-arr[i],arr,pos,n);
}
    bool canReach(vector<int>& arr, int st) {
        int n =arr.size();
        vector<int> pos(n,0);
        return f(st,arr,pos,n);
        // int i = st;
    //     if(i<0 || i>=n || pos[i]) return false;
    //     if(arr[i]==0) return true;
        



    //     while(i>=0 || i<n){
    //         pos[i]=1;
    //         i-=arr[i];
    //     }
    //     i=st;
    //      while(i>=0 || i<n){
    //         pos[i]=1;
    //         i+=arr[i];
    //     }
    //     for(int i:arr){
    //         if(i==0) return false;
    //     }
    // return true;
    }
};