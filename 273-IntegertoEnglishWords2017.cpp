class Solution {
public:
	Solution()
	{
		string arr[] = { "", "Thousand", "Million", "Billion" };
		level = vector<string>(arr, arr + 4);
		string arr2[] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
		singlenumber = vector<string>(arr2, arr2 + 10);
		string arr3[] = { "","", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty","Ninety" };
		tens = vector<string>(arr3, arr3 + 10);
		string arr4[] = { "Ten", "Eleven", "Twelve", "Thirteen","Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
		elevens = vector<string>(arr4, arr4 + 10);
	}

	string numberToWords(int num) {
		return helper(to_string(num));
	}
private:
	string helper(string num)
	{
		int n = num.size();
		if (!n) return "";
		if (num == "0") return "Zero";
		int i = n - 1;
		int lcnt = 0;
		vector<string> ret;
		while (i >= 0)
		{
            int start = max(i-2, 0);
			string sub = num.substr(start, i-start+1);
			i -= 3;
			string substr = Integer2Str(sub);
			if (lcnt > 0 && substr.size())
			{
				substr += " ";
				substr.append(level[lcnt]);
			}
			if(substr.size()) ret.push_back(substr);
			lcnt++;
		}
		string retstr;
		for (int i = (int)ret.size() - 1; i >= 0; --i)
		{
			retstr.append(ret[i]);
			retstr.push_back(' ');
		}
		if (retstr.size()) retstr.pop_back();
		return retstr;
	}
	string Integer2Str(string s)
	{
		int i = 0;
		while (i < s.size() && s[i] == '0')
		{
			i++;
		}
		s = s.substr(i);
		if (s.empty()) return "";
		int n = s.size();
		string ret;
		if (n == 3)
		{
			ret.append(singlenumber[s[0] - '0']);
			ret.append(" Hundred");
			if (s[1] == '0' && s[2] == '0') return ret;
		}
		if (n >= 2)
		{
			int k = n - 2;
            if(s[k] != '0')
            {
                if (ret.size()) ret.push_back(' ');
                if (s[k] == '1')
                {
                    ret.append(elevens[s[k + 1] - '0']);
                    return ret;
                }
                ret.append(tens[s[k] - '0']);
                if (s[k + 1] == '0') return ret;
            }			
		}
		if (ret.size()) ret.push_back(' ');
		ret.append(singlenumber[s[n - 1] - '0']);
		return ret;
	}
	vector<string> level;
	vector<string> singlenumber;
	vector<string> tens;
	vector<string> elevens;
};
