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

struct Node {
    int data;
    struct Node* next;
    Node(int data, Node *next=NULL) {
        this -> data = data;
        this -> next = next;
    }
};

Node* create_node(int, Node* = NULL);

void print_list(Node*);

//int size(Node*);

#endif /* node_hpp */
