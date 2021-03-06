#include "LinkList.h"

/**
 * LinkList constructor.
 *
 * @return void
 */
LinkList::LinkList() {
    head = NULL;
}

/**
 * Insert value in LinkList.
 *
 * @param val
 * @return void.
 */
void LinkList::insert(int val) {
    LinkNode* current = new LinkNode;
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
 * Search value in LinkList.
 *
 * @param find
 * @return bool
 */
bool LinkList::search(int find) {
    LinkNode* current = head;
    while(current != NULL)
    {
        if (current->data == find)
            return true;
        current = current->next;
    }
    return false;
}

/**
 * Remove value in LinkList.
 *
 * @param find
 * @return void
 */
void LinkList::remove(int find) {
    LinkNode** current = &head;
    while((*current)->data != find && (*current)->next != NULL) {
        current = &(*current)->next;
    }
    if ((*current)->data == find)
        *current = (*current)->next;
}

/**
 * Render the LinkList.
 *
 * @return void
 */
void LinkList::render() {
    LinkNode* current = head;
    std::cout << "Values: ";
    while(current != NULL)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
