class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i =num1;i<=num2;i++){
            if(i<100){
                continue;
            }
            else{
                string num=to_string(i);
                for(int x=1;x<=num.size()-2;x++){
                    if(num[x]>num[x-1]&&num[x]>num[x+1]){
                        ans++;
                    }
                    else if(num[x]<num[x-1]&&num[x]<num[x+1]){
                        ans++;
                    }
                }
            }
            
        }
        return ans;
    }
};