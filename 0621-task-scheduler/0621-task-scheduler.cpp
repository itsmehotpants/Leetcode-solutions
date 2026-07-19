// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int p) {
//         int n = tasks.size();
//         unordered_map<char, int> mp;
        
//         for(char &ch : tasks) {
//             mp[ch]++;
//         }

//         priority_queue<int> pq;
//         int time = 0;
        
//         for(auto &it : mp) {
//             pq.push(it.second);
//         }
        
//         while(!pq.empty()) {
//             vector<int> temp;
//             for(int i = 1; i<=p+1; i++) {
//                 if(!pq.empty()) {
//                     temp.push_back(pq.top()-1); 
//                     pq.pop();
//                 }
//             }
            
//             for(int &freq : temp) {
//                 if(freq > 0)
//                     pq.push(freq);
//             }
            
//             if(pq.empty()) 
//                 time += temp.size();
//             else
//                 time += (p+1); 
//         }
        
//         return time;
//     }
// };
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len=tasks.size();
        unordered_map<char,int>mp;
        int maxfreq=INT_MIN;

        for(auto &task:tasks){
            mp[task]++;
            maxfreq=max(maxfreq,mp[task]);
        }
        int numberofmaxfreq=0;
        for(auto &it:mp){
            if(it.second==maxfreq){
                numberofmaxfreq++;
            }
        }
        int ans=((n+1)*(maxfreq-1))+numberofmaxfreq;
        return max(len,ans);
    }
};