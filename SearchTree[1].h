#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
struct Node
{
    T data_;
    Node* left_;
    Node* right_;
};

template <typename T>
class SearchTree
{
public:
    SearchTree() : root_{ nullptr } {}
    ~SearchTree();

    bool empty();
    void insert(const T& data);
    void remove(const T& data);
    T find_min();
    T find_max();
    bool contains(const T& data);
    void print();

private:
    Node<T>* root_;

    void insert(const T& data, Node<T>*& node);
    void remove(const T& data, Node<T>*& node);
    T find_min(Node<T>* node);
    T find_max(Node<T>* node);
    bool contains(const T& data, Node<T>* node);
    void print(Node<T>* node, int depth);
    void destroy(Node<T>* node);
};

template <typename T>
SearchTree<T>::~SearchTree() {
    destroy(root_);
}

template <typename T>
void SearchTree<T>::destroy(Node<T>* node) {
    if (node == nullptr) return;
    destroy(node->left_);
    destroy(node->right_);
    delete node;
}

template <typename T>
bool SearchTree<T>::empty() {
    return root_ == nullptr;
}

template <typename T>
void SearchTree<T>::insert(const T& data) {
    insert(data, root_);
}

template <typename T>
void SearchTree<T>::insert(const T& data, Node<T>*& node) {
    if (node == nullptr) {
        node = new Node<T>{ data, nullptr, nullptr };
    }
    else if (data < node->data_) {
        insert(data, node->left_);
    }
    else {
        insert(data, node->right_);
    }
}

template <typename T>
void SearchTree<T>::remove(const T& data) {
    remove(data, root_);
}

template <typename T>
void SearchTree<T>::remove(const T& data, Node<T>*& node) {
    if (node == nullptr) return;

    if (data < node->data_) {
        remove(data, node->left_);
    }
    else if (data > node->data_) {
        remove(data, node->right_);
    }
    else if (node->left_ != nullptr && node->right_ != nullptr) {
        node->data_ = find_min(node->right_);
        remove(node->data_, node->right_);
    }
    else {
        Node<T>* oldNode = node;
        node = (node->left_ != nullptr) ? node->left_ : node->right_;
        delete oldNode;
    }
}

template <typename T>
T SearchTree<T>::find_min() {
    if (empty()) throw std::runtime_error("empty tree");
    return find_min(root_);
}

template <typename T>
T SearchTree<T>::find_min(Node<T>* node) {
    if (node->left_ == nullptr) return node->data_;
    return find_min(node->left_);
}

template <typename T>
T SearchTree<T>::find_max() {
    if (empty()) throw std::runtime_error("empty tree");
    return find_max(root_);
}

template <typename T>
T SearchTree<T>::find_max(Node<T>* node) {
    if (node->right_ == nullptr) return node->data_;
    return find_max(node->right_);
}

template <typename T>
bool SearchTree<T>::contains(const T& data) {
    return contains(data, root_);
}

template <typename T>
bool SearchTree<T>::contains(const T& data, Node<T>* node) {
    if (node == nullptr) return false;
    if (data < node->data_) return contains(data, node->left_);
    if (data > node->data_) return contains(data, node->right_);
    return true;
}

template <typename T>
void SearchTree<T>::print() {
    print(root_, 0);
}

template <typename T>
void SearchTree<T>::print(Node<T>* node, int depth) {
    if (node == nullptr) return;
    print(node->right_, depth + 1);
    std::cout << std::string(depth * 4, ' ') << node->data_ << std::endl;
    print(node->left_, depth + 1);
}
