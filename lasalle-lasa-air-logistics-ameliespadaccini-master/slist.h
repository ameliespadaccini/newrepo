/*

Header file for single linked list class library

*/
#ifndef SLIST_H
#define SLIST_H
#include <iostream>
using namespace std;

class Airport
{
public:
    char code[5];
    double longitude;
    double latitude;
};

struct Node
{
    Airport data;
    Node* next;

    Node(const Airport& a) : data(a), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void add(Airport& port);
    void toString();
    void insert(int position, const Airport& port);
    bool equals(LinkedList right);
    Airport get(int index);
    void swap(int index1, int index2);
    void remove(int index);
    int size();
    void clear();
    bool isEmpty();
    LinkedList subList(int start, int length);
};

#endif // LINKEDLIST_H

