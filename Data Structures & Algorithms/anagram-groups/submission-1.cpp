class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
          unordered_map <string, vector<string>> m1;
          int n = strs.size();
          vector<vector<string>> ans;

          // key value
          // 1a , c1, t1 : act,cat
          // p1 o1 t1 s1 : posts tops stop 
          
          for(int i = 0; i<n;i++){
            vector<int> count(26,0);
            for(int j=0; j<strs[i].length();j++){
                count[strs[i][j]-'a']++;
            }

            string key = "";
            for(int c: count){
                key += to_string(c) + "#";
            }

            m1[key].push_back(strs[i]);
          }

          for(auto p: m1){
             ans.push_back(p.second);
          }
          
          
          return ans;


    }
};
