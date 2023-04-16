class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0, curlength = 0, start = 0;
        map<char, int> mp;
        // mp chua index

        for (int i = 0; i< s.length(); i++){

            if (mp[s[i]] != 0){
                if (mp[s[i]] < start){
                    curlength++;
                    maxi = max(maxi, curlength);
                }
                else if (mp[s[i]] == start){
                    start++;

                }
                else {
                    start = mp[s[i]]+1;
                    curlength = (i+1) - mp[s[i]];
                }
            }
            else {
                curlength++;
            }
            mp[s[i]] = i+1;
            maxi = max(maxi, curlength);
            
        }
        return maxi;
    }
};

// 4 submissions