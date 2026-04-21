//
// Created by User on 21.04.2026.
//

#ifndef STRUCTURES_DOUBLYLINKEDLIST_H
#define STRUCTURES_DOUBLYLINKEDLIST_H
#include "Node.h"
#include <iostream>
#include <memory>
#include <stdexcept>

template<typename T>
class DoublyLinkedList {
private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void push_front(T element) {
        auto newNode = std::make_shared<Node<T>>(element);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    void push_back(T element) {
        auto newNode = std::make_shared<Node<T>>(element);

        if (!head) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void pop_front() {
        if (!head) {
            throw std::out_of_range("List is empty");
        }
        head = head->next;
        if (head) {
            head->prev.reset();
        } else {
            tail = nullptr;
        }
        size--;
    }

    void pop_back() {
        if (!tail) {
            throw std::out_of_range("List is empty");
        }
        auto prevNode = tail->prev.lock();
        if (prevNode) {
            prevNode->next = nullptr;
            tail = prevNode;
        } else {
            head = tail = nullptr;
        }
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

    // 🔹 вставка за індексом
    void insert(int index, T element) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            push_front(element);
            return;
        }
        if (index == size) {
            push_back(element);
            return;
        }
        auto newNode = std::make_shared<Node<T>>(element);
        auto temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        auto prevNode = temp->prev.lock();
        newNode->next = temp;
        newNode->prev = prevNode;
        prevNode->next = newNode;
        temp->prev = newNode;
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
        if (index == size - 1) {
            pop_back();
            return;
        }
        auto temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        auto prevNode = temp->prev.lock();
        auto nextNode = temp->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
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

    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<T>& list) {
        auto temp = list.head;
        while (temp) {
            os << temp->data << " <-> ";
            temp = temp->next;
        }
        os << "nullptr";
        return os;
    }
};

#endif //STRUCTURES_DOUBLYLINKEDLIST_H