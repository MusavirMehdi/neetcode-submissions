class Solution {
public:

    string encode(vector<string>& strs) {
        int n=strs.size();
        string merged;
        for(int i=0;i<n;i++){
            merged = merged + to_string(strs[i].length()) + '#' +  strs[i];
        }      
        return merged;
    }
    //5hello5world
    vector<string> decode(string s) {
        vector<string> sv;
        int i = 0;
        while(s[i] != '\0'){
            int m = 0;
            while(s[i] >= '0' && s[i] <= '9') {
               m = m * 10 + (s[i] - '0');
               i++;
            }

            i++;
            
            string word = "";
            for(int j = 0;j<m;j++){
                word = word + s[i];
                i++;
            }

            sv.push_back(word);
        }

    return sv;
    }
};
// to_string()
// string to int 
/*
while(s[i] >= '0' && s[i] <= '9'){
                m = (m * 10) + (s[i] - '0');
            }
*/
// char to int 
//s[i] - '0'
// int to char 
