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
#include <thread>
#include <chrono>

using namespace std;

int node_cnt = 100000;

bool is_sorted(Node* head) {
    Node* current = head;
    while (current -> next) {
        if (current -> data > current -> next -> data) {
            return false;
        }
        current = current -> next;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    
    struct timespec start, end;
    
    LinkedList* list = new LinkedList();
    LinkedList* list_copied;
    
    srand((unsigned)time(NULL));
    
    for (int i = 0; i < node_cnt; i++) {
        list_insert_tail(list, new Node(rand() % 1000000));
    }
    

    list_copied = list_copy(list);

    clock_gettime(_CLOCK_REALTIME, &start);
    list_sort_asc(list_copied, QUICK);
    clock_gettime(_CLOCK_REALTIME, &end);
    printf("quick: time(nano): %.0lf\n", (end.tv_nsec - start.tv_nsec) + (end.tv_sec - start.tv_sec) * 1E9);

    cout << "sorted checking... " ;
    cout << (is_sorted(list_copied -> head) ? "true" : "false") << endl;
    
    list_copied = list_copy(list);

    clock_gettime(_CLOCK_REALTIME, &start);
    list_sort_asc(list_copied, MERGE);
    clock_gettime(_CLOCK_REALTIME, &end);
    printf("merge: time(nano): %.0lf\n", (end.tv_nsec - start.tv_nsec) + (end.tv_sec - start.tv_sec) * 1E9);

    cout << "sorted checking... " ;
    cout << (is_sorted(list_copied -> head) ? "true" : "false") << endl;
    
    list_copied = list_copy(list);

    clock_gettime(_CLOCK_REALTIME, &start);
    list_sort_asc(list_copied, EXCHANGE);
    clock_gettime(_CLOCK_REALTIME, &end);
    printf("excha: time(nano): %.0lf\n", (end.tv_nsec - start.tv_nsec) + (end.tv_sec - start.tv_sec) * 1E9);

    cout << "sorted checking... " ;
    cout << (is_sorted(list_copied -> head) ? "true" : "false") << endl;
    
    
  
}
