
class Solution {
public:
    void addpoint(int x, int y, vector<pair<int, int> > &result){
        if(result.empty()||y!=result[result.size()-1].second)
            result.push_back(pair<int, int>(x, y));
    }
    void merge(vector<pair<int, int> > &vec1, vector<pair<int, int> > &vec2){
        vector<pair<int, int> > result;
        int i = 0, j = 0;
        int line1 = 0, line2 = 0;
        while(i<vec1.size()||j<vec2.size()){
            if(i<vec1.size() && (j==vec2.size()||vec1[i].first<vec2[j].first)){
                line1 = vec1[i].second;
                addpoint(vec1[i].first, max(line1, line2), result);
                i += 1;
            }
            else{
                line2 = vec2[j].second;
                addpoint(vec2[j].first, max(line1, line2), result);
                j += 1;
            }
        }
        vec1 = result;
    }
    void subline(vector<vector<int> > buildings, int left, int right, vector<pair<int, int> > &inner){
        if(left>right) return;
        if(left==right){
            inner.push_back(pair<int, int>(buildings[left][0], buildings[left][2]));
            inner.push_back(pair<int, int>(buildings[left][1], 0));
        }
        else{
            int mid = (left+right)>>1;
            vector<pair<int, int> > vec1, vec2;
            subline(buildings, left, mid, vec1);
            subline(buildings, mid+1, right, vec2);
            merge(vec1, vec2);
            inner = vec1;
        }
    }
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int> > result;
        subline(buildings, 0, buildings.size()-1, result);
        return result;
    }
};
