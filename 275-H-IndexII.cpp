class Solution {
public:
    int search(int low, int high, vector<int> &citations){
        if(low>high) return 0;
        int mid = (low+high)>>1;
        int h = citations.size()-mid;
        if(citations[mid]<h)
            return search(mid+1, high, citations);
        else if(mid==0 || citations[mid-1]<=h)
            return h;
        else
            search(low, mid-1, citations);
    }
    int hIndex(vector<int>& citations) {
        return search(0, citations.size()-1, citations);
    }
};
