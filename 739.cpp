class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        stack<int> st;

        for (int i = temperatures.size()-1; i>=0; i--){
            if (i == temperatures.size()-1){
                st.push(i);
                ans.push_back(0);
                continue;
            }
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]){
                st.pop();
            }
            if (st.empty()){
                ans.push_back(0);
                st.push(i);
            }
            else{
                ans.push_back(st.top()- i);
                st.push(i);
            }

        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
 };

 // 1 submission