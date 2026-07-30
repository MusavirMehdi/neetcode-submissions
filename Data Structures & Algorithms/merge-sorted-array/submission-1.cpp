class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = (n+m)-1;
        int i = m-1;
        int j = n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>=nums2[j]){
                nums1[idx] = nums1[i];
                i--;
                idx--;
            }
            else{ 
                nums1[idx] = nums2[j];
                j--;
                idx--;
            }
        }
        while(j>=0){
            nums1[idx]= nums2[j];
            j--;
            idx--; 
        }
    }
};
/*
10 20 20 40 0 0
         i    idx
1 2
  j
//
10 20 20 40 0 40
      i     idx
1 2      
  j
//
10 20 20 40 20 40
   i     idx     
1 2
  j
//
10 20 20 20 20 40 
i     idx
1 2
  j
//
10 20 10 20 20 40
   idx
1 2
  j
// now i<0 but j is not 
// so this another loop will run till j becomes 0
10 2 10 20 20 40 
idx      
1 2
  j
//
1 2 10 20 20 40
1 2
*/