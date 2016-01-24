// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
    int buffptr;
    int buffcnt;
    char *buff;
public:
    Solution(){
        buffptr = 0;
        buffcnt = 0;
        buff = new char[4];
    }
    ~Solution(){
        delete buff;
    }
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int ptr = 0;
        while(ptr<n){
            if(buffptr==0){
                buffcnt = read4(buff);
            }
            if(buffcnt==0) break;
            while(ptr<n && buffptr<buffcnt){
                buf[ptr] = buff[buffptr];
                ptr++;
                buffptr++;
            }
            if(buffptr==buffcnt) buffptr = 0;
        }
        return ptr;
    }
};
