class Solution {
public:
    int minTaps(int n, vector<int>& r) {
        int sz =r.size();
        vector<int>maxReach(n+1,0);
        for(int i =0;i<sz;i++){
            int s = max(0,i-r[i]);
            int e = min(n,i+r[i]);
            maxReach[s] = max(maxReach[s], e);
        }
        
        int tap=0,currEnd=0,nextEnd=0;

        for(int i = 0;i<=n;i++){
            if(i>nextEnd) return -1;
            if(i>currEnd){
                tap++;
                currEnd=nextEnd;
            }
            nextEnd = max(nextEnd,maxReach[i]);
        }
        return tap;
    }
};