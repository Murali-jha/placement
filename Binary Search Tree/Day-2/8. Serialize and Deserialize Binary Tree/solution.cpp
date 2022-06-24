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
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
            return "";
        
        string s;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp  =q.front();
            q.pop();
            if(temp==NULL)
                s.append("#,");
            else{
                s.append(to_string(temp->val) + ',');
            }
            
            if(temp){
                q.push(temp->left);
                q.push(temp->right);
            }
            
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data==""){
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                temp->left==NULL;
            }
            else{
                temp->left = new TreeNode(stoi(str));
                q.push(temp->left);
            }
            getline(s,str,',');
            if(str=="#"){
                temp->right==NULL;
            }
            else{
                temp->right = new TreeNode(stoi(str));
                q.push(temp->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
