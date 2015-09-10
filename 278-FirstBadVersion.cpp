// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n==0||!isBadVersion(n)) return 0;
        int i = 1, j = n;
        while(i<=j){
            int mid = ((j-i)>>1)+i;
            if(isBadVersion(mid))
                j = mid-1;
            else
                i = mid+1;
        }
        return i;
    }
};
