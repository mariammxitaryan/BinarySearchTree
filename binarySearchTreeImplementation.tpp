#include "binarySearchTreeHeader.hpp"

template <typename Key, typename T, typename Compare, typename Allocator>
BinarySearchTree<Key, T, Compare, Allocator>::iterator::iterator() 
    : node_(nullptr), tree_(nullptr) {}

template <typename Key, typename T, typename Compare, typename Allocator>
BinarySearchTree<Key, T, Compare, Allocator>::iterator::iterator(typename BinarySearchTree::Node* node, cont BinarySearchTree* tree)  
    : node_(node), tree_(tree) {}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::value_type&
BinarySearchTree<Key, T, Compare, Allocator>::iterator::operator*() const {
    return node_->data;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::value_type*
BinarySearchTree<Key, T, Compare, Allocator>::iterator::operator->() const {
    return &(node_->data);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::iterator&
BinarySearchTree<Key, T, Compare, Allocator>::iterator::operator++() {
    if (!node_) {
        return *this;
    }
    if (node_->right) {
        node_ = tree_->minimum(node_->right);
    }
    else {
        typename BinarySearchTree::Node* parent = node_->parent;
        while (parent && node_ == parent->right) {
            node_ = parent;
            parent = parent->parent;
        }
        node_ = parent;
    }
    return *this;
}


template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::iterator
BinarySearchTree<Key, T, Compare, Allocator>::iterator::operator++(int) {
    iterator tmp(*this);
    ++(*this);
    return tmp;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::iterator&
BinarySearchTree<Key, T, Compare, Allocator>::iterator::operator--() {
    if (!node_) {
        node_ = tree_->maximum(tree_->root_);
    }
    else if (node_->left) {
        node_ = tree_->maximum(node_->left);
    }
    else {
        typename BinarySearchTree::Node* parent = node_->parent;
        while (parent && node_ == parent->left) {
            node_ = parent;
            parent = parent->parent;
        }
        node_ = parent;
    }
    return *this;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::iterator
BinarySearchTree<Key, T, Compare, Allocator>::iterator::operator--(int) {
    iterator temp(*this);
    --(*this);
    return temp;
}

template <typename Key, typename T, typename Compare, typename Allocator>
bool BinarySearchTree<Key, T, Compare, Allocator>::iterator::operator==(const iterator& other) const {
    return node_ == other.node_;
}

template <typename Key, typename T, typename Compare, typename Allocator>
bool BinarySearchTree<Key, T, Compare, Allocator>::iterator::operator!=(const iterator& other) const {
    return node_ != other.node_;
}

template <typename Key, typename T, typename Compare, typename Allocator>
bool BinarySearchTree<Key, T, Compare, Allocator>::iterator::operator!=(const iterator& other) const {
    return node_ != other.node_;
}

template <typename Key, typename T, typename Compare, typename Allocator>
BinarySearchTree<Key, T, Compare, Allocator>::const_iterator::const_iterator()
    : node_(nullptr), tree_(nullptr) {}

template <typename Key, typename T, typename Compare, typename Allocator>
BinarySearchTree<Key, T, Compare, Allocator>::const_iterator::const_iterator(typename BinarySearchTree::Node* node, const BinarySearchTree* tree)
    : node_(node), tree_(tree) {}

template <typename Key, typename T, typename Compare, typename Allocator>
BinarySearchTree<Key, T, Compare, Allocator>::const_iterator::const_iterator(const iterator& it)
    : node_(it.node_), tree_(it.tree_) {}

template <typename Key, typename T, typename Compare, typename Allocator>
const typename BinarySearchTree<Key, T, Compare, Allocator>::value_type&
BinarySearchTree<Key, T, Compare, Allocator>::const_iterator::operator*() const {
    return node_->data;
}

template <typename Key, typename T, typename Compare, typename Allocator>
const typename BinarySearchTree<Key, T, Compare, Allocator>::value_type*
BinarySearchTree<Key, T, Compare, Allocator>::const_iterator::operator->() const {
    return &(node_->data);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::const_iterator&
BinarySearchTree<Key, T, Compare, Allocator>::const_iterator::operator++() {
    if (!node_) return *this;
    if (node_->right)
        node_ = tree_->minimum(node_->right);
    else {
        typename BinarySearchTree::Node* parent = node_->parent;
        while (parent && node_ == parent->right) {
            node_ = parent;
            parent = parent->parent;
        }
        node_ = parent;
    }
    return *this;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::const_iterator
BinarySearchTree<Key, T, Compare, Allocator>::const_iterator::operator++(int) {
    const_iterator temp(*this);
    ++(*this);
    return temp;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::const_iterator&
BinarySearchTree<Key, T, Compare, Allocator>::const_iterator::operator--() {
    if (!node_)
        node_ = tree_->maximum(tree_->root_);
    else if (node_->left)
        node_ = tree_->maximum(node_->left);
    else {
        typename BinarySearchTree::Node* parent = node_->parent;
        while (parent && node_ == parent->left) {
            node_ = parent;
            parent = parent->parent;
        }
        node_ = parent;
    }
    return *this;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::const_iterator
BinarySearchTree<Key, T, Compare, Allocator>::const_iterator::operator--(int) {
    const_iterator temp(*this);
    --(*this);
    return temp;
}

template <typename Key, typename T, typename Compare, typename Allocator>
bool BinarySearchTree<Key, T, Compare, Allocator>::const_iterator::operator==(const const_iterator& other) const {
    return node_ == other.node_;
}

template <typename Key, typename T, typename Compare, typename Allocator>
bool BinarySearchTree<Key, T, Compare, Allocator>::const_iterator::operator!=(const const_iterator& other) const {
    return node_ != other.node_;
}

