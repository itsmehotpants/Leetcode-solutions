class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> rev(n);
        vector<int> outdegree(n,0);
        for(int u=0;u<n;u++)
        {
            for(int v:graph[u])
            { 
                rev[v].push_back(u);//graph is reversed
                outdegree[u]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(outdegree[i]==0)  q.push(i);
        }
        vector<int> ans;
        while(q.size())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int nbr :rev[node])
            {
                outdegree[nbr]--;
                if(outdegree[nbr]==0)  q.push(nbr);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};