//
//  node.hpp
//  assignment01
//
//  Created by Joon on 2018/09/07.
//  Copyright © 2018 penubo. All rights reserved.
//

#ifndef node_hpp
#define node_hpp

#include <stdio.h>
#include <iostream>

/***********
 * structure Node
 *
 * node structure for doubly linked list.
 * (@member) data is integer value of the node.
 * (@member) next is pointer of the next node.
 * (@member) prev is pointer of the previous node.
 *
 ***********/
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
    
    // constructor
    Node(int data, Node *next=NULL, Node* prev=NULL) {
        this -> data = data;
        this -> next = next;
        this -> prev = prev;
    }
};

void print_list(Node*);



#endif /* node_hpp */
