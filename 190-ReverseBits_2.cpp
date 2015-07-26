class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int lookup[] = {
            #define R2(n) n, n+(1<<7), n+(1<<6), n+(1<<7)+(1<<6)
            #define R4(n) R2(n), R2(n+(1<<5)), R2(n+(1<<4)), R2(n+(1<<5)+(1<<4))
            #define R6(n) R4(n), R4(n+(1<<3)), R4(n+(1<<2)), R4(n+(1<<2)+(1<<3))
            R6(0), R6(2), R6(1), R6(3)
        };
        uint32_t result = 0;
        unsigned char *p = (unsigned char *)&n; //note: unsigned
        unsigned char *q = (unsigned char *)&result;
        q[0] = lookup[p[3]];
        q[1] = lookup[p[2]];
        q[2] = lookup[p[1]];
        q[3] = lookup[p[0]];
        return result;
    }
};
