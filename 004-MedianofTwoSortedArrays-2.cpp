class Solution {
public:
    
    int findkth(vector<int> &vec1, int left1, int right1, vector<int> &vec2, int left2, int right2, int k){
        int m = right1-left1+1;
        int n = right2-left2+1;
        if(m>n)
            return findkth(vec2, left2, right2,  vec1, left1, right1, k);
        if(left1>right1)
            return vec2[left2+k-1];
        if(k==1)
            return min(vec1[left1], vec2[left2]);
        int mid = (left1+right1)>>1;
        int t = k-(m+1)>>1;
        int mid2 = left2+t-1;
        if(vec1[mid]==vec2[mid2])
            return vec1[mid];
        else if(vec1[mid]<vec2[mid2])
            return findkth(vec1, mid+1, right1, vec2, left1, mid2, k-(mid-left1+1));
        else
            return findkth(vec1, left1, mid, vec2, mid2+1, right2, k-t);
        
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int m = nums1.size();
       int n = nums2.size();
       if((m+n)%2)
            return (double)findkth(nums1, 0, m-1, nums2, 0, n-1, (m+n+1)/2);
        else
            return 0.5*(findkth(nums1, 0, m-1, nums2, 0, n-1, (m+n)/2)+findkth(nums1, 0, m-1, nums2, 0, n-1, (m+n)/2+1));
    }
};
