class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m_size = matrix[0].size();
        int start = 0;
        int end = n-1;
        
        while(start<=end){
            int mid = start + (end - start) /2;
            int s = 0;
            int e = m_size-1;
            int m;
            while(s<=e){
                m = s + (e - s) / 2;
                if(matrix[mid][m] == target){
                    return true;
                }
                else if(matrix[mid][m] > target){
                    e = m - 1;
                }
                else{
                    s = m +1;
                }
            }
            if(matrix[mid][m] > target){
                end = mid - 1;
            }
            else{
                start = mid+1;
            }
        }

        return false;
    }
};
