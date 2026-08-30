class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map <char,int> rowsmap;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(rowsmap.count(board[i][j])){
                    return false;
                }
                if (board[i][j] != '.') rowsmap[board[i][j]]++;
            }
            rowsmap.clear();
        }

        unordered_map <char,int> columnsmap;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(columnsmap.count(board[j][i])){
                    return false;
                }
                if (board[j][i] != '.') columnsmap[board[j][i]]++;
            }
            columnsmap.clear();
        }

        /*
        00 01 02 10 11 12 20 21 22 => 00 r/3 h/3
        03 04 05 13 14 15 23 24 25 => 01
        06 07 08 16 17 18 26 27 28 => 02

        02 pair will be key and value another map containing the key as char and v as int
        */

        unordered_map<int ,unordered_map<char,int>> sqmap;
        for(int i = 0;i<9;i++){
            for(int j =0;j<9;j++){
                int k = (i / 3) * 3 + (j / 3);
                if(sqmap[k].count(board[i][j])){
                    return false;
                }
                if(board[i][j] != '.') sqmap[k][board[i][j]]++;
            }
        } 


        return true;

    }
};
