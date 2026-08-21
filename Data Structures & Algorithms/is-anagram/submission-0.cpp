class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char,int> map4s;
        unordered_map <char,int> map4t;

        for(char ch: s){
            map4s[ch]++;
        }

        for(char ch: t){
            map4t[ch]++;
        }
        
        if(map4s == map4t){
            return true;
        }

        return false;   
    }
};
