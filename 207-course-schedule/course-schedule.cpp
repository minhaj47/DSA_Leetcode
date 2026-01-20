class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // graph construction
        vector<vector<int>> graph(numCourses);
        for(auto p: prerequisites) {
            int course = p[0];
            int pre = p[1];
            // prerequisites -> course
            graph[pre].push_back(course);
        }

        vector<int> visited(numCourses, 0);

        for(int i=0; i<numCourses; i++) {
            if(!visited[i]) {
                if(isCycle(i, visited, graph)) return false;
            }
        }
        
        return true;
    }
private:
    bool isCycle(int n, vector<int>& visited, vector<vector<int>>& graph) {
        visited[n] = 1;
        for(int child: graph[n]) {
            if(visited[child] == 1){ // cycle detected
                return true; 
            }
            if(!visited[child]) {
                if(isCycle(child, visited, graph)) return true;
            } 
        }
        visited[n] = 2;
        return false;
    }
};