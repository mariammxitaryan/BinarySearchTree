```markdown
# Binary Search Tree (BST) Library

A modern, generic, template-based **Binary Search Tree (BST)** implementation in C++ designed for educational purposes. This project demonstrates the implementation of common BST functionalities with a focus on the latest C++20 practices.

---

## Overview

This project provides a C++ implementation of a non-balanced Binary Search Tree that supports key-value pairs (similar to a map). The library includes:

- Templated class with custom comparator and allocator support.
- Full set of BST operations:
  - Insertion, deletion, and lookup.
  - Iterators (forward, reverse, constant) implemented using modern C++ iterator traits.
  - Copy and move semantics.
- Extensive inline documentation and a clean project structure.

---

## Features

- **Generic BST Implementation:**  
  Template-based, supporting various key and value types.
  
- **Modern C++:**  
  Uses C++20 features and adheres to modern design principles, including the removal of deprecated components such as `std::iterator`.

- **Iterator Support:**  
  Provides bidirectional iterators (`iterator`, `const_iterator`, `reverse_iterator`, and `const_reverse_iterator`) to traverse the tree in-order.

- **Full Functionality:**  
  Supports insertion, deletion, lookup, range queries, and capacity queries (e.g., `empty()`, `size()`).

- **Well-Documented:**  
  Inline comments and a comprehensive `README.md` assist with understanding and using the code.

---

## Project Structure

```
├── README.md                  # Project overview and documentation.
├── binarySearchTreeHeader.hpp # Header file with class declarations.
├── binarySearchTreeImplementation.tpp  # Template implementation file.
└── main.cpp                   # Sample tester code demonstrating BST usage.
```

---

## Usage

To use the BST library in your project:

1. **Include the header** in your source files:

    ```cpp
    #include "binarySearchTreeHeader.hpp"
    ```

2. **Create and use a BST instance:**

    ```cpp
    #include "binarySearchTreeHeader.hpp"
    #include <iostream>
    
    int main() {
        // Create a BST mapping int to std::string.
        BinarySearchTree<int, std::string> bst;
        
        // Insert key-value pairs.
        bst.insert({5, "five"});
        bst.insert({3, "three"});
        bst.insert({7, "seven"});
    
        // Traverse in-order.
        for (auto it = bst.begin(); it != bst.end(); ++it) {
            std::cout << it->first << " -> " << it->second << std::endl;
        }
        return 0;
    }
    ```

---

## Compilation

The project supports C++20. To compile the tester `main.cpp` using `g++`, run the following command in your terminal:

```bash
g++ -std=c++20 -o bst_test main.cpp
```

Then execute:

```bash
./bst_test
```

---

## Contributing

Contributions and suggestions are welcome! If you would like to contribute:

1. Fork the repository.
2. Create a new branch for your feature or bugfix.
3. Ensure your code adheres to modern C++ practices.
4. Submit a pull request with clear details of your changes.

Feel free to open issues or contact the maintainers if you have any questions.

---

## Acknowledgments

- Inspired by the classic data structure implementations and modern C++ best practices.

---

Enjoy using the Binary Search Tree Library!
```
