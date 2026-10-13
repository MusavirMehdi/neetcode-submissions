class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<double> merged;
        
        for(int i:nums1){
            merged.push_back(i);
        }
        for(int i:nums2){
            merged.push_back(i);
        }

        sort(merged.begin(),merged.end());

        int l = merged.size();
        if(l%2 == 0){
            double median = (merged[l/2 - 1] + merged[l/2 + 1 -1]) / 2;
            return median;
        }
        else{
            double median = merged[l/2];
            return median;
        }
    }
};

/*
median ?
if n is odd 
 n+1/2 element
if n is even
 (n/2 + n+1/2)  / 2 

brute force 
create another array merging both 
sort it 
then find median
O(n+m)
*/
