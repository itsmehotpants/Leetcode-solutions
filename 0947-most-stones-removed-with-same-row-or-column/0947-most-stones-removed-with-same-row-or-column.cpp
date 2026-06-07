class Solution {
public:

vector<int>parent,size ;
    int find(int n){
        if(n==parent[n]) return n;
        return parent[n]=find(parent[n]);
    }

    void union_n(int a , int b){
        int roota = find(a);
        int rootb=find(b);
        if(roota==rootb) return;
        if(size[roota]<size[rootb]){
            swap(roota,rootb);
        }
        parent[rootb]=roota;
        size[roota]+=size[rootb];
    }
    int removeStones(vector<vector<int>>& stones) {
        int n =stones.size();
        parent.resize(n);
        size.resize(n,1);
        iota(parent.begin(),parent.end(),0);
        

        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if((stones[i][0]==stones[j][0])||(stones[i][1]==stones[j][1])){
                    union_n(i,j);
                }
            }
        }
        
        int count=0;
        for(int i =0;i<n;i++){
            if(find(i)==i) count++;
        }
        return n-count;


    }
};