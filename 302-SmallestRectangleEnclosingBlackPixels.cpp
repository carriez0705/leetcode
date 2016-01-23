class Solution {
    
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        int n = m? image[0].size() : 0;
        int minx = helperRow(image, 0,x, 0, n-1, true);
        int maxx = helperRow(image, x, m-1, 0, n-1, false);
        int miny = helperColumn(image, minx, maxx, 0, y, true);
        int maxy = helperColumn(image, minx, maxx, y,n-1, false);
        return (maxx-minx+1)*(maxy-miny+1);
    }
    int helperRow(vector<vector<char> > &image, int top, int bot, int left, int right, bool findmin){
        while(top<=bot){
            int mid = (top+bot)>>1;
            int k = left;
            while(k<=right && image[mid][k]!='1') k++;
            if(k<=right){
                if(findmin) bot = mid-1;
                else top = mid+1;
            }
            else{
                if(findmin) top = mid+1;
                else bot = mid-1;
            }
        }
        return findmin? top:bot;
    }
    int helperColumn(vector<vector<char> > &image, int top, int bot, int left, int right, bool findmin){
        while(left<=right){
            int mid = (left+right)>>1;
            int k = top;
            while(k<=bot && image[k][mid]!='1') k++;
            if(k<=bot){
                if(findmin) right = mid-1;
                else left = mid+1;
            }
            else{
                if(findmin) left = mid+1;
                else right = mid-1;
            }
        }
        return findmin? left: right;
    }
};
