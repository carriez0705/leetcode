class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.size();
		int n = word2.size();
		if (!m || !n) return max(m, n);
		int max_ = max(m, n) + 1;
		vector<vector<int> > matrix(m, vector<int>(n, 0));
		for (int i = 0; i<m; i++){
			for (int j = 0; j<n; j++){
				int del = i == 0 ? max_ : matrix[i - 1][j];
				int ins = j == 0 ? max_ : matrix[i][j - 1];
				int rep = (i == 0 || j == 0) ? max(i, j) : matrix[i - 1][j - 1];
				del += 1;
				ins += 1;
				rep += word1[i] == word2[j] ? 0 : 1;
				matrix[i][j] = min(min(del, ins), rep);
			}
		}
		return matrix[m - 1][n - 1];
	}
};
