class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<pair<int,int>> max_heap;
       int idx = 0;
       for(auto& p : points){
            int x_c = p[0];
            int y_c = p[1];

            long long dist = x_c * x_c + y_c * y_c;
            max_heap.push({dist,idx});
            idx++;
            if(max_heap.size()>k){
            max_heap.pop();
            }

        }

        vector<vector<int>> res;

        while(!max_heap.empty()){
            res.push_back(points[max_heap.top().second]);
            max_heap.pop();
        }


        return res;
    }
};