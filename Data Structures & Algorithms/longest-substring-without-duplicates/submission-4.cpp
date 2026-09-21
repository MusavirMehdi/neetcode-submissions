class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxcount = 0;
        int n = s.length();
        int l = 0;
        int r = 0;
        unordered_map <char,int> freq;

        while(r<n){
            freq[s[r]]++;
            while(freq[s[r]] > 1){
                freq[s[l]]--;
                l++;
            }
            maxcount = max(maxcount,r-l+1);
            r++;
        }

        return maxcount;
    }
};
