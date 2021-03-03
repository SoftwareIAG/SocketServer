#include "LinkList.h"

LinkList::LinkList() {
    head = NULL;
}

/**
 * Insert.
 *
 * @param val
 */
void LinkList::insert(int val) {
    Node* current = new Node;
    current->data = val;
    current->next = NULL;

    if (head == NULL)
        head = current;
    else {
        current->next = head;
        head = current;
    }
}

/**
 * Search.
 *
 * @param val
 * @return
 */
bool LinkList::search(int val) {
    Node* current = head;
    while(current != NULL)
    {
        if (current->data == val)
            return true;
        current = current->next;
    }
    return false;
}

/**
 * Remove.
 *
 * @param val
 */
void LinkList::remove(int find) {
    Node** current = &head;
    while((*current)->data != find && (*current)->next != NULL) {
        current = &(*current)->next;
    }
    if ((*current)->data == find)
        *current = (*current)->next;
}

/**
 * Render.
 */
void LinkList::render() {
    Node* current = head;
    while(current != NULL)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
