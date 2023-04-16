class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int ans = 0;
        int sum[nums.size()];
        sum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++){
            sum[i] = sum[i-1] + nums[i];
        }
        
        map<int, int> met;
        for (int i = 0; i < nums.size(); i++){
            if (sum[i] - k == 0){
                ans++;
            }
            ans += met[sum[i] - k];
            met[sum[i]]++;
        }
        return ans;
    }
};

// 2 submissions