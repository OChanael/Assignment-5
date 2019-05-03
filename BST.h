#include <iostream>
#include "Student.h"
#include "Faculty.h"

using namespace std;

template <class T> // TreeNode Class
class TreeNode
{
  private:

  public:
    int key;
    T* data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode();
    TreeNode(T* d, int k);
    virtual ~TreeNode();
};

template <class T>
TreeNode<T>::TreeNode()
{
  key = -1;
  data = T();
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T* d, int k)
{
  key = k;
  data = d;
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::~TreeNode()
{
  delete data;
  delete left;
  delete right;
}




template <class T> //BST Class
class BST
{
  protected:
    TreeNode<T> *root;
    int size;

  public:
    BST();
    virtual ~BST();

    bool contains(int k); //checks if contains
    T* find(int k); // like contain but different return type
    void put(TreeNode<T> *node); //insert

    TreeNode<T>* getSuccessor(TreeNode<T> *d); //*d is the node to delete
    bool erase(int k);

    T* getMin();
    T* getMax();

    void printRecursive(TreeNode<T> *node);
    void printTree();

    TreeNode<T>* getRoot();
    int getSize();
    bool isEmpty();
  };

  template <class T>
  BST<T>::BST()
  {
    root = NULL;
    size = 0;
  }

  template <class T>
  BST<T>::~BST()
  {

  }

  template <class T>
  bool BST<T>::contains(int k)
  {
    if(root == NULL)
    {
      return false;
    }

    TreeNode<T> *curr = root;

    while(curr->key != k)
    {
      if(k < curr->key)
      {
        curr = curr->left;
      }
      else
      {
        curr = curr->right;
      }

      if(curr == NULL)
      {
        return false;
      }
    }
    return true;
  }

  template <class T>
  T* BST<T>::find(int k)
  {
    if(root == NULL)
    {
      return NULL;
    }

    if(contains(k))
    {
      TreeNode<T> *curr = root;

      while(curr->key != k)
      {
        if(k < curr->key)
        {
          curr = curr->left;
        }
        else
        {
          curr = curr->right;
        }

        if(curr == NULL)
        {
          return NULL;
        }
      }
      return curr->data;
    }
    else
    {
      return NULL;
    }
  }

  template <class T>
  void BST<T>::put(TreeNode<T> *node)
  {
    if(root == NULL)
    {
      root = node;
    }
    else
    {
      TreeNode<T> *curr = root;
      TreeNode<T> *parent;

      while(true)
      {
        parent = curr;
        if(node->key < curr->key)
        {
          curr = curr->left;
          if(curr == NULL)
          {
              parent->left = node;
              break;
          }
        }
        else
        {
          if(node->key > curr->key)
          {
            curr = curr->right;
            if(curr == NULL)
            {
              parent->right = node;
              break;
            }
          }
        }
      }
    }
    ++size;
  }

  template <class T>
  TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d)
  {
    TreeNode<T> *sp = d;
    TreeNode<T> *successor = d;
    TreeNode<T> *curr = d->right;

    while(curr != NULL)
    {
      sp = successor;
      successor = curr;
      curr = curr->left;
    }

    if(successor != d->right)
    {
      sp->left = successor->right;
      successor->right = d->right;
    }

    return successor;
  }

  template <class T>
  bool BST<T>::erase(int k)
  {
    if(root == NULL)
    {
        return false;
    }

    TreeNode<T> *curr = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;

    while(curr->key != k)
    {
      parent = curr;

      if(k < curr->key)
      {
        isLeft = true;
        curr = curr->left;
      }
      else
      {
        isLeft = false;
        curr = curr->right;
      }

      if(curr == NULL)
      {
        return false;
      }
    } //found *d to delete

    if(curr->left == NULL && curr->right == NULL) // delete node with no children
    {
      if(curr == root)
      {
        root = NULL;
      }
      else if(isLeft)
      {
        parent->left = NULL;
      }
      else
      {
        parent->right = NULL;
      }
    }
    else if(curr->right == NULL) // one child to the left
    {
      if(curr == root)
      {
        root = curr->left;
      }
      else if(isLeft)
      {
        parent->left = curr->left;
      }
      else
      {
        parent->right = curr->right;
      }
    }
    else if(curr->left == NULL) //one chield to the right
    {
      if(curr == root)
      {
        root = curr->right;
      }
      else if(isLeft)
      {
        parent->left = curr->right;
      }
      else {
        parent->right = curr->right;
      }
    }
    else //two children
    {
      TreeNode<T> *successor = getSuccessor(curr);

      if(curr == root)
      {
        root = successor;
      }
      else if(isLeft)
      {
        parent->left = successor;
      }
      else
      {
        parent->right = successor;
      }
      successor->left = curr->left;
    }
    --size;
    return true;
  }

  template <class T>
  T* BST<T>::getMin()
  {
    TreeNode<T> *curr = root; //start at root

    if(root == NULL)
    {
      return NULL;
    }

    while(curr->left != NULL)
    {
      curr = curr->left;
    }

    return curr;
  }

  template <class T>
  T* BST<T>::getMax()
  {
    TreeNode<T> *curr = root;

    if(root == NULL)
    {
      return NULL;
    }

    while(curr->right != NULL)
    {
      curr = curr->right;
    }

    return curr;
  }

  template <class T>
  void BST<T>::printRecursive(TreeNode<T> *node)
  {
    if(node == NULL) {
      return;
    }

    printRecursive(node->left);
    cout << node->key << endl;
    printRecursive(node->right);
  }

  template <class T>
  void BST<T>::printTree()
  {
    printRecursive(root);
  }

  template <class T>
  TreeNode<T>* BST<T>::getRoot()
  {
    return root;
  }

  template <class T>
  int BST<T>::getSize()
  {
    return size;
  }

  template <class T>
  bool BST<T>::isEmpty()
  {
    return(size == 0);
  }
