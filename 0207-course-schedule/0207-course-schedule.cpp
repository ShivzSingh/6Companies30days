class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;
        vector<int> adj[N];
	    for(auto it : prerequisites){
	        adj[it[1]].push_back(it[0]);
	    }
        vector<int> inDegree(N , 0);
	    for(int i = 0 ; i < N ; i++){
	        for(auto x : adj[i]){
	            inDegree[x]++;
	        }
	    }
	    queue<int> q;
	    for(int i = 0 ; i < N ; i++){
	        if(inDegree[i] == 0){
	            q.push(i);
	        }
	    }
	    vector<int> topo;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto it : adj[node]){
	            inDegree[it]--;
	            if(inDegree[it] == 0){
	                q.push(it);
	            }
	        }
	    }
	    if(topo.size() == N){
	        return true;
	    }
	    return false;
    }
};