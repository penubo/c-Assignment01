//
//  node.cpp
//  assignment01
//
//  Created by Joon on 2018/09/07.
//  Copyright © 2018 penubo. All rights reserved.
//

#include "node.hpp"

Node* create_node(int data, Node* next) {
    Node* new_node = NULL;
    new_node = (Node*) malloc(sizeof(Node));
    new_node -> data = data;
    new_node -> next = next;
    return new_node;
}

int size(Node* node) {
    int sum_of_nodes = 0;
    Node* current = node;
    while(current != NULL) {
        sum_of_nodes++;
        current = current -> next;
    }
    return sum_of_nodes;
}

void print_list(Node* head) {
    Node* current = head;
    while(current != NULL) {
        printf("%d\n", current -> data);
        current = current -> next;
    }
}
