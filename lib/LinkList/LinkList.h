//
// Created by zen on 02-03-21.
//

#include <iostream>

#ifndef SOCKETSERVER_LINKLIST_H
#define SOCKETSERVER_LINKLIST_H

struct Node {
    int data;
    Node *next;
};

class LinkList {
    Node* head;
public:
    LinkList();
    void insert(int val);
    bool search(int val);
    void remove(int val);
    void render();
};


#endif //SOCKETSERVER_LINKLIST_H
