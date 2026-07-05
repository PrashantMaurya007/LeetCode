class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int max = 0;
        stack<int> st;
        int n = heights.size();

        for(int i = 0; i<= n; i++){
            int curr = (i==n)? 0: heights[i];
            while(!st.empty() && curr < heights[st.top()]){
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i- st.top()-1;
                max = fmax(max,height*width);

            }
            st.push(i);
        }
        return max;
    }
};