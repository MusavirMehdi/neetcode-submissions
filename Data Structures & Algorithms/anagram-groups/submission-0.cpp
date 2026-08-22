class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
          unordered_map <string, vector<string>> m1;
          int n = strs.size();
          vector<vector<string>> ans;

          // sort strs[0].begin

          // act opst opst act opst aht
          // map will be like
          // act : act, cat,hat
          // opst : pots,tops,stop
          
          for(int i = 0; i<n;i++){
            string org = strs[i];
            sort(strs[i].begin(),strs[i].end());
            m1[strs[i]].push_back(org);
          }

          for(auto p : m1){
            ans.push_back(p.second);
          }

          return ans;


    }
};
