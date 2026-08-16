class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0),topo;
        queue<int> q;
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int n=q.front();
            topo.push_back(n);
            q.pop();
            for(auto it:adj[n]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return topo.size()==numCourses;
    }
};