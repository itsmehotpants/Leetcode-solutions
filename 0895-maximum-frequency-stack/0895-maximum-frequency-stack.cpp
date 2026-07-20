class FreqStack {
public:
unordered_map<int,stack<int>>m;
unordered_map<int,int>freq;
int maxFreq=0;

    FreqStack() {
        
    }
    
    void push(int val) {
        maxFreq = max(maxFreq,++freq[val]);
        m[freq[val]].push(val);

    }
    
    int pop() {
        int x = m[maxFreq].top();
        m[maxFreq].pop();
        if(!m[freq[x]--].size()) maxFreq--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */