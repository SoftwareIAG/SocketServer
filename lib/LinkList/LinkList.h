#include <iostream>

#ifndef SOCKET_SERVER_LINKLIST_H
#define SOCKET_SERVER_LINKLIST_H

struct LinkNode {
    int data;
    LinkNode *next;
};

class LinkList {
    LinkNode* head;
public:
    LinkList();
    void insert(int val);
    bool search(int val);
    void remove(int val);
    void render();
};

#endif //SOCKET_SERVER_LINKLIST_H
