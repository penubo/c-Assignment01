//
//  main.cpp
//  assignment01
//
//  Created by Joon on 2018/09/05.
//  Copyright © 2018 penubo. All rights reserved.
//

#include "linked_list.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    LinkedList* list = new LinkedList();
    Node* t1 = new Node(11);
    Node* t2 = new Node(22);
    Node* t3 = new Node(33);
    Node* t4 = new Node(44);
    list_insert_tail(list, t1);
    list_insert_head(list, t2);
    list_insert_tail(list, t3);
    list_insert_index(list, 0, t4);
    
    Node* n = list_search_index(list, 3);
    printf("searched node %d\n", n -> data);

//    list_clear(&list);
    print_list(list -> head);
    
    LinkedList* new_list = list_copy(list);
    print_list(new_list -> head);
    list_clear(new_list);

    printf("new list after clear\n");
    print_list(new_list -> head);
    printf("%d\n", list_cnt(new_list));

    printf("%d\n", list_cnt(list));
    
}
