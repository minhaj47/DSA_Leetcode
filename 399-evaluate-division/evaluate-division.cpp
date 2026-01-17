class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        // graph representation
        // 1-> (2, 4), (3, 7)         // start -> (end, cost)
        unordered_map<string, unordered_map<string, double>>graph;

        // step 1: form the graph
        for(int i=0; i<equations.size(); i++) {
            string start = equations[i][0];  // divident
            string end = equations[i][1];  // divisor
            double cost = values[i];   // quotient

            graph[start][end] = cost;    // [divisor][divident] = cost
            graph[end][start] = 1.0/cost;
        }

        // step 2: process query
        vector<double>ans;

        for(int i=0; i<queries.size(); i++) {
            string start = queries[i][0];
            string end = queries[i][1];

            if(!graph.count(start) || !graph.count(end)) ans.push_back(-1.0);
            else if(start == end) ans.push_back(1.0);
            else {
                // run dfs to find from start to end
                unordered_set<string>visited;
                ans.push_back(dfs(graph, visited, start, end, 1));
            }

        }
        return ans;
    }
private:
    double dfs(unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited, string curr, string target, double acc) {
        visited.insert(curr);
        if(graph[curr].count(target)) return acc * graph[curr][target];
        for(auto [child, value]: graph[curr]){
            if(visited.count(child)) continue;
            double result = dfs(graph, visited, child, target, acc * value);
            if(result != -1.0) return result;  // if found once no need to traverse others. 
        } 
        visited.erase(curr);
        return -1.0;
    }
};