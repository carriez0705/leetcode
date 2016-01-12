struct TNode{
	int val;
	pair<int, int> leftTop;
	pair<int, int> rightBot;
	TNode* neighbor[4];
	TNode(pair<int, int> p1, pair<int, int> p2) :leftTop(p1), rightBot(p2), val(0){
	    for(int i = 0; i<4; i++)
	        neighbor[i] = NULL;
	}
};
class NumMatrix {
	vector<vector<int> > mymatrix;
	TNode *root;
	TNode* buildSGtree(pair<int, int> lefttop, pair<int, int> rightbot){
		if (lefttop.first>rightbot.first || lefttop.second>rightbot.second) return NULL;
		if (lefttop == rightbot){
			TNode *n = new TNode(lefttop, rightbot);
			n->val = mymatrix[lefttop.first][lefttop.second];
			return n;
		}
		int midx = (lefttop.first + rightbot.first) >> 1;
		int midy = (lefttop.second + rightbot.second) >> 1;
		TNode *n = new TNode(lefttop, rightbot);
		n->neighbor[0] = buildSGtree(lefttop, pair<int, int>(midx, midy));
		n->neighbor[1] = buildSGtree(pair<int, int>(lefttop.first, midy + 1), pair<int, int>(midx, rightbot.second));
		n->neighbor[2] = buildSGtree(pair<int, int>(midx + 1, lefttop.second), pair<int, int>(rightbot.first, midy));
		n->neighbor[3] = buildSGtree(pair<int, int>(midx + 1, midy + 1), rightbot);
		for (int i = 0; i<4; i++)
		    if(n->neighbor[i])
			n->val += n->neighbor[i]->val;
		return n;
	}
	void updatehelper(int row, int col, int diff, TNode *node){
		if (!node) return;
		if (node->leftTop.first <= row && node->rightBot.first >= row && node->leftTop.second <= col && node->rightBot.second >= col){
			node->val += diff;
		
		    for (int i = 0; i<4; i++){
		        if(node->neighbor[i])
			        updatehelper(row, col, diff, node->neighbor[i]);
		    }
		}
	}
	int query(pair<int, int> p1, pair<int, int> p2, TNode *node){
		if (!node) return 0;
		if (p1.first <= node->leftTop.first && p1.second <= node->leftTop.second && p2.first >= node->rightBot.first && p2.second >= node->rightBot.second){
			return node->val;
		}
		else if (p1.first> node->rightBot.first || p1.second> node->rightBot.second || p2.first< node->leftTop.first || p2.second<node->leftTop.second) return 0;
		int sum = 0;
		for (int i = 0; i<4; i++){
			sum += query(p1, p2, node->neighbor[i]);
		}
		return sum;
	}
public:
	NumMatrix(vector<vector<int>> &matrix):mymatrix(matrix) {
		int m = matrix.size();
		int n = m ? matrix[0].size() : 0;
		if (!m || !n) return;
		root = buildSGtree(pair<int, int>(0, 0), pair<int, int>(m - 1, n - 1));
	}

	void update(int row, int col, int val) {
		int diff = val - mymatrix[row][col];
		if (diff){
			updatehelper(row, col, diff, root);
			mymatrix[row][col] = val;
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return query(pair<int, int>(row1, col1), pair<int, int>(row2, col2), root);
	}
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
