class Solution {
public:
	bool ugly(int num, unordered_set<int> &param){
		if (param.find(num) != param.end()) return true;
		int sqrtn = (int)sqrt(num);
		bool f = false;
		for (int i = 2; i <= sqrtn; i++){
			if (num%i == 0){
				if (!ugly(i, param) || !ugly(num / i, param)) return false;
				f = true;
			}
		}
		if (f) param.insert(num);
		return f;
	}
	bool isUgly(int num) {
		if (num == 1) return true;
		unordered_set<int> param;
		param.insert(2);
		param.insert(3);
		param.insert(5);
		return ugly(num, param);
	}
};
