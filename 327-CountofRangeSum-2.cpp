struct TNode{
    long long val;
    int cnt;//substree node numbers, including itself
    int dup;//duplication
    TNode *left, *right;
    TNode(long long v):val(v), cnt(1), dup(1), left(NULL), right(NULL){}
};
class BSTree{
    TNode *root;
    int queryhelper(TNode *node, long long v, int rcnt){
        if(!node) return rcnt;
        if(node->val==v){
            return rcnt+node->dup+(node->right? node->right->cnt :0);
        }
        else if(node->val > v){
            return queryhelper(node->left, v, rcnt+node->dup + (node->right? node->right->cnt : 0));
        }
        else{
            return queryhelper(node->right, v, rcnt);
        }
    }
public:
    BSTree(long long v){
        root = new TNode(v);
    }
    void insert(long long v){
        TNode *node = root;
        while(node){
            node->cnt +=1;
            if(node->val==v){
                node->dup += 1;
                break;
            }
            else if(node->val < v){
                if(node->right)
                    node = node->right;
                else{
                    TNode *nn = new TNode(v);
                    node->right = nn;
                    break;
                }
            }
            else{
                if(node->left)
                    node = node->left;
                else{
                    TNode *nn = new TNode(v);
                    node->left = nn;
                    break;
                }
            }
        }
    }
    int query(long long v, long long lower, long long upper){
        //lower<=sum[j]-sum[i]<=upper
        //sum[i]>=sum[j]-upper
        //sum[i]<=sum[j]-lower
        int gt1 = queryhelper( root, v-upper,0);
        int gt2 = queryhelper( root, v-lower+1,0);
        return gt1-gt2;
    }
};
class Solution {
    
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        int ans = 0;
        if(!n) return 0;
        vector<long long> sum(n, 0);
        sum[0] = nums[0];
        for(int i = 1; i<n ; i++)
            sum[i] = sum[i-1] + nums[i];
        BSTree bst(sum[0]);
        ans = sum[0]>=lower && sum[0]<=upper;
        
        for(int i = 1; i<n; i++){
            ans += (sum[i]>=lower && sum[i]<=upper);
            ans += bst.query(sum[i], lower, upper);
            bst.insert(sum[i]);
        }
        return ans;
    }
};
