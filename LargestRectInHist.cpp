class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> st;
        heights.push_back(0);
        for(int i = 0; i < heights.size(); i++)
        {
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                int h = heights[st.top()];
                st.pop();
                if(st.empty())
                {
                    ans = max(ans , h*i);
                }
                else
                {
                    int len = i-st.top()-1;
                    ans = max(ans, len*h);
                }
            }
            st.push(i);
        }
        return ans;
    }
};
