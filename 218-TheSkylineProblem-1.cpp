struct TPoint{
   int x;
   int h;
   bool left;
   TPoint(int x_, int h_, bool left_):x(x_),h(h_), left(left_){};
};

class pointHeap{
    vector<int> pheap;
    int heap_size;
    int leftc(int i){
        return (i*2+1);
    }
    int rightc(int i){
        return (i*2+2);
    }
    int parent(int i){
        return (i-1)/2;
    }
    
public:
    pointHeap(){
        pheap.clear();
        heap_size=0;
    }
    void heap_insert(int x){
        pheap.push_back(x);
        heap_size += 1;
        int i = heap_size-1;
        while(i>0 && pheap[parent(i)]<pheap[i]){
            swap(pheap[parent(i)], pheap[i]);
            i = parent(i);
        }
    }
    int heap_maxheight(){
        if(pheap.size())  return pheap[0];
        else return 0;
    }
    void max_heapify(int i){
        int maxh = i;
        if(leftc(i)<heap_size && pheap[leftc(i)]>pheap[i])
            maxh = leftc(i);
        if(rightc(i)<heap_size && pheap[rightc(i)]>pheap[maxh])
            maxh = rightc(i);
        if(maxh!=i){
            swap(pheap[maxh], pheap[i]);
            max_heapify(maxh);
        }
    }
    bool heap_remove(int h){
        int pos = pheap.size();
        for(int i = 0; i<pheap.size(); i++){
            if(pheap[i] == h){
                pos = i;
                break;
            }
        }
        if(pos!= pheap.size()){
            swap(pheap[pos], pheap[pheap.size()-1]);
            heap_size--;
            pheap.pop_back();
            max_heapify(pos);
            return true;
        }
        else return false;
    }
};

bool comp(TPoint* a, TPoint* b){
        if(a->x!=b->x) return a->x<b->x;
        else if(a->left^b->left) return a->left;
        else if(a->left && b->left) return a->h>b->h;
        else return a->h < b->h;
}
class Solution {
public:
    
    void addpoint(int x, int y, vector<pair<int, int> > &result){
        if(result.empty() || result[result.size()-1].second!= y)
            result.push_back(pair<int, int>(x,y));
    }
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<TPoint*> pvec;
        for(int i = 0; i<buildings.size(); i++){
            pvec.push_back(new struct TPoint(buildings[i][0], buildings[i][2], true));
            pvec.push_back(new struct TPoint(buildings[i][1], buildings[i][2], false));
        }
        sort(pvec.begin(), pvec.end(), comp);
        pointHeap ph = pointHeap();
        vector<pair<int, int> > result;
        for(int i = 0; i<pvec.size(); i++){
            if(pvec[i]->left)
                ph.heap_insert(pvec[i]->h);
            else
                ph.heap_remove(pvec[i]->h);
            int maxh = ph.heap_maxheight();
            addpoint(pvec[i]->x, maxh, result);
        }
        return result;
    }
};
