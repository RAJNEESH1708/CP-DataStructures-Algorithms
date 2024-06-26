#include<bits/stdc++.h> 
using namespace std; 

class Node 
{ 
	public: 
	int key; 
	Node *left; 
	Node *right; 
	int height; 
}; 


int max(int a, int b); 

int height(Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 


int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 

Node* newNode(int key) 
{ 
	Node* node = new Node(); 
	node->key = key; 
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1; 
	return(node); 
} 

Node *rightRotate(Node *y) 
{ 
	Node *x = y->left; 
	Node *T2 = x->right; 

	//Rotation
	x->right = y; 
	y->left = T2; 

    //Updates height
	y->height = max(height(y->left), 
					height(y->right)) + 1; 
	x->height = max(height(x->left), 
					height(x->right)) + 1; 

	// Return new root 
	return x; 
} 

Node *leftRotate(Node *x) 
{ 
	Node *y = x->right; 
	Node *T2 = y->left; 

	// Perform rotation 
	y->left = x; 
	x->right = T2; 

	// Update heights 
	x->height = max(height(x->left), 
					height(x->right)) + 1; 
	y->height = max(height(y->left), 
					height(y->right)) + 1; 

	// Return new root 
	return y; 
} 

// Balance factor of node N 
int getBalance(Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
} 

Node* insert(Node* node, int key) 
{ 
	/* 1. Perform the normal BST rotation */
	if (node == NULL) 
		return(newNode(key)); 

	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	else // Equal keys not allowed 
		return node; 

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left), 
						height(node->right)); 

	/* 3. Get the balance factor of this 
		ancestor node to check whether 
		this node became unbalanced */
	int balance = getBalance(node); 

	// If this node becomes unbalanced, 
	// then there are 4 cases 

	// Left Left Case 
	if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 

	// Right Right Case 
	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 

	// Left Right Case 
	if (balance > 1 && key > node->left->key) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 

	// Right Left Case 
	if (balance < -1 && key < node->right->key) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 

	/* return the (unchanged) node pointer */
	return node; 
} 


Node * minValueNode(Node* node) 
{ 
	Node* current = node; 

	/* loop down to find the leftmost leaf */
	while (current->left != NULL) 
		current = current->left; 

	return current; 
} 


Node* deleteNode(Node* root, int key) 
{ 
	
	// STEP 1: PERFORM STANDARD BST DELETE 
	if (root == NULL) 
		return root; 

	// If the key to be deleted is smaller 
	// than the root's key, then it lies 
	// in left subtree 
	if ( key < root->key ) 
		root->left = deleteNode(root->left, key); 

	// If the key to be deleted is greater 
	// than the root's key, then it lies 
	// in right subtree 
	else if( key > root->key ) 
		root->right = deleteNode(root->right, key); 

	// if key is same as root's key, then 
	// This is the node to be deleted 
	else
	{ 
		// node with only one child or no child 
		if( (root->left == NULL) || 
			(root->right == NULL) ) 
		{ 
			Node *temp = root->left ? 
						root->left : 
						root->right; 

			// No child case 
			if (temp == NULL) 
			{ 
				temp = root; 
				root = NULL; 
			} 
			else // One child case 
			*root = *temp; // Copy the contents of 
						// the non-empty child 
			free(temp); 
		} 
		else
		{ 
			// node with two children: Get the inorder 
			// successor (smallest in the right subtree) 
			Node* temp = minValueNode(root->right); 

			// Copy the inorder successor's 
			// data to this node 
			root->key = temp->key; 

			// Delete the inorder successor 
			root->right = deleteNode(root->right, 
									temp->key); 
		} 
	} 

	// If the tree had only one node 
	// then return 
	if (root == NULL) 
	return root; 

	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE 
	root->height = 1 + max(height(root->left), 
						height(root->right)); 

	// STEP 3: GET THE BALANCE FACTOR OF 
	// THIS NODE (to check whether this 
	// node became unbalanced) 
	int balance = getBalance(root); 

	// If this node becomes unbalanced, 
	// then there are 4 cases 

	// Left Left Case 
	if (balance > 1 && 
		getBalance(root->left) >= 0) 
		return rightRotate(root); 

	// Left Right Case 
	if (balance > 1 && 
		getBalance(root->left) < 0) 
	{ 
		root->left = leftRotate(root->left); 
		return rightRotate(root); 
	} 

	// Right Right Case 
	if (balance < -1 && 
		getBalance(root->right) <= 0) 
		return leftRotate(root); 

	// Right Left Case 
	if (balance < -1 && 
		getBalance(root->right) > 0) 
	{ 
		root->right = rightRotate(root->right); 
		return leftRotate(root); 
	} 

	return root; 
} 

void printLevelOrder(Node* root)  
{  
    int h = height(root);  
    int i;  
    for (i = 1; i <= h; i++)  
        printGivenLevel(root, i);  
}  
  

void printGivenLevel(Node* root, int level)  
{  
    if (root == NULL)  
        return;  
    if (level == 1)  
        cout << root->key << " ";  
    else if (level > 1)  
    {  
        printGivenLevel(root->left, level-1);  
        printGivenLevel(root->right, level-1);  
    }  
}


int main() 
{ 
Node *root = NULL; 

      int n;
      cin>>n;

      for(int i=0;i<n;i++){
          int x;
          cin>>x;
          root = insert(root,x);
      }

	root = deleteNode(root, 10); 

	printLevelOrder(root); 

	return 0; 
} 

