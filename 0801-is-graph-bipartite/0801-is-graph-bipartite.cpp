class Solution {
    private:
    bool dfs(int node,int col,int color[],vector<vector<int>>&graph){
        color[node]=col;
        for(auto it:graph[node]){
            if(color[it]==-1){
                if(!dfs(it,!col,color,graph))return false;
            }
            else if(color[it]==col)
            return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        //visited array
        int color[n];
        for(int i=0;i<n;i++)
            color[i]=-1;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,graph)==false)return false;
            }
        }
        return true;
        
    }
};