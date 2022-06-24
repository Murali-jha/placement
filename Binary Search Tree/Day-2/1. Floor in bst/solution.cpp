/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    if(root==NULL)
        return -1;
    int ans= -1;
    TreeNode<int> *temp = root;
    
    while(temp){
        if(temp->val==X){
            return temp->val;
        }
        else if(temp->val<X){
            ans = temp->val;
            temp  = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
    return ans;
}
