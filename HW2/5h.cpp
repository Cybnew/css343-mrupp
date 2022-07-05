class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> closest(k);
        //initialize heap
        
        priority_queue<vector<int> > heap;
        
        
        //populate heap
        for (auto& point : points) {
            int x = point[0], y = point[1];
            heap.push({x*x + y*y, x, y});
            if (heap.size() > k) {
                heap.pop();
            }
        }
        
        for (int i = 0; i < k; i++) {
            vector<int> max = heap.top();
            heap.pop();
            closest[i] = {max[1], max[2]};
        }
        
        return closest;
    }
};
