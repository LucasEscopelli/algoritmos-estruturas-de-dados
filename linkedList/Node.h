#pragma once

template <typename T>
struct Node {
    T value;
    Node<T>* next;
    Node(T value, Node<T>* nextNode): value(value), next(nextNode) {}
    Node(T value): value(value), next(nullptr) {}
    Node(){};
};