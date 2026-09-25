class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> countT, window;
        for (char c : t) {
            countT[c]++;
        }

        int have = 0, need = countT.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int l = 0;

        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c]++;

            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }

            while (have == need) {
                if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    res = {l, r};
                }

                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
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
