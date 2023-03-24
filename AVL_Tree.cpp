
//#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

// An AVL tree Node

class avlTreeNode
{
	public:
	int avl_key; // key of a AVL tree
	avlTreeNode *avlleftchild; //left child of a AVL tree
	avlTreeNode *avlrightchild; //right child of a AVL tree
	int avl_height; // height of a AVL tree
};

// function to initialize AVL tree

void initialize()
{
	avlTreeNode* root =NULL;
}

// function to get the
//height of the tree
int height(avlTreeNode *avl_node)
{
	if (avl_node == NULL)
		return 0;
	return avl_node->avl_height;
}

// function to
//get maximum value of 2 numbers
int max(int num1, int num2)
{
	return (num1 > num2)? num1 : num2;
}

// function to get
//maximum value of 2 numbers

avlTreeNode* newavlTreeNode(int key)
{
	avlTreeNode* node = new avlTreeNode();
	node->avl_key = key;
	node->avlleftchild = NULL;
	node->avlrightchild = NULL;
	node->avl_height = 1; // new node is initially
					// added at leaf
	return(node);
}
// A function to right
// rotate subtree rooted with node2
avlTreeNode *rightRotate(avlTreeNode *node2)
{
	avlTreeNode *node1 = node2->avlleftchild;
	avlTreeNode *temp = node1->avlrightchild;

	// code to perform rotation
	node1->avlrightchild = node2;
	node2->avlleftchild = temp;

	// update the heights
	node2->avl_height = max(height(node2->avlleftchild),
					height(node2->avlrightchild)) + 1;
	node1->avl_height = max(height(node1->avlleftchild),
					height(node1->avlrightchild)) + 1;

	// return the new root
	return node1;
}

// A function to left
// rotate subtree rooted with node1
avlTreeNode *leftRotate(avlTreeNode *node1)
{
	avlTreeNode *node2 = node1->avlrightchild;
	avlTreeNode *temp = node2->avlleftchild;

	// Perform the rotation
	node2->avlleftchild = node1;
	node1->avlrightchild = temp;

	// Update the heights
	node1->avl_height = max(height(node1->avlleftchild),
					height(node1->avlrightchild)) + 1;
	node2->avl_height = max(height(node2->avlleftchild),
					height(node2->avlrightchild)) + 1;

	// return new root
	return node2;
}

// function to get Balance factor of Node
int getBalance(avlTreeNode *node)
{
	if (node == NULL)
		return 0;
	return height(node->avlleftchild) - height(node->avlrightchild);
}

//  function call recursively to insert a key
// in the avlTreeNode subtree
// will return the subtree new root
avlTreeNode* insert(avlTreeNode* root, int key)
{
	/* 1. Perform the normal BST insertion */
	if (root == NULL)
		return(newavlTreeNode(key));


	if (key < root->avl_key)
		root->avlleftchild = insert(root->avlleftchild, key);
	else if (key > root->avl_key)
		root->avlrightchild = insert(root->avlrightchild, key);
	else // same key values are not
	//permitted in AVL trees
		return root;

	// change the height of ancestor
	//of avlTreeNode
	root->avl_height = 1 + max(height(root->avlleftchild),
						height(root->avlrightchild));

	// Get the balance factor
	//of the following ancestor
	//logic to
	//check whether
	//this avlTreeNode became
	//unbalanced
	int balance = getBalance(root);

	// If this avlTreeNode becomes
	//unbalanced, then
	// there are 4 following cases

	// 1. Left Left Case
	if (balance > 1 && key < root->avlleftchild->avl_key)
		return rightRotate(root);

	// 2. Right Right Case
	if (balance < -1 && key > root->avlrightchild->avl_key)
		return leftRotate(root);

	// 3. Left Right Case
	if (balance > 1 && key > root->avlleftchild->avl_key)
	{
		root->avlleftchild = leftRotate(root->avlleftchild);
		return rightRotate(root);
	}

	// 4. Right Left Case
	if (balance < -1 && key < root->avlrightchild->avl_key)
	{
		root->avlrightchild = rightRotate(root->avlrightchild);
		return leftRotate(root);
	}

	// return the pointer of
	// the avlTreeNode
	return root;
}

//function to get leftmost leaf
avlTreeNode * minValueNode(avlTreeNode* node)
{
    avlTreeNode* current = node;

    // while loop to get leftmost leaf
    while (current->avlleftchild != NULL)
        current = current->avlleftchild;

    return current;
}

//function to search a particular key

avlTreeNode* search(avlTreeNode* root, int key){

	avlTreeNode* curNode = root;
	while(curNode != NULL){
		if(curNode->avl_key == key){
			return curNode;
		}
		//navigating to left side of tree
		else if(curNode->avl_key > key){
			curNode = curNode->avlleftchild;
		}
		//navigating to right side of tree
		else{
			curNode = curNode->avlrightchild;
		}
	}
	return NULL; // retuning null
	//if key not found

}
avlTreeNode* deleteNode(avlTreeNode* root, int key)
{

    // delete operation
    if (root == NULL)
        return root;

    // if key is smaller
    // when compared to root's key
    // go to the left subtree
    if ( key < root->avl_key )
        root->avlleftchild = deleteNode(root->avlleftchild, key);

				// if key is larger
				// when compared to root's key
				// go to the right subtree
    else if( key > root->avl_key )
        root->avlrightchild = deleteNode(root->avlrightchild, key);

    // if key is same, then delete it
    else
    {
        // avlTreeNode having only
				// one child or no child
        if( (root->avlleftchild == NULL) ||
            (root->avlrightchild == NULL) )
        {
          avlTreeNode *temp = root->avlleftchild ?
                         root->avlleftchild :
                         root->avlrightchild;

        // case where there is no child
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // having single child
            *root = *temp; // Coping the
                           // the single child
            free(temp); // freeing memory
        }
        else
        {
            // avlTreeNode having 2 childs
            // get smaller of avlrightchild subtree
            avlTreeNode* temp = minValueNode(root->avlrightchild);

            // put the successor's
            // contents to the avlTreeNode
            root->avl_key = temp->avl_key;

            // Delete inorder successor
            root->avlrightchild = deleteNode(root->avlrightchild,
                                     temp->avl_key);
        }
    }

    //  only single node
    // then return
    if (root == NULL)
    return root;

    // Modify HEIGHT OF THE cur NODE
    root->avl_height = 1 + max(height(root->avlleftchild),
                           height(root->avlrightchild));

    //  get the nodes balance factor
    // to check if its unbalanced
    int balance = getBalance(root);

    // imbalance causes 4 cases

    // Left Left Case
    if (balance > 1 &&
        getBalance(root->avlleftchild) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 &&
        getBalance(root->avlleftchild) < 0)
    {
        root->avlleftchild = leftRotate(root->avlleftchild);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 &&
        getBalance(root->avlrightchild) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 &&
        getBalance(root->avlrightchild) > 0)
    {
        root->avlrightchild = rightRotate(root->avlrightchild);
        return leftRotate(root);
    }

    return root;
}
vector<int> res;
//performing range search
void searchKeys(avlTreeNode* root, int k1,int k2){
    if(!root){
        return;
    }
	//store the key values onto a list
    if(root->avl_key >=k1 && root->avl_key <= k2){
        res.push_back(root->avl_key);
        searchKeys(root->avlleftchild,k1,k2);
        searchKeys(root->avlrightchild,k1,k2);
    }
    else if(root->avl_key < k1){
        searchKeys(root->avlrightchild,k1,k2);
    }
    else if(root->avl_key > k2){
        searchKeys(root->avlleftchild,k1,k2);
    }
}
// main Code

int main(int argc, char **argv)
{
	string inputfilename = argv[1];
    //initialize the avl tree
	avlTreeNode *root = NULL;
	//file creation
	std::ifstream myinputfile;
	//output file creation
	std::ofstream output("output_file.txt");
	//input file opening
	myinputfile.open(inputfilename.c_str());
	string inputStr;
	bool checkInitialize = false;
	//open input file
	if ( myinputfile.is_open() ) {
		while ( myinputfile.good() ) {
			myinputfile >> inputStr;
			//get indices
			int index1 = inputStr.find('(');
			int index2 = inputStr.find(')');
			//getting input str from file
			string temp = inputStr.substr(0,index1);
			int value,v1,v2,x;
			if(temp != "Initialize" && temp != "Search"){
				 value = stoi(inputStr.substr(index1+1,index2-index1-1));
			}
			else if(temp == "Search"){
				 x = inputStr.find(',');
				if(x==-1){
					 value = stoi(inputStr.substr(index1+1,index2-index1-1));
				}
				else{
					 v1 = stoi(inputStr.substr(index1+1,x-index1-1));
					 v2 = stoi(inputStr.substr(x+1,index2-x-1));
				}
			}
			if(temp != "Initialize" && checkInitialize == false){
                output << "No operations possible as tree is not initialized"<<endl;
                return 0;
            }
			//initialize avl tree
			if(temp == "Initialize"){
                root = NULL;
				initialize();
                checkInitialize = true;
            }
			
			//insert into avl tree
			else if(temp == "Insert"){
				root = insert(root,value);
			}
			//delete from avl tree
			else if(temp == "Delete"){
				deleteNode(root, value);
			}
			//perform search
			else if(temp == "Search" && x==-1){
					avlTreeNode* node1 = search(root,value);
					if(node1){
						//found the key
						output << node1->avl_key<<endl;
					}
					else{
						//key not found
						output <<"NULL"<<endl;
					}
			}
			//perform range search
			else if(temp == "Search" && x!=-1){
				searchKeys(root,v1,v2);
				if(res.empty()){
					//keys not found
					output <<"NULL"<<endl;
				}
				else{
					sort(res.begin(),res.end());
					for(int i=0;i<res.size()-1;i++){
					    	output<<res[i]<<",";
						//write the keys into file
					}
					output<<res[res.size()-1]<<endl;
				}
			}
		}
	}
//close output file
output.close();
	return 0;
}
