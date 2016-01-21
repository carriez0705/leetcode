class ZigzagIterator {
    vector<vector<int>::iterator> itervec, endvec;
    int cur;
public:
    ZigzagIterator(vector<vector<int> > &kvec) {
        int k = kvec.size();
        if(k==0){
            cur = -1;
        }
        else{
            itervec.resize(k);
            endvec.resize(k);
            for(int i = 0; i<k; i++){
                itervec[i] = kvec[i].begin();
                endvec[i] = kvec[i].end();
            }
            int i = 0;
            while(itervec[i]==endvec[i])
                i++;
            cur = i==k? -1 : i;
        }
    }

    int next() {
        int res = *itervec[cur];
        itervec[cur]++;
        int i = 1;
        while(i<=k && itervec[(cur+i)%k]==endvec[(cur+i)%k]){
            i++;
        }
        cur = i==k+1? -1 :cur+i;
        return res;
    }

    bool hasNext() {
        return cur!=-1;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
