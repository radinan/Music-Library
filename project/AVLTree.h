#pragma once
#include <iostream>
#include "Song.h"
//#include "Library.h"
#include "User.h"

//added search(std::string) and helper
//and changed both search fs to find



//--AVL Tree-- 
// self-balancing BST;  |B(n)| <= 1;
// Time complexity:
//		-> insert:		O(logn) best/worst case
//		-> delete:		O(logn) best/worst case
//		-> search:		O(logn) best/worst case

//the original avl tree with all songs is always sorted by name!

class AVLTree
{
private:
	struct Node
	{
		Song data;
		Node* left = nullptr, * right = nullptr;
		size_t height = 0; //by default node is a leaf

		Node(const Song& _data) : data(_data) {}
	};
	Node* root;
private:
	Node* copy(Node* other_root,Node* curr)
	{
		//empty tree
		if (other_root == nullptr)
			return nullptr;
		//else
		curr = new Node(other_root->data); //copying node
		curr->left = copy(other_root->left, curr->left);	 //copying children
		curr->right = copy(other_root->right, curr->right);

		return curr; //returning pointer to copied tree
	}
	void del(Node* root)
	{
		//empty tree
		if (root == nullptr)
			return;
		//else
		del(root->left);	//recursively calling all children
		del(root->right);

		delete root;	    //deleting every node
	}

	//setters and getters
	Node* get_min_node(Node* root) const
	{
		// (left subtree) < root < (right subtree)
		Node* curr = root;
		while (curr != nullptr && curr->left != nullptr)
		{
			curr = curr->left;
		}
		return curr;
	}
	int get_height(Node* node) const
	{
		if (node == nullptr)
			return -1; //no node
		else
			return node->height;
	}
	void set_height(Node* node)
	{
		node->height = 1 + std::max(get_height(node->left),
			get_height(node->right));
		//if node has no children -> h = 1 + (-1) = 0
	}
	int get_balance(Node* node) const
	{
		if (node == nullptr)
			return 0;
		else
			return get_height(node->left) - get_height(node->right);
		// B(node) = h(left) - h(right)
		// B > 0 -> left heavy
		// B < 0 -> right heavy
	}

	//rotations 
	Node* left_rotate(Node* node)
	{
		Node* temp = node->right;
		node->right = temp->left;
		temp->left = node;

		//set new heights
		set_height(node);
		set_height(temp);

		return temp;
	}
	Node* right_rotate(Node* node)
	{
		Node* temp = node->left;
		node->left = temp->right;
		temp->right = node;

		//set new heights
		set_height(node);
		set_height(temp);

		return temp;
	}
	Node* left_right_rotate(Node* node)
	{
		node->left = left_rotate(node->left);
		return right_rotate(node);
	}
	Node* right_left_rotate(Node* node)
	{
		node->right = right_rotate(node->right);
		return left_rotate(node);
	}

	//helpers (main)
	Node* insert_help(Node* root, const Song& element)
	{
		//1. BST insert
		//empty/end of tree
		if (root == nullptr)
			return new Node(element);  //creating leaf
		else if (element < root->data) //go in left subtree
			root->left = insert_help(root->left, element);
		else if (element > root->data) //go in right subtree
			root->right = insert_help(root->right, element);

		//~~AVL~~:
		//2. update height and check balance
		set_height(root);
		int balance = get_balance(root);

		//3. rotate if it's unbalanced
		if (balance > 1) //left heavy
		{
			//LL
			if (element < root->left->data)
				return right_rotate(root);
			//LR
			else if (element > root->left->data)
				return left_right_rotate(root);
		}
		else if (balance < -1) //right heavy
		{
			//RR
			if (element > root->right->data)
				return left_rotate(root);
			//RL
			else if (element < root->right->data)
				return right_left_rotate(root);
		}

		return root; //returning the root node at the end
	}
	Node* find_help(Node* root, const Song& element)  //returns either the element, or nullptr
	{
		//BST search
		//empty/end of tree or found 
		if (root == nullptr || root->data == element)
			return root;
		else if (element < root->data) //go in left subtree
			find_help(root->left, element);
		else if (element > root->data) //go in right subtree
			find_help(root->right, element);
	}
	Node* remove_help(Node* root, const Song& element)
	{
		//1. BST remove
		//empty/end of tree 
		if (root == nullptr)
			return root;
		else if (element < root->data) //go in left subtree
			root->left = remove_help(root->left, element);
		else if (element > root->data) //go in right subtree
			root->right = remove_help(root->right, element);
		else //found
		{
			//no children or 1 child
			if (root->left == nullptr)
			{
				Node* save = root->right; //ptr to save the child node
				delete root;
				return save;			  //it will automatically connect with root's parent by the recursion
			}
			else if (root->right == nullptr) //analogical
			{
				Node* save = root->left;
				delete root;
				return save;
			}
			//2 children
			else
			{
				//we either get the max node from the left subtree  (could shrink the tree too much)
				//			 or the min node from the right subtree (my choice)
				//so we can save the BST property
				Node* min_right = get_min_node(root->right);			 //min node from the right subtree
				root->data = min_right->data;							 //copy its data
				root->right = remove_help(root->right, min_right->data); //find and remove the original
			}
		}

		//~~AVL~~: 
		//2. update height and check balance
		set_height(root);
		int balance = get_balance(root);
		int left_balance = get_balance(root->left);
		int right_balance = get_balance(root->right);

		//3. rotate if it's unbalanced
		if (balance > 1)
		{
			//LL
			if (left_balance >= 0)
				return right_rotate(root);
			//LR
			else // left_balance < 0
				return left_right_rotate(root);
		}
		else if (balance < -1)
		{
			//RR
			if (right_balance <= 0)
				return left_rotate(root);
			//RL
			else // right_balance > 0
				return right_left_rotate(root);
		}

		return root; //returning the root node at the end
	}
	//search by name
	Node* find_help(Node* root, const std::string& name) //overload
	{
		//BST search
		//empty/end of tree or found 
		if (root == nullptr)
			return nullptr;
		if (root->data == name)
			return root;
		else if (root->data > name) //go in left subtree
			find_help(root->left, name);
		else if (root->data < name) //go in right subtree
			find_help(root->right, name);
	}

	//helpers (other)
	Node* copy_insert_helper(Node* _root)
	{
		if (_root == nullptr)
			return nullptr;

		//Node* new_node = new Node(_root->data);
		insert(_root->data);
		copy_insert_helper(_root->left);
		copy_insert_helper(_root->right);

		return root;
	}
	void inorder_help(Node* root) const
	{
		if (root != nullptr)
		{
			inorder_help(root->left);
			std::cout << root->data << " ";
			inorder_help(root->right);
		}
	}
	void preorder_help(Node* root) const
	{
		if (root != nullptr)
		{
			std::cout << root->data << " ";
			preorder_help(root->left);
			preorder_help(root->right);
		}
	}
	const size_t sizeHelp(Node* root) const
	{
		if (root == nullptr)
			return 0;
		return 1 + sizeHelp(root->left) + sizeHelp(root->right); //number of all nodes
	}

	//helpers (playlist)
	void rating_bigger_helper(AVLTree& other, double x, Node* root)
	{
		if (root == nullptr) 
			return;
		
		rating_bigger_helper(other, x, root->left);
		if (root->data > x)
			other.insert(root->data);
		rating_bigger_helper(other, x, root->right);

	}
	void genre_plus_helper(AVLTree& other, std::string& x, Node* root)
	{
		if (root == nullptr) 
			return;

		genre_plus_helper(other, x, root->left);
		if (root->data == x)
			other.insert(root->data);
		genre_plus_helper(other, x, root->right);
	}
	void genre_minus_helper(AVLTree& other, std::string& x, Node* root)
	{
		if (root == nullptr)
			return;

		genre_minus_helper(other, x, root->left);
		if (root->data != x)
			other.insert(root->data);
		genre_minus_helper(other, x, root->right);

	}
	void year_bigger_helper(AVLTree& other, size_t x, Node* root)
	{
		if (root == nullptr)
			return;

		year_bigger_helper(other, x, root->left);
		if (root->data > x)
			other.insert(root->data);
		year_bigger_helper(other, x, root->right);
	}
	void year_smaller_helper(AVLTree& other, size_t x, Node* root)
	{
		if (root == nullptr)
			return;

		year_smaller_helper(other, x, root->left);
		if (root->data < x)
			other.insert(root->data);
		year_smaller_helper(other, x, root->right);
	}
	void year_equals_helper(AVLTree& other, size_t x, Node* root)
	{
		if (root == nullptr)
			return;

		year_equals_helper(other, x, root->left);
		if (root->data == x)
			other.insert(root->data);
		year_equals_helper(other, x, root->right);
	}

	void insert_to_list_helper(Node* root, std::list<std::string>& playlist)
	{
		if (root != nullptr)
		{
			insert_to_list_helper(root->left, playlist);
			playlist.push_back(root->data.get_name());
			insert_to_list_helper(root->right, playlist);
		}
	}

	void save_to_file_helper(std::ofstream& file, Node* root)
	{
		if (root != nullptr)
		{
			save_to_file_helper(file, root->left);
			file << root->data;
			save_to_file_helper(file, root->right);
		}
	}

public:
	AVLTree() : root(nullptr) {}
	AVLTree(const AVLTree& other) //may add 2 different constructors (one with flag?)
	{
		//root = copy(other.root);
		root = copy_insert_helper(other.root);
	}
	AVLTree& operator=(const AVLTree& other)
	{
		if (this != &other)
		{
			del(root);
			root = copy(other.root, root);
		}
		return *this;
	}
	~AVLTree()
	{
		del(root);
	}

	//main functions
	void insert(const Song& element)
	{
		root = insert_help(root, element);
	}
	Node* find(const Song& element) 
	{
		return find_help(root, element);
	}
	Node* find(const std::string& name) //overload
	{

		return find_help(root, name);
	}
	void remove(const Song& element)
	{
		root = remove_help(root, element);
	}


	//other
	void copy_insert(const AVLTree& other)
	{
		copy_insert_helper(other.root); //copying tree by insert()
	}
	void inorder() const
	{
		inorder_help(root);
	}
	void preorder() const
	{
		preorder_help(root);
	}
	const size_t size() const
	{
		return sizeHelp(root);
	}
	bool is_empty()
	{
		return root == nullptr;
	}

	//playlist funcs //filters the tree on criteria:
	void rating_bigger(double x, AVLTree& other) //works
	{
		rating_bigger_helper(other, x, root);
		*this = other;
	}
	void genre_plus(std::string& x, AVLTree& other) //works !!!WHITE SPACES!!!
	{
		genre_plus_helper(other, x, root);
		*this = other;
	}
	void genre_minus(std::string& x, AVLTree& other) //works !!!WHITE SPACES!!!
	{
		genre_minus_helper(other, x, root);
		*this = other;
	}
	void genres_fav(std::unordered_set<std::string>& genres, AVLTree& other)	//not tested after the fixes:
	{
		std::unordered_set<std::string > ::iterator it;
		for (it = genres.begin(); it != genres.end(); ++it)
		{
			std::string x = *it;
			genre_plus(x, other);
		}
	}
	void year_bigger(size_t x, AVLTree& other) //works
	{
		year_bigger_helper(other, x, root);
		*this = other;
	}
	void year_smaller(size_t x, AVLTree& other) //works
	{
		year_smaller_helper(other, x, root);
		*this = other;
	}
	void year_equals(size_t x, AVLTree& other) //works
	{
		year_equals_helper(other, x, root);
		*this = other;
	}

	void insert_to_list(std::list<std::string>& playlist)
	{
		insert_to_list_helper(root, playlist);
	}

	void save_to_file(std::ofstream& file)
	{
		save_to_file_helper(file, root);
	}


};