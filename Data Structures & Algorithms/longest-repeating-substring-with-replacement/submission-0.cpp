class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxwind = 0;
        int maxletter = 0;
        unordered_map <char,int> freq;
        int l = 0;
        int r = l;

        while(r<n){
            freq[s[r]]++;
            
            if(maxletter < freq[s[r]]) 
                  maxletter = freq[s[r]];

            while((r-l+1) - maxletter > k){
                freq[s[l]]--;
                l++;
            }

            maxwind = max(maxwind,r-l+1);
            r++;

        }

        return maxwind;
    }
};
