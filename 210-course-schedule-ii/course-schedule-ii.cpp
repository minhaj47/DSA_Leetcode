class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);

        for(auto p: prerequisites) {
            int course = p[1];
            int pre = p[0];
            graph[pre].push_back(course);
        }

        vector<int> visited(numCourses, 0);
        vector<int> ans;

        for(int i=0; i<numCourses; i++) {
            if(!visited[i])dfs(i, visited, graph, ans);
        }
        return isCycle ? vector<int>() : ans;
    }

private: 
    bool isCycle = false;
    void dfs(int n, vector<int>& visited, vector<vector<int>>& graph, vector<int>& ans) {
        if(isCycle) return;
        visited[n] = 1;
        for(int child: graph[n]) {
            if(visited[child] == 1){
                isCycle = true;
                return;
            } 
            if(!visited[child])
                dfs(child, visited, graph, ans);
        }
        visited[n] = 2;
        ans.push_back(n);
    }
};