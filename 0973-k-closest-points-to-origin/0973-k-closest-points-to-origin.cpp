class Solution {
public:
      vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using ppi = pair<int, int>;
        priority_queue<pair <int, ppi>> maxheap;
        for (auto& point : points){
            int a = point[0];
            int b = point[1];
            maxheap.push({a*a + b*b, {a, b} });
            if (maxheap.size() > k) maxheap.pop();
            
        }
        for (int i = 0; i < k; i++){
            auto [f, s] = maxheap.top();
            points[i] = {s.first ,s.second};
            maxheap.pop();
        }
        points.resize(k);
        reverse(points.begin(), points.end());
      
        return points;
      }
      
};