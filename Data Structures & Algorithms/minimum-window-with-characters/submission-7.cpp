class Solution {
public:
    string minWindow(string s, string t) {
        int s_length = s.length();
        int t_length = t.length();

        unordered_map<char, int> map_s;
        unordered_map<char, int> map_t;

        for (int i = 0; i < t_length; i++) {
            map_t[t[i]]++;
        }

        int l = 0;
        int have = 0;
        int need = map_t.size();

        int bestStart = -1;
        int bestLen = INT_MAX;

        for (int r = 0; r < s_length; r++) {
            if (map_t.count(s[r])) {
                map_s[s[r]]++;
                if (map_t[s[r]] == map_s[s[r]]) {
                    have++;
                }
            }

            while (have == need) {
                if (r - l + 1 < bestLen) {
                    bestLen = r - l + 1;
                    bestStart = l;              // just an int — no copying
                }
                if (map_t.count(s[l])) {
                    map_s[s[l]]--;
                    if (map_s[s[l]] < map_t[s[l]]) {
                        have--;
                    }
                }
                l++;
            }
        }

        return bestStart == -1 ? "" : s.substr(bestStart, bestLen);  // substr called ONCE, at the very end
    }
};
/*
sl = 3
tl = 3

x 1
y 1
z 1

X
X 1 have = 1
Y
X 1
Y 1 have = 2
Z
Z 1 have = 3
have = need
cal min = 3
XYZ as answer

YZ
Y

*/
/*
:::THE ALGO:::
- ADD A CHARACTER INTO THE WINDOW.
- THEN ADD THAT CHAR INTO HASHMAP IF IT EXISTS IN t.
- IF IT DOESNT EXIST IN T WE DONT CARE.
- AFTER ADDING TO HASHMAP CHECK THE CONDN IF THAT CHAR HAS MORE THAN OR EQUAL TO
  REQUIRED OCCURENCES AS COMPARED TO ITS FREQ IN t.
- IF YES, THEN INC HAVE COUNT.
- IF HAVE COUNT IS LESS THAN NEED COUNT => EXPAND.
- IF HAVE COUNT IS EQUAL TO NEED COUNT => SHRINK.
- IF EQUAL STORE THE MINIMUM ALSO

- Inside the shrink loop
- WHEN THE ELEMENT IS IN T then only it should be decremented (becz U:0 to U:-1 if we dont check)
- 
*/
