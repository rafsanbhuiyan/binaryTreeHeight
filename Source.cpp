#include <iostream>
#include <cstddef>
#include <algorithm>

using namespace std;

//create class node
class Node {
public:              //initialize data members and pointers
	int data;
	Node* left;
	Node* right;
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

//create class Solution
class Solution {
public:
	Node* insert(Node* root, int data) {
		if (root == NULL) {
			return new Node(data);
		}
		else {
			Node* cur;
			if (data <= root->data) {
				cur = insert(root->left, data);
				root->left = cur;
			}
			else {
				cur = insert(root->right, data);
				root->right = cur;
			}

			return root;
		}
	}

	//get height function
	int getHeight(Node* root) {

		return root == NULL ? -1 : 1 + max(getHeight(root->left), getHeight(root->right));
	}

}; //End of Solution

//main function
int main() {
	Solution myTree;
	Node* root = NULL;
	int t;
	int data;

	cin >> t;

	while (t-- > 0) {
		cin >> data;
		root = myTree.insert(root, data);
	}
	int height = myTree.getHeight(root);
	cout << height;

	return 0;
}



