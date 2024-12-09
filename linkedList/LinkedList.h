#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class LinkedList{
private:
    Node<T>* firstNode = nullptr;
    Node<T>* lastNode = nullptr;
    int size = 0;

    void pushToEmpty(T value){
        Node<T>* node = new Node<T>(value);
        this->firstNode = node;
        this->lastNode = node;
        this->size++;
    }
public:
    LinkedList(){}

    LinkedList(T value){
        pushToEmpty(value);
    }

    ~LinkedList(){
        Node<T>* currentNode = this->firstNode;
        Node<T>* nextNode;
        while(!currentNode) {
            nextNode = currentNode->next;
            delete currentNode;
            head = nextNode;
        }
    }

    void push_back(T value){
        if(!this->firstNode){
            pushToEmpty(value);
            return;
        }
        Node<T>* newNode = new Node<T>(value);
        this->size++;
        this->lastNode->next = newNode;
        this->lastNode = newNode;
    }

    void push_front(T value) {
        if(!this->firstNode){
            pushToEmpty(value);
            return;
        }
        Node<T>* newFirstNode = new Node<T>(value, this->firstNode);
        this->size++;
        this->firstNode = newFirstNode;
    }

    T get(int indexTarget) {
        Node<T>* node = this->firstNode;
        int index = 0;
        if (indexTarget >= this->size) {
            cout << "Index Out Of Bounds" << endl;
            return 0;
        }
        while (index != indexTarget) {
            node = node->next;
            index++;
        }
        return node->value;
    }

    void deleteNode(int indexToDelete) {
        if (indexToDelete >= this->size) {
            cout << "Index Out Of Bounds" << endl;
            return;
        }
        Node<T>* nodeBeforeDeletedOne = this->firstNode;
        for(int i = 0; i < indexToDelete - 1; i++){
            nodeBeforeDeletedOne = nodeBeforeDeletedOne->next;
        }
        Node<T>* nodeToBeDeleted = nodeBeforeDeletedOne->next;
        nodeBeforeDeletedOne->next = nodeToBeDeleted->next;
        delete nodeToBeDeleted;
        this->size--;
    }

    void printList() {
        Node<T>* dummy = this->firstNode;
        while (dummy != nullptr) {
            cout << dummy->value << " ";
            dummy = dummy->next;
        }
        cout << endl;
    }

};