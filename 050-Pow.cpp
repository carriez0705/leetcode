class Solution {
public:
    double pow(double x, int n) {
        if(x==0)
            return 0;
        else
            return power(x, n);
    }
    double power(double x, int n){
        if(n==0)
            return 1;
        double p=power(x, n/2);
        if(n%2==0)
            return p*p;
        else if(n>0)
            return p*p*x;
        else
            return p*p/x;
    }
};
