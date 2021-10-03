/*

bstree.h
CSCI 241 Assign11

Created by Christopher Huguelet (z1885874)
Section 2

*/

#ifndef BSTREE_H
#define BSTREE_H
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <queue>

template <class K, class V>
struct node 
{
    K key;
    V value;
    node* right;
    node* left;
    node(K k = K(), V v = V(), node* r = nullptr, node* l = nullptr)
    {
        key = k;
        value = v;
        right = r;
        left = l;
    }
};


template <class K, class V> 
class bstree
{
    private:
    node<K,V> * root = nullptr;
    size_t t_size = 0;

    public:
    bstree() = default;
    ~bstree();
    bstree(const bstree&);
    bstree& operator=(const bstree&);

    void clear();
    size_t size() const;
    size_t height() const;
    bool empty() const;

    const K& min() const;
    const K& max() const;

    bool insert(const K&, const V&);
    bool remove(const K&);

    const node<K,V>* find(const K&) const;

    void preorder() const;
    void inorder() const;
    void postorder() const;
    void level_order() const;

    private:
    size_t height(node<K,V>*) const;
    void preorder(node<K,V>*) const;
    void inorder(node<K,V>*) const;
    void postorder(node<K,V>*) const;

    node<K,V>* clone(const node<K,V>*) const;
    void destroy(node<K,V>*);
};

/*
height getter but better
*/
template <class K, class V>
size_t bstree<K,V>::height(node<K,V>* ptr) const
{
    if (ptr == nullptr) return 0;
    return 1+std::max(height(ptr->left), height(ptr->right));

}

/**
destructor
**/
template <class K, class V>
bstree<K,V>::~bstree<K,V>()
{
    clear();
}

/**
copy constructor
@param tree: source tree
**/
template <class K, class V>
bstree<K,V>::bstree(const bstree<K,V>& tree)
{
    t_size = tree.t_size;
    root = clone(tree.root);
}

/**
copy assignment
**/
template <class K, class V>
bstree<K,V>& bstree<K,V>::operator=(const bstree<K,V>& tree)
{
    if (this != &tree)
    {
        clear();
        t_size = tree.t_size;
        root = clone(tree.root);
    }
    return *this;
}

/**
clears the tree
**/
template <class K, class V>
void bstree<K,V>::clear()
{
    destroy(root);
    root = nullptr;
    t_size = 0;
}

/**
size getter
**/
template <class K, class V>
size_t bstree<K,V>::size() const
{
    return t_size;
}

/**
height getter
**/
template <class K, class V>
size_t bstree<K,V>::height() const
{
    return height(root);
}

/**
empty flag
**/
template <class K, class V>
bool bstree<K,V>::empty() const
{
    if (t_size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
minimum key value getter
**/
template <class K, class V>
const K& bstree<K,V>::min() const
{
    node<K,V>* ptr = root;
    while (ptr->left)
    {
        ptr = ptr->left;
    }
    return ptr->key;
}

/**
maximum key value getter
**/
template <class K, class V>
const K& bstree<K,V>::max() const
{
    node<K,V>* ptr = root;
    while (ptr->right)
    {
        ptr = ptr->right;
    }
    return ptr->key;
}


/**
insert new leaf node into the tree
@param key = key of new leaf
@param value = value of the new leaf
@return true if the leaf was successfully inserted, returns false if already there.
**/
template <class K, class V>
bool bstree<K,V>::insert(const K& key, const V& value)
{
    node<K,V>* ptr = root;
    node<K,V>* parent = nullptr;
    while (ptr && key != ptr->key)
    {
        parent = ptr;
        if (key < ptr->key)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr-> right;
        }
    }
    if (ptr) return false;
    node<K,V>* n = new node<K,V>(key,value);
    if (parent == nullptr) root = n;
    else
    {
        if(key < parent->key)
        {
            parent->left = n;
        }
        else
        {
            parent->right = n;
        }
    } 
    t_size++;
    return true;
}


/**
removes node from tree
@param key = node to remove
@return true if removed, return false if node does not exist.
**/
template <class K, class V>
bool bstree<K,V>::remove(const K& key)
{
    node<K,V>* ptr = root;
    node<K,V>* parent = nullptr;
    node<K,V>* replace = nullptr;
    node<K,V>* replace_parent = nullptr;
    while (ptr && key != ptr->key)
    {
        parent = ptr;
        if (key < ptr->key)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr-> right;
        }
    }
    if (ptr == nullptr) return false;
    if (ptr->left == nullptr)
    {
        replace = ptr->right;
    }
    else if (ptr->right == nullptr)
    {
        replace = ptr->left;
    }
    else
    {
        replace_parent = ptr;
        replace = ptr->left;
        while (replace->right)
        {
            replace_parent = replace;
            replace = replace->right;
        }
        if (replace_parent != ptr)
        {
            replace_parent->right = replace->left;
            replace->left = ptr->left;
        }
        replace->right = ptr->right;
    }
    if (parent == nullptr)
    {
        root = replace;
    }
    else
    {
        if (ptr->key < parent->key)
        {
            parent->left = replace;
        }
        else 
        {
            parent->right = replace;
        }
    }
    delete ptr;
    t_size--;
    return true;
}

/**
find
**/
template <class K, class V>
const node<K,V>* bstree<K,V>::find(const K& key) const
{
    node<K,V>* ptr = root;
    while (ptr && key != ptr->key)
    {
        if(key < ptr->key)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }
    return ptr;
}

/**
preorder traversal
**/
template <class K, class V>
void bstree<K,V>::preorder() const
{
    preorder(root);
}

/**
inorder traversal
**/
template <class K, class V>
void bstree<K,V>::inorder() const
{
    inorder(root);
}

/**
postorder traversal
**/
template <class K, class V>
void bstree<K,V>::postorder() const
{
    postorder(root);
}

/**
level_order traversal
**/
template <class K, class V>
void bstree<K,V>::level_order() const
{
    node<K,V>* ptr = nullptr;
    std::queue<node<K,V>*> nodes;
    if (empty()) return;
    nodes.push(root);
    while (!nodes.empty())
    {
        ptr = nodes.front();
        nodes.pop();
        std::cout << ptr->key << ": " << ptr->value << std::endl;
        if (ptr->left) nodes.push(ptr->left);
        if (ptr->right) nodes.push(ptr->right);
    }
}



/**
preorder traversal
**/
template <class K, class V>
void bstree<K,V>::preorder(node<K,V>* ptr) const
{
    if (ptr == nullptr) return;
    std::cout << ptr->key << ": " << ptr->value << std::endl;
    preorder(ptr->left);
    preorder(ptr->right);
}

/**
inorder traversal
**/
template <class K, class V>
void bstree<K,V>::inorder(node<K,V>* ptr) const
{
    if (ptr == nullptr) return;
    inorder(ptr->left);
    std::cout << ptr->key << ": " << ptr->value << std::endl;
    inorder(ptr->right);
}

/**
postorder traversal
**/
template <class K, class V>
void bstree<K,V>::postorder(node<K,V>* ptr) const
{
    if (ptr == nullptr) return;
    postorder(ptr->left);
    postorder(ptr->right);
    std::cout << ptr->key << ": " << ptr->value << std::endl;
}

/**
clones a source node
@param ptr = the node being copied
**/
template <class K, class V>
node<K,V>* bstree<K,V>::clone(const node<K,V>* ptr) const
{
    if (ptr == nullptr) return nullptr;
    node<K,V>* n = new node<K,V>(ptr->key, ptr->value);
    n->left = clone(ptr->left);
    n->right = clone(ptr->right);
    return n;
}


/**
destry the tree
**/
template <class K, class V>
void bstree<K,V>::destroy(node<K,V>* ptr)
{
    if (ptr)
    {
        destroy(ptr->left);
        destroy(ptr->right);
        delete ptr;
    }
}

#endif