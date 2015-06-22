class Solution {
public:
    void addpoint(int x, int y, vector<pair<int,int> > &result){
        if(!result.empty() && result[result.size()-1].first == x)
            result[result.size()-1].second = max(y, result[result.size()-1].second);
        else
            result.push_back(pair<int,int>(x,y));
    }
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int> > result;
        map<int, int> rightedge;
        vector<vector<int> > inner;
        if(buildings.empty()) return result;
        else{
            inner.push_back(buildings[0]);
            addpoint(buildings[0][0], buildings[0][2],result);
        }
        for(int i = 1; i<buildings.size(); i++){
            vector<int> node = buildings[i];
            int j = 0;
            bool appear = true;
            bool insert = false;
            int insertpos = 0;
            int rightest = inner[inner.size()-1][1];
            while(j<inner.size()){
                if(!insert && inner[j][1] > node[1]){
                    insertpos = j;
                    insert = true;
                }
                if(inner[j][1]<node[0]){
                    if(rightedge.find(inner[j][1])!=rightedge.end()){
                        addpoint(inner[j][1], rightedge[inner[j][1]],result);
                        rightedge.erase(inner[j][1]);
                    }
                    inner.erase(inner.begin()+j);
                }
                else{
                    if(inner[j][2]>=node[2]) appear = false;
                    if(inner[j][1]<=node[1]){
                        if(inner[j][2]>node[2]){
                            int p = rightedge.find(inner[j][1])!=rightedge.end() ? rightedge[inner[j][1]] : 0;
                            rightedge[inner[j][1]] = max(p, node[2]);
                        }
                        else{
                            if(rightedge.find(inner[j][1])!=rightedge.end()) rightedge.erase(inner[j][1]);
                        }
                    }
                    else{
                        if(inner[j][2]<node[2]){
                            int p = rightedge.find(node[1])!=rightedge.end() ? rightedge[node[1]] : 0;
                            rightedge[node[1]] = max(inner[j][2], p);
                        }
                    }
                    j++;
                }
            }
            if(inner.empty()) addpoint(rightest,0,result);
            if(appear) addpoint(node[0], node[2],result);
            if(!insert) j = inner.size();
            inner.insert(inner.begin()+j, node);
        }
        for(int i = 0; i<inner.size(); i++){
            int p = rightedge.find(inner[i][1])!=rightedge.end() ? rightedge[inner[i][1]] : 0;
            addpoint(inner[i][1], p,result);
        }
        return result;
    }
};
