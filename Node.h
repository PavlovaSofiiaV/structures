//
// Created by User on 20.04.2026.
//

#ifndef STRUCTURES_NODE_H
#define STRUCTURES_NODE_H

template<typename T>
struct Node {
    T data;
    std::shared_ptr<Node<T>> next;
    Node(T element) : data(element), next(nullptr) {}
};

#endif //STRUCTURES_NODE_H