#include <iostream>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

int main() {

    std::cout << "=== Singly Linked List ===\n";

    SinglyLinkedList<int> s;

    s.push_back(10);
    s.push_back(7);
    s.push_front(3);

    std::cout << s << std::endl;

    s.pop_front();
    std::cout << "After pop_front: " << s << std::endl;

    s.pop_back();
    std::cout << "After pop_back: " << s << std::endl;

    std::cout << "\n=== Doubly Linked List ===\n";

    DoublyLinkedList<int> d;

    d.push_back(5);
    d.push_back(4);
    d.push_front(6);

    std::cout << d << std::endl;

    d.insert(1, 7);
    std::cout << "After insert: " << d << std::endl;

    d.remove(2);
    std::cout << "After remove: " << d << std::endl;

    d.pop_back();
    std::cout << "After pop_back: " << d << std::endl;

    std::cout << "Find 7: " << d.find(7) << std::endl;

    return 0;
}