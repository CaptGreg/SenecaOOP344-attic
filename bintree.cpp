// http://www.cprogramming.com/tutorial/lesson18.html

// GB this algo uses recursion to search and insert

#include <iostream>
using namespace std;

struct node
{
  int key_value;
  node *left;
  node *right;
};

class btree
{
    public:
        btree();
        ~btree();

        void insert(int key);
        node *search(int key);
        // void destroy_tree();

    private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        node *search(int key, node *leaf);

        node *root;
};

btree::btree()
{
  root = nullptr;
}

btree::~btree()
{
  destroy_tree(root);
}

void btree::destroy_tree(node *leaf)
{
  if(leaf != nullptr)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

void btree::insert(int key, node *leaf)
{
  if(key< leaf->key_value)
  {
    if(leaf->left != nullptr)
     insert(key, leaf->left);
    else
    {
      leaf->left = new node;
      leaf->left->key_value = key;
      leaf->left->left = nullptr;    //Sets the left child of the child node to null
      leaf->left->right = nullptr;   //Sets the right child of the child node to null
    }
  }
  else if(key >= leaf->key_value)
  {
    if(leaf->right != nullptr)
      insert(key, leaf->right);
    else
    {
      leaf->right = new node;
      leaf->right->key_value = key;
      leaf->right->left = nullptr;  //Sets the left child of the child node to null
      leaf->right->right = nullptr; //Sets the right child of the child node to null
    }
  }
}

node *btree::search(int key, node *leaf)
{
  if(leaf != nullptr)
  {
    if(key == leaf->key_value)
      return leaf;
    if(key < leaf->key_value)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return nullptr;
}

void btree::insert(int key)
{
  if(root != nullptr)
    insert(key, root);
  else
  {
    root = new node;
    root->key_value = key;
    root->left = nullptr;
    root->right = nullptr;
  }
}

node *btree::search(int key)
{
  return search(key, root);
}

int main(int argc, char**argv)
{
    btree t;
    t.insert(1);
    t.insert(3);
    t.insert(5);
    t.insert(7);

    for(int key = 1; key <= 7; key++) {
        cout << "searching for " <<key <<" returned " <<t.search(key) <<endl;
    }
}
