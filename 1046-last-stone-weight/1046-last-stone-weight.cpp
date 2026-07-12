class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxh;
        for(int i :stones) maxh.push(i);
    //    if(stones.size()==2) return stones[1]-stones[0];
        while(maxh.size()>1){
            int x = maxh.top();maxh.pop();
            int y= maxh.top();maxh.pop();
        
        if(x!=y){
            int diff= x-y;
           // maxh.pop();
            maxh.push(diff);
        }
        }
        return maxh.empty()?0:maxh.top();
    }
};