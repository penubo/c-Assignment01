//
//  linked_list.hpp
//  assignment01
//
//  Created by Joon on 2018/09/07.
//  Copyright © 2018 penubo. All rights reserved.
//



#ifndef linked_list_hpp
#define linked_list_hpp

#include "node.hpp"
#include "enum_sortings.h"

#include <stdio.h>

/******
 * structure LinkedList
 *
 * this structure has head, tail and size attribute.
 * (@member) head is the pointer which refers to the first node in LinkedList.
 * (@member) tail is the pointer which refers to the last node in LinkedList.
 * (@member) size is integer variable which indicates how many nodes are in LinkedList.
 *
 ******/
struct LinkedList {
    Node* head;
    Node* tail;
    int size;
    
    // constructor
    LinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
};

// return size of the node.
int list_cnt(LinkedList*);

// add new node in front of the first node.
void list_insert_head(LinkedList*, Node*);

// add new node behind the last node.
void list_insert_tail(LinkedList*, Node*);

// add new node at the given index.
void list_insert_index(LinkedList*, int, Node*);

// remove the first node.
Node* list_delete_head(LinkedList*);

// remove the last node.
Node* list_delete_tail(LinkedList*);

// remove the data from list.
Node* list_delete_data(LinkedList*, int);

// remove a node at the given index.
Node* list_delete_index(LinkedList*, int);

// search a node at the given index.
Node* list_search_index(LinkedList*, int);

// search a node of having the given data.
Node* list_search_data(LinkedList*, int);

// clear the list.
void list_clear(LinkedList*);

// copy the entire list.
LinkedList* list_copy(LinkedList*, int, int);

// overloading function of list_copy.
LinkedList* list_copy(LinkedList*);

// sort the list by ascending order.
void list_sort_asc(LinkedList*, Sortings);

// sort the list by decending order.
void list_sort_dec(LinkedList*, Sortings);

// exchange data between two nodes.
void list_exchange_data(Node*, Node*);

#endif /* linked_list_hpp */
