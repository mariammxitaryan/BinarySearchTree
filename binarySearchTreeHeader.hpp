#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <utility>    
#include <cstddef>   
#include <functional>  
#include <iterator>     
#include <stack>
#include <memory>

template <
    typename Key, 
    typename T, 
    typename Compare = std::less<Key>, 
    typename Allocator = std::allocator<std::pair<const Key, T>>
>
class BinarySearchTree {
    struct Node;
public:
    using key_type = Key;
    using mapped_type = T;
    using value_type = std::pair<const Key, T>;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using key_compare = Compare;
    using value_compare = std::function<bool(const value_type&, const value_type&)>;
    using allocator_type = Allocator;
    
    class iterator;
    class const_iterator;
    
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    class iterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type        = BinarySearchTree::value_type;
        using difference_type   = std::ptrdiff_t;
        using pointer           = value_type*;
        using reference         = value_type&;

        iterator();
        iterator(typename BinarySearchTree::Node* node, const BinarySearchTree* tree);
        value_type& operator*() const;
        value_type* operator->() const;
        iterator& operator++();
        iterator operator++(int);
        iterator& operator--();
        iterator operator--(int);
        bool operator==(const iterator& other) const;
        bool operator!=(const iterator& other) const;
    private:
        typename BinarySearchTree::Node* node_;
        const BinarySearchTree* tree_;
        friend class BinarySearchTree;
        friend class const_iterator;
    };

    class const_iterator : public std::iterator<std::bidirectional_iterator_tag, const value_type> {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type        = BinarySearchTree::value_type;
        using difference_type   = std::ptrdiff_t;
        using pointer           = const value_type*;
        using reference         = const value_type&;
        
        const_iterator();
        const_iterator(typename BinarySearchTree::Node* node, const BinarySearchTree* tree);
        const_iterator(const iterator& it);
        const value_type& operator*() const;
        const value_type* operator->() const;
        const_iterator& operator++();
        const_iterator operator++(int);
        const_iterator& operator--();
        const_iterator operator--(int);
        bool operator==(const const_iterator& other) const;
        bool operator!=(const const_iterator& other) const;
    private:
        typename BinarySearchTree::Node* node_;
        const BinarySearchTree* tree_;
        friend class BinarySearchTree;
    };

    BinarySearchTree();
    explicit BinarySearchTree(const key_compare& comp, const allocator_type& alloc = allocator_type());
    BinarySearchTree(const BinarySearchTree& other);
    BinarySearchTree(BinarySearchTree&& other) noexcept;
    ~BinarySearchTree();
    BinarySearchTree& operator=(const BinarySearchTree& other);
    BinarySearchTree& operator=(BinarySearchTree&& other) noexcept;

    bool empty() const noexcept;
    size_type size() const noexcept;
    size_type max_size() const noexcept;

    iterator begin() noexcept;
    const_iterator cbegin() const noexcept;
    iterator end() noexcept;
    const_iterator cend() const noexcept;
    reverse_iterator rbegin() noexcept;
    const_reverse_iterator crbegin() const noexcept;
    reverse_iterator rend() noexcept;
    const_reverse_iterator crend() const noexcept;

    void clear() noexcept;
    std::pair<iterator, bool> insert(const value_type& value);
    iterator insert(iterator hint, const value_type& value);

    template <typename InputIterator>
    void insert(InputIterator first, InputIterator last);

    void erase(iterator pos);
    size_type erase(const key_type& key);
    void erase(iterator first, iterator last);

    iterator find(const key_type& key);
    const_iterator cfind(const key_type& key) const;
    size_type count(const key_type& key) const;
    iterator lower_bound(const key_type& key);
    const_iterator clower_bound(const key_type& key) const;
    iterator upper_bound(const key_type& key);
    const_iterator cupper_bound(const key_type& key) const;
    std::pair<iterator, iterator> equal_range(const key_type& key);
    std::pair<const_iterator, const_iterator> cequal_range(const key_type& key) const;

    key_compare key_comp() const;
    value_compare value_comp() const;

private:
    struct Node {
        value_type data;
        Node* left;
        Node* right;
        Node* parent;
        Node(const value_type& d)
            : data(d), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    Node* root_;
    size_type size_;
    key_compare comp_;
    allocator_type alloc_;

    void destroy(Node* node);
    Node* copy_tree(Node* other_node, Node* parent);
    Node* minimum(Node* node) const;
    Node* maximum(Node* node) const;
    Node* find_node(const key_type& key) const;
    void erase_node(Node* node);
    void transplant(Node* u, Node* v);
};

#include "binarySearchTreeImplementation.tpp"

#endif 
