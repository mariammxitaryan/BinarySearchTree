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

template <typename Key, typename T, typename Compare, typename Allocator>
BinarySearchTree<Key, T, Compare, Allocator>::BinarySearchTree() 
    : root_(nullptr), size_(0), comp_(Compare()), alloc_(Allocator()) {}

template <typename Key, typename T, typename Compare, typename Allocator>
BinarySearchTree<Key, T, Compare, Allocator>::BinarySearchTree(const key_compare& comp, const allocator_type& alloc)
    : root_(nullptr), size_(0), comp_(comp), alloc_(alloc) {}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::Node*
BinarySearchTree<Key, T, Compare, Allocator>::copy_tree(Node* other_noe, Node* parent) {
    if (!other_node) {
        return nullptr;
    }
    Node* new_node = new Node(other_node->data);
    new_node->parent = parent;
    new_node->left = copy_tree(other_node->left, new_node);
    new_node->right = copy_tree(other_node->right, new_node);
    return new_node;
}

template <typename Key, typename T, typename Compare, typename Allocator>
BinarySearchTree<Key, T, Compare, Allocator>::BinarySearchTree(const BinarySearchTree& other) 
    : root_(copy_tree(other.root_, nullptr)),
      size(other.size_),
      comp_(other.comp_),
      alloc_(other.alloc_) {}

template <typename Key, typename T, typename Compare, typename Allocator>
BinarySearchTree<Key, T, Compare, Allocator>::BinarySearchTree(const BinarySearchTree&& other) noexcept
    : root_(other.root_), size(other.size_), comp_(other.comp_), alloc_(other.alloc_) {
    other.root_ = nullptr;
    other.size_ = 0;
}

template <typename Key, typename T, typename Compare, typename Allocator>
BinarySearchTree<Key, T, Compare, Allocator>::~BinarySearchTree() {
    clear();
}

template <typename Key, typename T, typename Compare, typename Allocator>
BinarySearchTree<Key, T, Compare, Allocator>& 
BinarySearchTree<Key, T, Compare, Allocator>::operator=(const BinarySearchTree& other) {
    if (this != &other) {
        clear();
        root_ = copy_tree(other.root_, nullptr);
        size_ = other.size_;
        comp_ = other.comp_;
        alloc_ = other.alloc_;
    }
    return *this;
}

template <typename Key, typename T, typename Compare, typename Allocator>
BinarySearchTree<Key, T, Compare, Allocator>& 
BinarySearchTree<Key, T, Compare, Allocator>::operator=(const BinarySearchTree&& other) noexcept {
    if (this != &other) {
        clear();
        root_ = other.root_;
        size_ = other.size_;
        comp_ = other.comp_;
        alloc_ = other.alloc_;
        other.root_ = nullptr;
        other.size_ = 0;
    }
    return *this;
}

template <typename Key, typename T, typename Compare, typename Allocator>
bool BinarySearchTree<Key, T, Compare, Allocator>::empty() const noexcept {
    return size_ == 0;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::size_type 
BinarySearchTree<Key, T, Compare, Allocator>::size() const noexcept {
    return size_;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::size_type 
BinarySearchTree<Key, T, Compare, Allocator>::max_size() const noexcept {
    return Allocator().mac_size();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::iterator
BinarySearchTree<Key, T, Compare, Allocator>::begin() noexcept {
    return iterator(minimum(root_), this);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::const_iterator
BinarySearchTree<Key, T, Compare, Allocator>::cbegin() const noexcept {
    return const_iterator(minimum(root_), this);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::iterator
BinarySearchTree<Key, T, Compare, Allocator>::end() noexcept {
    return iterator(nullptr, this);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::const_iterator
BinarySearchTree<Key, T, Compare, Allocator>::cend() const noexcept {
    return const_iterator(nullptr, this);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::reverse_iterator
BinarySearchTree<Key, T, Compare, Allocator>::rbegin() noexcept {
    return reverse_iterator(end());
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::const_reverse_iterator
BinarySearchTree<Key, T, Compare, Allocator>::crbegin() const noexcept {
    return const_reverse_iterator(cend());
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::reverse_iterator
BinarySearchTree<Key, T, Compare, Allocator>::rend() noexcept {
    return reverse_iterator(begin());
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::const_reverse_iterator
BinarySearchTree<Key, T, Compare, Allocator>::crend() const noexcept {
    return const_reverse_iterator(cbegin());
}

template <typename Key, typename T, typename Compare, typename Allocator>
void BinarySearchTree<Key, T, Compare, Allocator>::clear() noexcept {
    distroy(root_);
    root_ = nullptr;
    size_ = 0;
}

template <typename Key, typename T, typename Compare, typename Allocator>
std::pair<typename BinarySearchTree<Key, T, Compare, Allocator>::iterator, bool>
BinarySearchTree<Key, T, Compare, Allocator>::insert(const value_type& value) {
    Node* parent = nullptr;
    Node** curr = &root_;
    while (*curr) {
        parent = *curr;
        if (comp_(value.first, (*curr)->data.first)) {
            curr = &((*curr)->left);
        }
        else if (comp_((*curr)->data.first, value.first)) {
            curr = &((*curr)->right);
        }
        else {
            return std::make_pair(iterator(*curr, this), false);
        }
    }
    Node* new_node = new Node(value);
    new_node->parent = parent;
    *curr = new_node;
    ++size_;
    return std::make_pair(iterator(new_node, this), true);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::iterator
BinarySearchTree<Key, T, Compare, Allocator>::insert(const value_type& value) {
    Node* parent = nullptr;
    Node** curr = &root_;
    while (*curr) {
        parent = *curr;
        if (comp_(value.first, (*curr)->data.first)) {
            curr = &((*curr)->left);
        }
        else if (comp_((*curr)->data.first, value.first)) {
            curr = &((*curr)->right);
        }
        else {
            return std::make_pair(iterator(*curr, this), false);
        }
    }
    Node* new_node = new Node(value);
    new_node->parent = parent;
    *curr = new_node;
    ++size_;
    return std::make_pair(iterator(new_node, this), true);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::iterator
BinarySearchTree<Key, T, Compare, Allocator>::insert(iterator hint, const value_type& value) {
    insert(value).first;
}

template <typename Key, typename T, typename Compare, typename Allocator>
template <typename InputIterator>
void BinarySearchTree<Key, T, Compare, Allocator>::insert(InputIterator first, InputIterator last) {
    for ( ; first != last; ++first)
        insert(*first);
}

template <typename Key, typename T, typename Compare, typename Allocator>
void BinarySearchTree<Key, T, Compare, Allocator>::erase(iterator pos) {
    if (pos == end()) {
        return;
    }
    erase(pos.node_->data.first);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::size_type 
BinarySearchTree<Key, T, Compare, Allocator>::erase(const key_type& key) {
    Node* node = find_node(key);
    if (!node) {
        return 0;
    }
    erase_node(node);
    --size_;
    return 1;
}

template <typename Key, typename T, typename Compare, typename Allocator>
void BinarySearchTree<Key, T, Compare, Allocator>::erase(iterator first, iterator last) {
    while (first != last) {
        iterator tmp = first;
        ++first;
        erase(tmp);
    }
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::iterator 
BinarySearchTree<Key, T, Compare, Allocator>::find(const key_type& key) {
    return iterator(find_node(key), this);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::const_iterator 
BinarySearchTree<Key, T, Compare, Allocator>::cfind(const key_type& key) const {
    return const_iterator(find_node(key), this);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::size_type
BinarySearchTree<Key, T, Compare, Allocator>::count(const key_type& key) const {
    return find_node(key) ? 1 : 0;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::iterator
BinarySearchTree<Key, T, Compare, Allocator>::lower_bound(const key_type& key) {
    Node* curr = root_;
    Node* candidate = nullptr;
    while (curr) {
        if (!comp_(curr->data.first, key)) {
            candidate = curr;
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
    return iterator(candidate, this);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::const_iterator 
BinarySearchTree<Key, T, Compare, Allocator>::clower_bound(const key_type& key) const {
    Node* curr = root_;
    Node* candidate = nullptr;
    while (curr) {
        if (!comp_(curr->data.first, key)) {
            candidate = curr;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return const_iterator(candidate, this);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::const_iterator 
BinarySearchTree<Key, T, Compare, Allocator>::upper_bound(const key_type& key) const {
    Node* curr = root_;
    Node* candidate = nullptr;
    while (curr) {
        if (comp_(key, curr->data.first)) {
            candidate = curr;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return iterator(candidate, this);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::const_iterator 
BinarySearchTree<Key, T, Compare, Allocator>::cupper_bound(const key_type& key) const {
    Node* curr = root_;
    Node* candidate = nullptr;
    while (curr) {
        if (comp_(key, curr->data.first)) {
            candidate = curr;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return iterator(candidate, this);
}

template <typename Key, typename T, typename Compare, typename Allocator>
std::pair<typename BinarySearchTree<Key, T, Compare, Allocator>::iterator, 
          typename BinarySearchTree<Key, T, Compare, Allocator>::iterator>
BinarySearchTree<Key, T, Compare, Allocator>::equal_range(const key_type& key) {
    return std::make_pair(lower_bound(key), upper_bound(key));
}

template <typename Key, typename T, typename Compare, typename Allocator>
std::pair<typename BinarySearchTree<Key, T, Compare, Allocator>::const_iterator, 
          typename BinarySearchTree<Key, T, Compare, Allocator>::const_iterator>
BinarySearchTree<Key, T, Compare, Allocator>::cequal_range(const key_type& key) const {
    return std::make_pair(lower_bound(key), upper_bound(key));
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::key_compare
BinarySearchTree<Key, T, Compare, Allocator>::key_comp() const {
    return comp_;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::value_compare 
BinarySearchTree<Key, T, Compare, Allocator>::value_comp() const {
    return value_compare(comp_);
}

template <typename Key, typename T, typename Compare, typename Allocator>
void BinarySearchTree<Key, T, Compare, Allocator>::destroy(Node* node) {
    if (node) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::Node*
BinarySearchTree<Key, T, Compare, Allocator>::minimum(Node* node) const {
    if (!node) return nullptr;
    while (node->left)
        node = node->left;
    return node;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::Node*
BinarySearchTree<Key, T, Compare, Allocator>::maximum(Node* node) const {
    if (!node) return nullptr;
    while (node->right)
        node = node->right;
    return node;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::Node*
BinarySearchTree<Key, T, Compare, Allocator>::find_node(const key_type& key) const {
    Node* curr = root_;
    while (curr) {
        if (comp_(key, curr->data.first))
            curr = curr->left;
        else if (comp_(curr->data.first, key))
            curr = curr->right;
        else
            return curr;
    }
    return nullptr;
}

template <typename Key, typename T, typename Compare, typename Allocator>
void BinarySearchTree<Key, T, Compare, Allocator>::transplant(Node* u, Node* v) {
    if (!u->parent)
        root_ = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if (v)
        v->parent = u->parent;
}

template <typename Key, typename T, typename Compare, typename Allocator>
void BinarySearchTree<Key, T, Compare, Allocator>::erase_node(Node* z) {
    if (!z->left) {
        transplant(z, z->right);
    } else if (!z->right) {
        transplant(z, z->left);
    } else {
        Node* y = minimum(z->right);
        if (y->parent != z) {
            transplant(y, y->right);
            y->right = z->right;
            if (y->right)
                y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        if (y->left)
            y->left->parent = y;
    }
    delete z;
}