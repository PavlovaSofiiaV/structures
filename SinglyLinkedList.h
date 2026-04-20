//
// Created by User on 20.04.2026.
//

#ifndef STRUCTURES_SINGLYLINKEDLIST_H
#define STRUCTURES_SINGLYLINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <memory>
#include <stdexcept>


template<typename T>
class SinglyLinkedList {
private:
    std::shared_ptr<Node<T>> head;
    int size;

public:

    SinglyLinkedList() : head(nullptr), size(0) {}
    ~SinglyLinkedList() {
        head = nullptr;
        size = 0;
    }

    void push_front(T element) {
        auto newNode = std::make_shared<Node<T>>(element);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void push_back(T element) {
        auto newNode = std::make_shared<Node<T>>(element);
        if (!head) {
            head = newNode;
            size++;
            return;
        }
        auto temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        size++;
    }

    void pop_front() {
        if (!head) {
            throw std::out_of_range("List is empty");
        }
        head = head->next;
        size--;
    }

    void pop_back() {
        if (!head) {
            throw std::out_of_range("List is empty");
        }
        if (!head->next) {
            head = nullptr;
            size--;
            return;
        }
        auto temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        temp->next = nullptr;
        size--;
    }

    T at(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        auto temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    void insert(int index, T element) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            push_front(element);
            return;
        }
        auto newNode = std::make_shared<Node<T>>(element);
        auto temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            pop_front();
            return;
        }
        auto temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        size--;
    }

    int getSize() const {
        return size;
    }


    bool empty() const {
        return size == 0;
    }

    int find(T element) {
        auto temp = head;
        int index = 0;

        while (temp) {
            if (temp->data == element) {
                return index;
            }
            temp = temp->next;
            index++;
        }

        return -1;
    }

    friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList<T>& list) {
        auto temp = list.head;
        while (temp) {
            os << temp->data << " ";
            temp = temp->next;
        }
        os << "nullptr";
        return os;
    }
};

#endif //STRUCTURES_SINGLYLINKEDLIST_H