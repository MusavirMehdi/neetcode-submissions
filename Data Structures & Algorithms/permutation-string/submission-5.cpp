class Solution {
public:
    bool checkInclusion(string s1, string s2) {
         // fixed sliding window

        int s1_length = s1.length();
        int windSize = s1_length;

        int s2_length = s2.length();

        unordered_map <char,int> s1_freq;
        unordered_map <char,int> s2_freq;

        if (windSize > s2_length) return false;

        //map s1 onto its hashmap;
        for(int i=0;i<s1_length;i++){
            s1_freq[s1[i]]++;
        }

        // precompute for the first window
        for(int i=0;i<windSize;i++){
            s2_freq[s2[i]]++;
        }
        if(s1_freq == s2_freq){
            return true;
        }

        int left=0;
        int right=windSize-1;

        while (right < s2_length ) {
            s2_freq[s2[left]]--;
            if (s2_freq[s2[left]] == 0) {
                s2_freq.erase(s2[left]);
            }
            left++;
            right++;
            s2_freq[s2[right]]++;
            if (s1_freq == s2_freq) {
                return true;
            }
        }

        return false;


    }
};
