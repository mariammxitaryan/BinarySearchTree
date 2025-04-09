#include "binarySearchTreeHeader.hpp"

// ================================================================
// Iterator Class: iterator
// ================================================================

/**
 * @brief Default constructor for iterator.
 *
 * Initializes an iterator to nullptr.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
BinarySearchTree<Key, T, Compare, Allocator>::iterator::iterator() 
    : node_(nullptr), tree_(nullptr) {}

/**
 * @brief Parameterized constructor for iterator.
 *
 * @param node Pointer to the current node.
 * @param tree Pointer to the BinarySearchTree instance.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
BinarySearchTree<Key, T, Compare, Allocator>::iterator::iterator(typename BinarySearchTree::Node* node, const BinarySearchTree* tree)  
    : node_(node), tree_(tree) {}

/**
 * @brief Dereference operator.
 *
 * Returns a reference to the data stored in the current node.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::value_type&
BinarySearchTree<Key, T, Compare, Allocator>::iterator::operator*() const {
    return node_->data;
}

/**
 * @brief Member access operator.
 *
 * Returns a pointer to the data stored in the current node.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::value_type*
BinarySearchTree<Key, T, Compare, Allocator>::iterator::operator->() const {
    return &(node_->data);
}

/**
 * @brief Pre-increment operator.
 *
 * Advances the iterator to the in-order successor.
 *
 * @return Reference to the updated iterator.
 */
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

/**
 * @brief Post-increment operator.
 *
 * Advances the iterator to the in-order successor but returns the iterator state before increment.
 *
 * @return Iterator before the increment.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::iterator
BinarySearchTree<Key, T, Compare, Allocator>::iterator::operator++(int) {
    iterator tmp(*this);
    ++(*this);
    return tmp;
}

/**
 * @brief Pre-decrement operator.
 *
 * Moves the iterator to the in-order predecessor.
 *
 * @return Reference to the updated iterator.
 */
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

/**
 * @brief Post-decrement operator.
 *
 * Moves the iterator to the in-order predecessor but returns the iterator state before decrement.
 *
 * @return Iterator before the decrement.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::iterator
BinarySearchTree<Key, T, Compare, Allocator>::iterator::operator--(int) {
    iterator temp(*this);
    --(*this);
    return temp;
}

/**
 * @brief Equality operator for iterator.
 *
 * @param other Another iterator to compare.
 * @return True if both iterators point to the same node.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
bool BinarySearchTree<Key, T, Compare, Allocator>::iterator::operator==(const iterator& other) const {
    return node_ == other.node_;
}

/**
 * @brief Inequality operator for iterator.
 *
 * @param other Another iterator to compare.
 * @return True if the iterators do not point to the same node.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
bool BinarySearchTree<Key, T, Compare, Allocator>::iterator::operator!=(const iterator& other) const {
    return node_ != other.node_;
}

// ================================================================
// Iterator Class: const_iterator
// ================================================================

/**
 * @brief Default constructor for const_iterator.
 *
 * Initializes the const_iterator to nullptr.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
BinarySearchTree<Key, T, Compare, Allocator>::const_iterator::const_iterator()
    : node_(nullptr), tree_(nullptr) {}

/**
 * @brief Parameterized constructor for const_iterator.
 *
 * @param node Pointer to the current node.
 * @param tree Pointer to the BinarySearchTree instance.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
BinarySearchTree<Key, T, Compare, Allocator>::const_iterator::const_iterator(typename BinarySearchTree::Node* node, const BinarySearchTree* tree)
    : node_(node), tree_(tree) {}

/**
 * @brief Conversion constructor from iterator to const_iterator.
 *
 * @param it Iterator instance.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
BinarySearchTree<Key, T, Compare, Allocator>::const_iterator::const_iterator(const iterator& it)
    : node_(it.node_), tree_(it.tree_) {}

/**
 * @brief Dereference operator for const_iterator.
 *
 * Returns a constant reference to the data stored in the node.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
const typename BinarySearchTree<Key, T, Compare, Allocator>::value_type&
BinarySearchTree<Key, T, Compare, Allocator>::const_iterator::operator*() const {
    return node_->data;
}

/**
 * @brief Member access operator for const_iterator.
 *
 * Returns a pointer to the constant data in the node.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
const typename BinarySearchTree<Key, T, Compare, Allocator>::value_type*
BinarySearchTree<Key, T, Compare, Allocator>::const_iterator::operator->() const {
    return &(node_->data);
}

/**
 * @brief Pre-increment operator for const_iterator.
 *
 * Advances the iterator to the in-order successor.
 *
 * @return Reference to the updated const_iterator.
 */
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

/**
 * @brief Post-increment operator for const_iterator.
 *
 * Advances the iterator and returns the state before increment.
 *
 * @return const_iterator before the increment.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::const_iterator
BinarySearchTree<Key, T, Compare, Allocator>::const_iterator::operator++(int) {
    const_iterator temp(*this);
    ++(*this);
    return temp;
}

/**
 * @brief Pre-decrement operator for const_iterator.
 *
 * Moves the iterator to the in-order predecessor.
 *
 * @return Reference to the updated const_iterator.
 */
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

/**
 * @brief Post-decrement operator for const_iterator.
 *
 * Moves the iterator to the in-order predecessor and returns the previous state.
 *
 * @return const_iterator before the decrement.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::const_iterator
BinarySearchTree<Key, T, Compare, Allocator>::const_iterator::operator--(int) {
    const_iterator temp(*this);
    --(*this);
    return temp;
}

/**
 * @brief Equality operator for const_iterator.
 *
 * @param other The other const_iterator to compare.
 * @return true if both iterators point to the same node.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
bool BinarySearchTree<Key, T, Compare, Allocator>::const_iterator::operator==(const const_iterator& other) const {
    return node_ == other.node_;
}

/**
 * @brief Inequality operator for const_iterator.
 *
 * @param other The other const_iterator to compare.
 * @return true if the iterators do not point to the same node.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
bool BinarySearchTree<Key, T, Compare, Allocator>::const_iterator::operator!=(const const_iterator& other) const {
    return node_ != other.node_;
}

// ================================================================
// BinarySearchTree Constructors, Destructor, and Assignment Operators
// ================================================================

/**
 * @brief Default constructor.
 *
 * Constructs an empty BinarySearchTree.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
BinarySearchTree<Key, T, Compare, Allocator>::BinarySearchTree() 
    : root_(nullptr), size_(0), comp_(Compare()), alloc_(Allocator()) {}

/**
 * @brief Parameterized constructor.
 *
 * Constructs an empty BinarySearchTree with the given key comparison object and allocator.
 *
 * @param comp The key comparison object.
 * @param alloc The allocator.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
BinarySearchTree<Key, T, Compare, Allocator>::BinarySearchTree(const key_compare& comp, const allocator_type& alloc)
    : root_(nullptr), size_(0), comp_(comp), alloc_(alloc) {}

/**
 * @brief Helper function to recursively copy a tree.
 *
 * Recursively copies the tree from other_node to create a new subtree.
 *
 * @param other_node The node to copy from.
 * @param parent The parent pointer for the new node.
 * @return Pointer to the newly created node.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::Node*
BinarySearchTree<Key, T, Compare, Allocator>::copy_tree(Node* other_node, Node* parent) {
    if (!other_node) {
        return nullptr;
    }
    Node* new_node = new Node(other_node->data);
    new_node->parent = parent;
    new_node->left = copy_tree(other_node->left, new_node);
    new_node->right = copy_tree(other_node->right, new_node);
    return new_node;
}

/**
 * @brief Copy constructor.
 *
 * Constructs a new BinarySearchTree by performing a deep copy of another tree.
 *
 * @param other The tree to copy.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
BinarySearchTree<Key, T, Compare, Allocator>::BinarySearchTree(const BinarySearchTree& other) 
    : root_(copy_tree(other.root_, nullptr)),
      size_(other.size_),
      comp_(other.comp_),
      alloc_(other.alloc_) {}

/**
 * @brief Move constructor.
 *
 * Constructs a new BinarySearchTree by moving resources from another tree.
 *
 * @param other The tree to move from.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
BinarySearchTree<Key, T, Compare, Allocator>::BinarySearchTree(BinarySearchTree&& other) noexcept
    : root_(other.root_), size_(other.size_), comp_(other.comp_), alloc_(other.alloc_) {
    other.root_ = nullptr;
    other.size_ = 0;
}

/**
 * @brief Destructor.
 *
 * Destroys the BinarySearchTree and deallocates all its nodes.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
BinarySearchTree<Key, T, Compare, Allocator>::~BinarySearchTree() {
    clear();
}

/**
 * @brief Copy assignment operator.
 *
 * Assigns one BinarySearchTree to another using deep copy.
 *
 * @param other The tree to copy from.
 * @return Reference to this tree.
 */
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

/**
 * @brief Move assignment operator.
 *
 * Moves the resources from one BinarySearchTree to another.
 *
 * @param other The tree to move from.
 * @return Reference to this tree.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
BinarySearchTree<Key, T, Compare, Allocator>& 
BinarySearchTree<Key, T, Compare, Allocator>::operator=(BinarySearchTree&& other) noexcept {
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

// ================================================================
// BinarySearchTree Capacity Functions
// ================================================================

/**
 * @brief Checks if the tree is empty.
 *
 * @return true if the tree has no elements.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
bool BinarySearchTree<Key, T, Compare, Allocator>::empty() const noexcept {
    return size_ == 0;
}

/**
 * @brief Returns the number of elements in the tree.
 *
 * @return Number of nodes.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::size_type 
BinarySearchTree<Key, T, Compare, Allocator>::size() const noexcept {
    return size_;
}

/**
 * @brief Returns the maximum possible number of elements.
 *
 * @return Maximum size based on the allocator.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::size_type 
BinarySearchTree<Key, T, Compare, Allocator>::max_size() const noexcept {
    return Allocator().mac_size();
    // Note: You might have meant max_size() here. Ensure spelling is correct.
}

// ================================================================
// BinarySearchTree Iterator Functions
// ================================================================

/**
 * @brief Returns an iterator to the first (smallest) element.
 *
 * @return Iterator pointing to the minimum node.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::iterator
BinarySearchTree<Key, T, Compare, Allocator>::begin() noexcept {
    return iterator(minimum(root_), this);
}

/**
 * @brief Returns a const_iterator to the first (smallest) element.
 *
 * @return Const_iterator pointing to the minimum node.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::const_iterator
BinarySearchTree<Key, T, Compare, Allocator>::cbegin() const noexcept {
    return const_iterator(minimum(root_), this);
}

/**
 * @brief Returns an iterator to one past the last element.
 *
 * @return Iterator representing the end.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::iterator
BinarySearchTree<Key, T, Compare, Allocator>::end() noexcept {
    return iterator(nullptr, this);
}

/**
 * @brief Returns a const_iterator to one past the last element.
 *
 * @return Const_iterator representing the end.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::const_iterator
BinarySearchTree<Key, T, Compare, Allocator>::cend() const noexcept {
    return const_iterator(nullptr, this);
}

/**
 * @brief Returns a reverse_iterator to the beginning of the reversed sequence.
 *
 * @return Reverse_iterator to the reverse beginning.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::reverse_iterator
BinarySearchTree<Key, T, Compare, Allocator>::rbegin() noexcept {
    return reverse_iterator(end());
}

/**
 * @brief Returns a const_reverse_iterator to the beginning of the reversed sequence.
 *
 * @return Const_reverse_iterator to the reverse beginning.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::const_reverse_iterator
BinarySearchTree<Key, T, Compare, Allocator>::crbegin() const noexcept {
    return const_reverse_iterator(cend());
}

/**
 * @brief Returns a reverse_iterator to the end of the reversed sequence.
 *
 * @return Reverse_iterator to the reverse end.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::reverse_iterator
BinarySearchTree<Key, T, Compare, Allocator>::rend() noexcept {
    return reverse_iterator(begin());
}

/**
 * @brief Returns a const_reverse_iterator to the end of the reversed sequence.
 *
 * @return Const_reverse_iterator to the reverse end.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::const_reverse_iterator
BinarySearchTree<Key, T, Compare, Allocator>::crend() const noexcept {
    return const_reverse_iterator(cbegin());
}

// ================================================================
// BinarySearchTree Modifier Functions
// ================================================================

/**
 * @brief Clears the tree.
 *
 * Deletes all nodes, leaving the tree empty.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
void BinarySearchTree<Key, T, Compare, Allocator>::clear() noexcept {
    destroy(root_);
    root_ = nullptr;
    size_ = 0;
}

/**
 * @brief Inserts an element into the tree.
 *
 * @param value The key-value pair to insert.
 * @return A pair containing the iterator to the inserted node (or existing node) and a boolean indicating success.
 */
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

/**
 * @brief Inserts an element into the tree using a hint iterator.
 *
 * The hint is ignored in this implementation.
 *
 * @param hint Iterator hint (unused).
 * @param value The key-value pair to insert.
 * @return Iterator to the inserted element.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::iterator
BinarySearchTree<Key, T, Compare, Allocator>::insert(iterator hint, const value_type& value) {
    // The hint parameter is not used.
    return insert(value).first;
}

/**
 * @brief Inserts a range of elements into the tree.
 *
 * Iterates over the range and inserts each element.
 *
 * @param first Iterator to the start of the range.
 * @param last Iterator to one past the end of the range.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
template <typename InputIterator>
void BinarySearchTree<Key, T, Compare, Allocator>::insert(InputIterator first, InputIterator last) {
    for ( ; first != last; ++first)
        insert(*first);
}

/**
 * @brief Erases an element from the tree by iterator.
 *
 * @param pos Iterator pointing to the element to erase.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
void BinarySearchTree<Key, T, Compare, Allocator>::erase(iterator pos) {
    if (pos == end()) {
        return;
    }
    erase(pos.node_->data.first);
}

/**
 * @brief Erases an element from the tree by key.
 *
 * Deletes the node associated with the key.
 *
 * @param key The key of the element to erase.
 * @return 1 if the element was erased; 0 otherwise.
 */
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

/**
 * @brief Erases a range of elements from the tree.
 *
 * @param first Iterator to the start of the range.
 * @param last Iterator to one past the end of the range.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
void BinarySearchTree<Key, T, Compare, Allocator>::erase(iterator first, iterator last) {
    while (first != last) {
        iterator tmp = first;
        ++first;
        erase(tmp);
    }
}

// ================================================================
// BinarySearchTree Lookup Functions
// ================================================================

/**
 * @brief Finds an element by key.
 *
 * @param key The key to find.
 * @return Iterator to the found element or end() if not found.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::iterator 
BinarySearchTree<Key, T, Compare, Allocator>::find(const key_type& key) {
    return iterator(find_node(key), this);
}

/**
 * @brief Finds an element by key (const version).
 *
 * @param key The key to find.
 * @return const_iterator to the found element or cend() if not found.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::const_iterator 
BinarySearchTree<Key, T, Compare, Allocator>::cfind(const key_type& key) const {
    return const_iterator(find_node(key), this);
}

/**
 * @brief Counts the number of elements matching a key.
 *
 * For unique-key trees, returns 1 if the key exists, otherwise 0.
 *
 * @param key The key to count.
 * @return Count (0 or 1).
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::size_type
BinarySearchTree<Key, T, Compare, Allocator>::count(const key_type& key) const {
    return find_node(key) ? 1 : 0;
}

/**
 * @brief Finds the lower bound for a key.
 *
 * Returns the first element that is not less than the given key.
 *
 * @param key The key to search for.
 * @return Iterator to the lower bound.
 */
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

/**
 * @brief Finds the lower bound for a key (const version).
 *
 * @param key The key to search for.
 * @return const_iterator to the lower bound.
 */
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

/**
 * @brief Finds the upper bound for a key.
 *
 * Returns the first element that is greater than the given key.
 *
 * @param key The key to search for.
 * @return Iterator to the upper bound.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::iterator 
BinarySearchTree<Key, T, Compare, Allocator>::upper_bound(const key_type& key) {
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

/**
 * @brief Finds the upper bound for a key (const version).
 *
 * @param key The key to search for.
 * @return const_iterator to the upper bound.
 */
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
    return const_iterator(candidate, this);
}

/**
 * @brief Returns the equal range for a given key.
 *
 * For a unique-key BST, this returns a pair of iterators where the first is the lower bound
 * and the second is the upper bound.
 *
 * @param key The key to search for.
 * @return Pair of iterators (lower bound, upper bound).
 */
template <typename Key, typename T, typename Compare, typename Allocator>
std::pair<typename BinarySearchTree<Key, T, Compare, Allocator>::iterator, 
          typename BinarySearchTree<Key, T, Compare, Allocator>::iterator>
BinarySearchTree<Key, T, Compare, Allocator>::equal_range(const key_type& key) {
    return std::make_pair(lower_bound(key), upper_bound(key));
}

/**
 * @brief Returns the equal range for a given key (const version).
 *
 * @param key The key to search for.
 * @return Pair of const_iterators (lower bound, upper bound).
 */
template <typename Key, typename T, typename Compare, typename Allocator>
std::pair<typename BinarySearchTree<Key, T, Compare, Allocator>::const_iterator, 
          typename BinarySearchTree<Key, T, Compare, Allocator>::const_iterator>
BinarySearchTree<Key, T, Compare, Allocator>::cequal_range(const key_type& key) const {
    return std::make_pair(clower_bound(key), cupper_bound(key));
}

// ================================================================
// BinarySearchTree Observer Functions
// ================================================================

/**
 * @brief Retrieves the key comparison object.
 *
 * @return The key_compare object.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::key_compare
BinarySearchTree<Key, T, Compare, Allocator>::key_comp() const {
    return comp_;
}

/**
 * @brief Retrieves the value comparison object.
 *
 * @return The value_compare object.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::value_compare 
BinarySearchTree<Key, T, Compare, Allocator>::value_comp() const {
    return value_compare(comp_);
}

// ================================================================
// BinarySearchTree Private Helper Functions
// ================================================================

/**
 * @brief Recursively deallocates all nodes in the subtree.
 *
 * @param node The root of the subtree to destroy.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
void BinarySearchTree<Key, T, Compare, Allocator>::destroy(Node* node) {
    if (node) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

/**
 * @brief Finds the minimum node in the subtree.
 *
 * @param node The root of the subtree.
 * @return Pointer to the node with the minimum key.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::Node*
BinarySearchTree<Key, T, Compare, Allocator>::minimum(Node* node) const {
    if (!node) return nullptr;
    while (node->left)
        node = node->left;
    return node;
}

/**
 * @brief Finds the maximum node in the subtree.
 *
 * @param node The root of the subtree.
 * @return Pointer to the node with the maximum key.
 */
template <typename Key, typename T, typename Compare, typename Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::Node*
BinarySearchTree<Key, T, Compare, Allocator>::maximum(Node* node) const {
    if (!node) return nullptr;
    while (node->right)
        node = node->right;
    return node;
}

/**
 * @brief Searches for a node with the given key.
 *
 * @param key The key to search for.
 * @return Pointer to the node if found; nullptr otherwise.
 */
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

/**
 * @brief Replaces one subtree as a child of its parent with another subtree.
 *
 * @param u The node to replace.
 * @param v The node to replace it with.
 */
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

/**
 * @brief Removes a node from the tree, preserving BST properties.
 *
 * Depending on the number of children, this function replaces the node appropriately.
 *
 * @param z The node to remove.
 */
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
