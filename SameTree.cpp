/**
 *  ---------------------- SAME TREE -----------------------
 * Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:

Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:

Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:

Input: p = [1,2,1], q = [1,1,2]
Output: false
 * 
 * 
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */  


/**Solution I -- time taking 3ms -- generating both treenode string in preorder fashion and then comparing it */
class Solution {
public:
    string str = "";
    string preorderTraversalString(TreeNode *node){
        if(node == NULL){
            str = str + "*";
            return str;
        }
        
        str = str + std::to_string(node->val);
        preorderTraversalString(node->left);
        preorderTraversalString(node->right);
        return str;

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        string strp = preorderTraversalString(p);
        str = "";
        string strq = preorderTraversalString(q);
        // cout<<strp<<"  -- "<< strq;
        return strq==strp;
        
    }
};

/** solution II -- Parsing both treenodes simaltaneously and Checking for condition like struture and comparing values then following preorder fashion and it will terminate the code as soon as it gets any negative case scenario */

class Solution {
public:
    bool preorderTraversalString(TreeNode *p,TreeNode *q){

        //Comparing structure
        if(p == NULL && q == NULL){
            return true;
        }else if((p == NULL && q != NULL) || (p != NULL && q == NULL)){
            return false;
        }
        //comparing node values
        if(p->val != q->val){
            return false;
        }
        
        bool x;
        x = preorderTraversalString(p->left,q->left);
        if(!x){
            return x;
        }
        x = preorderTraversalString(p->right,q->right);
        if(!x){
            return x;
        }
        return x;

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return preorderTraversalString(p, q);
        
    }
};