#include <math.h>
class Solution {
public:
    double pow(double x, int n) {
        if(x==0) return 0;
        if(x==1) return 1;
        if(x==-1)
            n = n&1;
        double base = x;
        if(n<0){
            base = 1/x;
            n = -n;
        } 
        double r = 1;
        int h = log(n)/log(2);
        for(int hh = h;hh>=0;--hh){
            int i = hh>0?n/(2<<(hh-1)):n;
            if((i&1)==0)
                r = r*r;
            else
                r = r*r*base;
        }
        return r;
    }
};
##but it did not get faster than recursive version
##because it is not the rihgt idea of non recursive version

#include <math.h>
class Solution {
public:
    double pow(double x, int n) {
        if(x==0){
            if(n>0) return 0;
            else return -1;//error
        }
        if(n==0||x==1) return 1;
        if(n<0){
            if(n==INT_MIN) return 1.0/pow(x,INT_MAX)/x;
            else return 1.0/pow(x,-n);
        }
        double r = x;
        double result = 1;
        for(;n!=0;n >>= 1,r *= r){
            if((n&1)==1)
                result *= r;
        }
        return result;
    }
};

