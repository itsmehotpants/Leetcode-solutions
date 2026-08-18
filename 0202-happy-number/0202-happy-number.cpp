class Solution {
public:
int f(int n){
    int res= 0;
    while(n>0){
        int num = n%10;
        res+=num*num;
        n=n/10;
    }
    return res;
}
    bool isHappy(int n) {
        int slow = f(n);
        int fast = f(f(n));

        while(slow!=fast){
            if(fast==1) return true;
            slow = f(slow);
            fast = f(f(fast));
        }
        return slow==1;
    }
};