class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        using P = pair<int, int>;
        vector<vector<P>> adjacent(N);
        for (const auto& time : times) {
            int u;
            int v; 
            int w;
            
            tie(u, v, w) = make_tuple(time[0] - 1, time[1] - 1, time[2]);
            adjacent[u].emplace_back(v, w);
        }

        int result = 0;
        unordered_set<int> lookup;
        unordered_map<int, int> fastest;
        fastest[K - 1] = 0;
        priority_queue<P, vector<P>, greater<P>> min_heap;
        min_heap.emplace(0, K - 1);
        while (!min_heap.empty() && lookup.size() != N) {
            int u;
            tie(result, u) = min_heap.top(); min_heap.pop();
            lookup.emplace(u);
            if (fastest.count(u) &&
                fastest[u] < result) {
                continue;
            }
            for (const auto& point : adjacent[u]) {
                int v, w;
                tie(v, w) = point;
                if (lookup.count(v)) continue;
                if (!fastest.count(v) ||
                    result + w < fastest[v]) {
                    fastest[v] = result + w;
                    min_heap.emplace(result + w, v);
                }
            }
        }
        return lookup.size() == N ? result : -1;
    }
};
