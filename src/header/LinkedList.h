#pragma once
#include <iostream>

template<typename T>
class LinkedList{
public:
    LinkedList();
    ~LinkedList();

    void insertFront(T value);
    void insertBack(T value);
    void deleteElement(T value);
    bool search(T value) const;
    void display() const;

private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };
    Node* head;
};

// Implementation

template<typename T>
LinkedList<T>::LinkedList() : head(nullptr) {}

template<typename T>
LinkedList<T>::~LinkedList(){
    Node* current = head;
    // Clean up all data nodes linked
    while (current != nullptr){
        Node* next = current->next;
        delete current;
        current = next;
    }
}

template<typename T>
void LinkedList<T>::insertFront(T value){
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

template<typename T>
void LinkedList<T>::insertBack(T value){
    Node* newNode = new Node(value);
    if (head == nullptr){
        head = newNode;
        return;
    }
    // Shift the nodes forward to insert at the last node
    Node* current = head;
    while (current->next != nullptr){
        current = current->next;
    }
    // Insertion
    current->next =  newNode;
}

template<typename T>
void LinkedList<T>::deleteElement(T value){
    if (head == nullptr) return;
    
    if (head->data == value){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != value){
        current = current->next;
    }
    
    if (current->next == nullptr) return;
    Node* temp = current->next;
    current->next = current->next->next;
    delete temp; 
}

template<typename T>
bool LinkedList<T>::search(T value) const{
    Node* current = head;
    while (current != nullptr){
        if (current->data == value){
            return true;
        }
        current =current->next;
    }
    return false;
}

template<typename T>
void LinkedList<T>::display() const{
    Node* current = head;
    std::cout << "\t[START] ";
    while (current != nullptr){
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "null [END]" << std::endl;
}