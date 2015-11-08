/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    string itoa(int val){
        string s = "";
        if(!val) return "0";
        while(val){
            int b = val%10;
            val /= 10;
            s.push_back(b+'0');
        }
        int i = 0, j = s.size()-1;
        while(i<j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
    void serializeOneNode(TreeNode *node, string &result){
        if(node){
            string num = itoa(node->val);
            result.append(num);
        }
        result.push_back('#');    
    }
    int atoi(string &s){
        int num = 0;
        int i = 0;
        while(i<s.size()){
            int b = s[i]-'0';
            num = num*10 + b;
            i++;
        }
        return num;
    }
    TreeNode* deserializeOneNode(string &data, int &i){
        int start = i;
        while(i<data.size() && data[i]!='#')
            i++;
        if(i==start)  return NULL;
        string num = data.substr(start, i-start);
        int val = atoi(num);
        TreeNode *node = new TreeNode(val);
        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        result.push_back('#');
        queue<TreeNode *> que;
        if(!root){
            result.push_back('#');
            return result;
        }
        que.push(root);
        serializeOneNode(root, result);
        while(!que.empty()){
            TreeNode *node = que.front();
            que.pop();
            if(node->left)
                que.push(node->left);
            serializeOneNode(node->left, result);
            if(node->right)
                que.push(node->right);
            serializeOneNode(node->right, result);
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(!data.size() || data[0]!='#') return NULL;
        int i = 1;
        TreeNode *root = deserializeOneNode(data, i);
        i += 1;
        if(!root) return root;
        queue<TreeNode *> que;
        que.push(root);
        int stat = 0;//0-open for leftc and rightc, 1-open for rightc, 2-already set
        while(i<data.size()){
            TreeNode *node = deserializeOneNode(data, i);
            i += 1;
            if(node)
                que.push(node);
            TreeNode *fr = que.front();
            if(stat==0){
                fr->left = node;
                stat+= 1;
            }
            else if(stat==1){
                fr->right = node;
                que.pop();
                stat = 0;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
