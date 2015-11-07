#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrder(TreeNode* root) {
    queue<TreeNode*> q1, q2;
    q1.push(root);
    
    TreeNode *curr;
    vector<vector<int> > result;
    vector<int> currLevel;

    if(root==nullptr) {
        return result;
    } else {
        currLevel.push_back(root->val);
        result.push_back(currLevel);
    }
    
    while(!q1.empty() || !q2.empty()) {
        vector<int> nextLevel;

        if(!q1.empty()) {
            while(!q1.empty()) {
                if(q1.front()->left != nullptr) {
                    curr = q1.front()->left;
                    nextLevel.push_back(curr->val);
                    q2.push(curr);
                }
                if(q1.front()->right != nullptr) {
                    curr = q1.front()->right;
                    nextLevel.push_back(curr->val);
                    q2.push(curr);
                }
                q1.pop();
            }
        } else {
            while(!q2.empty()) {
                if(q2.front()->left != nullptr) {
                    curr = q2.front()->left;
                    nextLevel.push_back(curr->val);
                    q1.push(curr);
                }
                if(q2.front()->right != nullptr) {
                    curr = q2.front()->right;
                    nextLevel.push_back(curr->val);
                    q1.push(curr);
                }
                q2.pop();
            }
        }

        if(!nextLevel.empty()) result.push_back(nextLevel);

    }   

    return result;
}

void printVector(vector<vector<int> > arr) {
    for (int row=0; row<arr.size(); row++) {
        cout << "[ ";
        for(int col=0; col<arr[row].size(); col++) {
            cout << arr[row][col] << ", ";
        }
        cout << "]" << endl;
    }

    return;
}

int main() {
    //create a tree
    TreeNode *root = new TreeNode(1);
    
    TreeNode *aNode = new TreeNode(2);
    root->left = aNode;
    aNode = new TreeNode(3);
    root->right = aNode;
    aNode = new TreeNode(4);
    root->left->left = aNode;
    aNode = new TreeNode(5);
    root->right->left = aNode;
    aNode = new TreeNode(6);
    root->right->right = aNode;

    cout << "Tree: {1, 2, 3, 4, #, 5, 6}" << endl;

    vector<vector<int> > result = levelOrder(root);
    printVector(result);

    return 0;
}
