//
//  node.cpp
//  assignment01
//
//  Created by Joon on 2018/09/07.
//  Copyright © 2018 penubo. All rights reserved.
//

#include "node.hpp"

/*
 * print_list
 *
 * print each node recursively.
 *
 */
void print_list(Node* head) {
    Node* current = head;
    while(current != NULL) {
        printf("%d\n", current -> data);
        current = current -> next;
    }
}
