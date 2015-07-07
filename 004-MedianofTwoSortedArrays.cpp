class Solution {
public:
    int findpos(vector<int> &vec, int left, int right, int t){
        while(left<=right){
            int mid = (left+right+1)/2;
            if(vec[mid]==t){
                right = mid;
                break;
            }
            else if(vec[mid]<t)
                left = mid+1;
            else
                right = mid-1;
        }
        return right;
    }
    int findkth(vector<int> &nums1, int left1, int right1, vector<int> &nums2, int left2, int right2, int k){
        int m = right1-left1+1;
        int n = right2-left2+1;
        if(m>n)
            return findkth(nums2, left2, right2, nums1, left1, right1, k);
        if(left1>right1)
            return nums2[left2+k-1];
        int mid = (left1+right1+1)/2;
        int pos = findpos(nums2, left2, right2, nums1[mid]);
        int pre = mid-left1+1+pos-left2+1;
        if(pre==k)
            return nums1[mid];
        else if(pre<k)
            return findkth(nums1, mid+1, right1, nums2, pos+1, right2, k-pre);
        else
            return findkth(nums1, left1, mid-1, nums2, left2, pos, k);
        
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        double median = 0;
        if((m+n)%2!=0)
            median = findkth(nums1, 0, m-1, nums2, 0, n-1, (m+n+1)/2);
        else
            median = 0.5*(findkth(nums1, 0, m-1, nums2, 0, n-1, (m+n)/2) + findkth(nums1, 0, m-1, nums2, 0, n-1, (m+n)/2+1));
        return median;
    }
};
