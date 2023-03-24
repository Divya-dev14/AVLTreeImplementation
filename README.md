# AVLTreeImplementation


Problem Description : 

AVL tree is a self-balancing Binary Search Tree (BST) where the difference
between heights of left and right subtrees cannot be more than one for all
nodes. In this project, you’re asked to develop and test a small AVL Tree (i.e.
the entire tree resides in main memory). The data is given in the form (key)
with no duplicates, you are required to implement an AVL Tree to store the key
values. Your implementation should support the following operations : 

1. Initialize (): create a new AVL tree
2. Insert (key): insert a key into AVL tree
3. Delete (key) : delete a key from AVL tree
4. Search (key): returns the key if present in the tree else NULL
5. Search (key1, key2): returns keys that are in the range key1 ≤key ≤key2

Function Prototypes : 

1. void initialize()

2. avlTreeNode* insert( avlTreeNode* root, int key)

3. avlTreeNode* deleteNode( avlTreeNode* root, int key)

4. avlTreeNode* search( avlTreeNode* root, int key)

5. void searchKeys( avlTreeNode* root, int k1, int k2)

Additional Functions : 

1. int height(avlTreeNode *avl_node)

2. avlTreeNode* newavlTreeNode(int key)

3. avlTreeNode *rightRotate(avlTreeNode *node2)

4. avlTreeNode *leftRotate(avlTreeNode *node1)

5. int getBalance(avlTreeNode *node)


How to execute the code : 

•	Go to the project path and type "make' command.
•	Then type ./avltree input_file.txt , where avltree is the generated executable file and input_file.txt is the name of input file.
  
 Note : Make sure to mention .txt extension for input file name 
