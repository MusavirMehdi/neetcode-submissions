class Solution {
public:
    int compress(vector<char>& chars) {
        int read = 0;
        int write = 0;
        int n = chars.size();
        while(read < n){
            char ch = chars[read];
            int count = 0;

            while(read < n && chars[read] == ch){
                count++;
                read++;
            }

            
            if(count == 1){
                chars[write++] = ch;
            }
            else{
                chars[write++] = ch;
                string digit = to_string(count);
                for(char c: digit){
                    chars[write++] = c;
                }
            }

            

        }
        return write;

    }
};