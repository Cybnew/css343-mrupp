class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> inDeg, edge;
        for (const auto& prereq : prerequisites) {
            inDeg[prereq[0]].emplace(prereq[1]);
            edge[prereq[1]].emplace(prereq[0]);
        }
        //construct queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!inDeg.count(i)) {
                q.emplace(i);
            }
        }
        
        vector<int> result;
        while (!q.empty()) {
            const auto node = q.front(); q.pop();
            result.emplace_back(node);
            for (const auto& i : edge[node]) {
                inDeg[i].erase(node);
                if (inDeg[i].empty()) {
                    q.emplace(i);
                    inDeg.erase(i);
                }
            }
            edge.erase(node);
        }
       
        if(inDeg.empty() == true && edge.empty()==true){
           return result;
        }
        else{
            return vector<int>();
        }
        
    }
};
