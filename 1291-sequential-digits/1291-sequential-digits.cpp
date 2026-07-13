// class Solution {
// public:
//     vector<int> sequentialDigits(int low, int high) {
//         vector<int>ans;
//         for(int len =2;len<=9;len++){
//             for(int start=1;start+len<=10;start++){
//                 int num=0;
//                 for(int d=start;d<start+len;d++){
//                     num =num*10+d;
//                 }
//                     if(num>=low &&num<=high){
//                         ans.push_back(num);
//                     }               
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        queue<int> q;
        for (int d = 1; d <= 9; d++) q.push(d);   

        while (!q.empty()) {
            int num = q.front(); q.pop();

            if (num > high) continue;             
            if (num >= low && num >= 10)          
                ans.push_back(num);

            int lastDigit = num % 10;
            if (lastDigit < 9)                 
                q.push(num * 10 + (lastDigit + 1));
        }
        return ans;
    }
};