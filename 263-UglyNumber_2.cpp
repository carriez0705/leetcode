class Solution {
public:
	
	bool isUgly(int num) {
		bool flag = true;
		while(flag&&num>1){
		    flag = false;
		    if(num%2==0){
		        num/=2;
		        flag = true;
		    }
		    if(num%3 == 0){
		        num/=3;
		        flag = true;
		    }
		    if(num%5==0){
		        num /=5;
		        flag = true;
		    }
		}
		return num==1;
	}
};
