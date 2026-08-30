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
    //5#hello5#world
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
            

            //5#Hello5#World
            string word = s.substr(i, m);
            i += m;
            // instead of for loop 
            // i want s.substr(start, +how much forward we need to go)

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
