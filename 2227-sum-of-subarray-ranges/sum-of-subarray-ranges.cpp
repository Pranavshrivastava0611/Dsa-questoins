class Solution {
public:

    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();

        long long maxiSum = 0;
        long long miniSum = 0;

        // -------------------------
        // Maximum contribution
        // -------------------------

        vector<int> leftGreater(n);
        vector<int> rightGreater(n);

        stack<int> st;

        // Previous Greater
        for(int i = 0; i < n; i++) {

            while(!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            if(st.empty())
                leftGreater[i] = -1;
            else
                leftGreater[i] = st.top();

            st.push(i);
        }

        while(!st.empty())
            st.pop();

        // Next Greater or Equal
        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if(st.empty())
                rightGreater[i] = n;
            else
                rightGreater[i] = st.top();

            st.push(i);
        }

        // Maximum contribution
        for(int i = 0; i < n; i++) {

            long long left = i - leftGreater[i];
            long long right = rightGreater[i] - i;

            maxiSum += nums[i] * left * right;
        }


        // -------------------------
        // Minimum contribution
        // -------------------------

        while(!st.empty())
            st.pop();

        vector<int> leftSmaller(n);
        vector<int> rightSmaller(n);

        // Previous Smaller
        for(int i = 0; i < n; i++) {

            while(!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            if(st.empty())
                leftSmaller[i] = -1;
            else
                leftSmaller[i] = st.top();

            st.push(i);
        }

        while(!st.empty())
            st.pop();

        // Next Smaller or Equal
        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if(st.empty())
                rightSmaller[i] = n;
            else
                rightSmaller[i] = st.top();

            st.push(i);
        }

        // Minimum contribution
        for(int i = 0; i < n; i++) {

            long long left = i - leftSmaller[i];
            long long right = rightSmaller[i] - i;

            miniSum += nums[i] * left * right;
        }

        return maxiSum - miniSum;
    }
};