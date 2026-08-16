class Solution {
public:
    bool checkSame(int s1freq[], int windfreq[]){
        for(int i=0;i<26;i++){
            if(s1freq[i]!=windfreq[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int s1freq[26] = {0};
        for(int i=0;i<s1.length();i++){
            s1freq[s1[i] - 'a']++;
        } 

        int windSize = s1.length();
        
        for(int i=0;i<s2.length();i++){
            int idx = i;
            int windIdx = 0;
            int windfreq[26] = {0};
            while(windIdx<windSize && idx<s2.length()){
                windfreq[s2[idx]-'a']++;
                idx++;
                windIdx++;
            }
            if(checkSame(s1freq,windfreq)) return true;
        }

        return false;
    }
};
