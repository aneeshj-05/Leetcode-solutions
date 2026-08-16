class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0),topo;
        queue<int> q;
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]) indegree[it]++;
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int n=q.front();
            q.pop();
            topo.push_back(n);
            for(auto i:adj[n]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        if(topo.size()==numCourses) return topo;
        return {};
    }
};