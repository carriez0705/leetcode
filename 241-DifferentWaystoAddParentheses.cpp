class Solution {
public:
	int toNum(const string &input, int st, int end){
		int num = 0;
		while (st <= end){
			num = input[st] - '0' + num * 10;
			st++;
		}
		return num;
	}
	void getNum(vector<int> &vec1, vector<int> &vec2, char op, vector<int> &result){
		for (int i = 0; i<vec1.size(); i++)
		for (int j = 0; j<vec2.size(); j++){
			int r = 0;
			switch (op){
			case '+': r = vec1[i] + vec2[j]; break;
			case '-': r = vec1[i] - vec2[j]; break;
			case '*': r = vec1[i] * vec2[j]; break;
			}
			result.push_back(r);
		}
	}
	vector<int> diffWaysToCompute(string input) {
		int n = input.size();
		vector<int> nums;
		vector<char> ops;
		int st = 0;
		set<char> opp;
		opp.insert('+');
		opp.insert('-');
		opp.insert('*');
		for (int i = 0; i<n; i++){
			if (opp.find(input[i]) != opp.end()){
				nums.push_back(toNum(input, st, i - 1));
				ops.push_back(input[i]);
				st = i + 1;
			}
		}
		nums.push_back(toNum(input, st, n - 1));
		n = nums.size();
		vector<vector<vector<int> > > dict(n, vector<vector<int> >(n, vector<int>()));
		for (int i = 0; i<n; i++)
			dict[0][i].push_back(nums[i]);

		for (int len = 2; len <= n; len++){
			for (int i = 0; i <= n - len; i++)
			for (int j = i; j <= i + len - 2; j++){
				getNum(dict[j - i][i], dict[len - j + i - 2][j + 1], ops[j], dict[len - 1][i]);
			}
		}
		return dict[n - 1][0];
	}
};
