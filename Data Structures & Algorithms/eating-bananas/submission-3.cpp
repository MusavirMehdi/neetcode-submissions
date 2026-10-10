class Solution {
   public:
    bool isValid(int n, int mid,vector<int>& piles,int h) {
        long long p = 0;
        for (int i = 0; i < n; i++) {
            if (piles[i] <= mid) {
                p = p + 1;
            }
            if (piles[i] > mid) {
                p = p + (piles[i] + mid - 1) / mid;
            }
        }
        if (p > h) {
            return false;
        } else if (p <= h) {
            return true;
        }
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int minimum = INT_MAX;
        int start = 1;
        int end = 0;
        for (int i : piles) {
            end  = max(end,i);
        }


        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (isValid(n, mid,piles,h)) {
                minimum = min(mid, minimum);
                cout << minimum;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return minimum;
    }
    // 1 2 3 4 5 6 7 8 9 10
    // 5 mid
    // valid? under 9 hrs?
    // done in 2hrs
    // store as min
    // left or right?
    // min left mai belong karega
    // 1 4
    // mid 2
    // 2 valid?
    // yes valid 5 hrs.
    // store as min
    // 1
    // 1 vlid?
    // no
    // go right

    // valid?
    //  5
    //  1+4 = 5 =5
    //  k++;
    //  0 + 3 = 3
    //  3+2 = 5
    //  k++;
    //  k = 2 < 9
    //  return true

    // 2
    // 1
    // 1 < 2
    // 4
    // 5 / 2 = 2.5

    // 1
    // 1 <= 1 p++
    // 4 > 1 4/1 p++
    // 3 3* p++
    // 2 p++
};
