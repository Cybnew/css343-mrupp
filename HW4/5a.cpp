class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //cost of Minimum Spanning Tree
        int cost = 0;
        //integer for iterating through point set
        int p = 0;
        
        vector<int> distance(points.size(), INT_MAX);
        
        //a data structure for tracking which points we've visited
        unordered_map<int,int> visited;
        
        for (int i = 0; i < points.size() - 1; i++) {
            int x = points[p][0]; 
            int y = points[p][1];
            
            visited.emplace(p,p);
            
            
            for (int j = 0; j < points.size(); j++) {
                if (visited.count(j) > 0) {
                    //we've already visited U.
                    continue;
                }
                //Compare element J distance to the absolute value of x-x1 and y-y1 and return the min to element j
                distance[j] = min(distance[j], abs(points[j][0] - x) + abs(points[j][1] - y));
            }
            
            int dist = INT_MAX;
            
            for (int i = 0; i < distance.size(); i++) {
                if (distance[i] < dist) {
                    dist = distance[i];
                    p = i;
                }
            }
            //set the distance on points we've added
            distance[p] = INT_MAX; 
            // add the distance to the cost of our MST
            cost += dist;
        }
        return cost;
    }
};
