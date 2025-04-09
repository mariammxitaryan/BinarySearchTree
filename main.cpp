#include "BST.hpp"
#include <iostream>
#include <vector>

int main() {
    std::cout << "Creating BinarySearchTree<int, std::string> bst\n";
    BinarySearchTree<int, std::string> bst;

    // --- Insert test ---
    std::cout << "\nInserting elements:\n";
    auto res1 = bst.insert({5, "five"});
    auto res2 = bst.insert({3, "three"});
    auto res3 = bst.insert({7, "seven"});
    auto res4 = bst.insert({2, "two"});
    auto res5 = bst.insert({4, "four"});
    auto res6 = bst.insert({6, "six"});
    auto res7 = bst.insert({8, "eight"});

    for (int i = 0; i < 10; ++i) {
        auto res = bst.insert({i, "num" + std::to_string(i)});
        if (res.second)
            std::cout << "Inserted key " << i << "\n";
        else
            std::cout << "Duplicate key " << i << "\n";
    }

    std::cout << "\nBST size after insertion: " << bst.size() << "\n";

    // --- In-Order Traversal (forward iterator) ---
    std::cout << "\nBST In-order Traversal:\n";
    for (auto it = bst.begin(); it != bst.end(); ++it) {
        std::cout << it->first << " -> " << it->second << "\n";
    }

    // --- Reverse Traversal ---
    std::cout << "\nBST Reverse In-order Traversal:\n";
    for (auto rit = bst.rbegin(); rit != bst.rend(); ++rit) {
        std::cout << rit->first << " -> " << rit->second << "\n";
    }

    // --- Lookup Functions ---
    int testKey = 4;
    std::cout << "\nTesting find() for key " << testKey << ":\n";
    auto itFound = bst.find(testKey);
    if (itFound != bst.end())
        std::cout << "Found key " << itFound->first << " with value " << itFound->second << "\n";
    else
        std::cout << "Key " << testKey << " not found\n";

    std::cout << "\nTesting lower_bound() and upper_bound() for key " << testKey << ":\n";
    auto lb = bst.lower_bound(testKey);
    auto ub = bst.upper_bound(testKey);
    if (lb != bst.end())
        std::cout << "lower_bound: " << lb->first << " -> " << lb->second << "\n";
    if (ub != bst.end())
        std::cout << "upper_bound: " << ub->first << " -> " << ub->second << "\n";

    std::cout << "\nTesting equal_range() for key " << testKey << ":\n";
    auto er = bst.equal_range(testKey);
    if (er.first != bst.end()) {
        std::cout << "equal_range first: " << er.first->first << " -> " << er.first->second << "\n";
    }
    if (er.second != bst.end()) {
        std::cout << "equal_range second: " << er.second->first << " -> " << er.second->second << "\n";
    }

    std::cout << "\nTesting count() for key " << testKey << ": " << bst.count(testKey) << "\n";

    // --- Erase by key ---
    std::cout << "\nErasing key " << testKey << "...\n";
    bst.erase(testKey);
    std::cout << "BST size after erasing key " << testKey << ": " << bst.size() << "\n";

    // --- Erase by iterator ---
    std::cout << "\nErasing element at iterator pointing to key 5...\n";
    auto itKey5 = bst.find(5);
    bst.erase(itKey5);
    std::cout << "BST size after erasing key 5: " << bst.size() << "\n";

    // --- Test copy constructor ---
    std::cout << "\nCreating bstCopy from bst using copy constructor...\n";
    BinarySearchTree<int, std::string> bstCopy(bst);
    std::cout << "bstCopy size: " << bstCopy.size() << "\n";
    std::cout << "Contents of bstCopy:\n";
    for (auto it = bstCopy.begin(); it != bstCopy.end(); ++it) {
        std::cout << it->first << " -> " << it->second << "\n";
    }

    // --- Test move assignment ---
    std::cout << "\nTesting move assignment...\n";
    BinarySearchTree<int, std::string> bstMoved;
    bstMoved = std::move(bstCopy);
    std::cout << "bstMoved size: " << bstMoved.size() << "\n";
    std::cout << "After move, bstCopy size: " << bstCopy.size() << "\n";

    // --- Test clear ---
    std::cout << "\nClearing bstMoved...\n";
    bstMoved.clear();
    std::cout << "bstMoved size after clear: " << bstMoved.size() << "\n";

    return 0;
}
