// class Solution {
// public:

//     bool f(int n){
//         bool flag=1;
//         while(n>9){
//             int x = n%10;
//             n=n/10;
//             int y  = n%10;
//             if(y+1!=x) return false;
//         }
//         return true;
//     }

//     vector<int> sequentialDigits(int low, int high) {
//         vector<int>ans;
//         for(int i = low;i<=high;i++){
//             if(f(i)) ans.push_back(i);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        // string s = "123456789";
        // string l= to_string(low);
        // string h =to_string(high);

        vector<int>ans;
        for(int len =2;len<=9;len++){
            for(int start=1;start+len-1<=9;start++){
                int num=0;
                for(int d=start;d<start+len;d++){
                    num =num*10+d;
                }
                    if(num>=low &&num<=high){
                        ans.push_back(num);
                    }
                
            }
        }
        return ans;

    }
};