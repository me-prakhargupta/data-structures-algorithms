#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int largestRectangle(vector<int>& heights) {
    int n = heights.size();

    vector<int> left(n), right(n);
    stack<int> st;

    // Previous Smaller Element
    for(int i = 0; i < n; i++) {
        while(!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    // Clear stack
    while(!st.empty()) st.pop();

    // Next Smaller Element
    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    int maxArea = INT_MIN;
    for(int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    vector<int> heights = {2,1,5,6,2,3}; 
    cout << largestRectangle(heights); // 10
    return 0;
}