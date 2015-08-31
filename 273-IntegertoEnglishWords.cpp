string ordinary[] = {"Zero ","One ", "Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine ","Ten ","Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen "};
string tens[]={"Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety "};
string type[] = {"Hundred ","Thousand ","Million ","Billion "};
class Solution {
public:
	void num2digit(int &num, vector<int> &digit){
		while (num){
			digit.push_back(num % 10);
			num /= 10;
		}
	}
	string convert(vector<int> &digit, int high, int low, int t){
		string r = "";
		int n = high - low + 1;
		bool f = false;
		if (n == 3 ){
			n--;
			high--;
			if (digit[high + 1]){
				f = true;
				r += ordinary[digit[high+1]];
				r += type[0];
				if (digit[high] == 0){
					n--;
					high--;
					if (digit[low] == 0){
						n--;
						high--;
					}
					//else
					//    r += "and ";
				}
			}
		}
		if (n == 2){
			high--;
			n--;
			if (digit[high + 1]){
				f = true;
				if (digit[high+1] == 1){
					int d2 = digit[high+1] * 10 + digit[low];
					r += ordinary[d2];
					high--;
					n--;
				}
				else{
					r += tens[digit[high+1] - 2];
				}
			}
		}
		if (n == 1 && digit[high] >= 1){
			f = true;
			r += ordinary[digit[high]];
		}
		if (t >= 1 && f) r += type[t];
		return r;
	}
	string numberToWords(int num) {
		if (!num) return "Zero";
		vector<int> digit;
		num2digit(num, digit);
		string result = "";
		int n = (digit.size() - 1) / 3;
		int h = digit.size();
		while (h){
			string r = convert(digit, h - 1, 3 * n, n);
			result.append(r);
			h = 3 * n;
			n--;
		}
		result = result.substr(0, result.size() - 1);
		return result;
	}
};
