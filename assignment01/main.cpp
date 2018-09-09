//
//  main.cpp
//  assignment01
//
//  Created by Joon on 2018/09/05.
//  Copyright © 2018 penubo. All rights reserved.
//

#include "linked_list.hpp"
#include "sorting.hpp"

#include <ctime>

using namespace std;

int node_cnt = 10;

int main(int argc, const char * argv[]) {
    LinkedList* list = new LinkedList();
    
    srand((unsigned)time(NULL));
    
    for (int i = 0; i < node_cnt; i++) {
        list_insert_tail(list, new Node(rand() % 100));
    }
    
    printf("before sorted\n");
    print_list(list -> head);
    printf("size is : %d\n", list_cnt(list));
    
    list_sort_asc(list, MERGE);
    
    printf("after sorted\n");
    print_list(list -> head);
    printf("size is : %d\n", list_cnt(list));
    
    
}
