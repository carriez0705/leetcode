class Solution {
public:
    int cover(int a, int b, int e, int f){
        if(a>e)
            return cover(e,f,a,b);
        int co = 0;
        if(b<e)
            co = 0;
        else if(b<f)
            co = b-e;
        else
            co = f-e;
        return co;
            
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int l1 = cover(A,C,E,G);
        int l2 = cover(B,D,F,H);
        int carea = l1*l2;
        int area1 = (C-A)*(D-B);
        int area2 = (G-E)*(H-F);
        return (area1+area2-carea);
    }
};
