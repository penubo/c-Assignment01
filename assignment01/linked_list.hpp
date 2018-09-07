//
//  linked_list.hpp
//  assignment01
//
//  Created by Joon on 2018/09/07.
//  Copyright © 2018 penubo. All rights reserved.
//

#ifndef linked_list_hpp
#define linked_list_hpp

#include <stdio.h>
#include "node.hpp"

/******
 * structure LinkedList
 *
 * this structure has head, tail and size attribute.
 * head is the pointer which refers to the first node in LinkedList.
 * tail is the pointer which refers to the last node in LinkedList.
 * size is integer variable which indicates how many nodes are in LinkedList.
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
int size(LinkedList*);

// add new node in front of the first node.
void add_first(LinkedList*, Node*);

// add new node behind the last node.
void add_last(LinkedList*, Node*);

// remove the first node.
Node* remove_first(LinkedList*);

// remove the last node.
Node* remove_last(LinkedList*);

// get the first node.
Node* get_first(LinkedList*);

// get the last node.
Node* get_last(LinkedList*);




#endif /* linked_list_hpp */
