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

static int NODE_COUNT = 1000;
static char* SORTING[3] = {"quick", "merge", "excha"};

/*
 * Helper function
 *
 * It checks if the list is sorted in ascending order.
 *
 */
bool is_sorted(Node* head) {
    if (!head) { return true; }
    Node* current = head;
    while (current -> next) {
        if (current -> data > current -> next -> data) {
            return false;
        }
        current = current -> next;
    }
    return true;
}

/*
 * Helper function
 *
 * initialize list randomly
 */
void init(LinkedList* list) {
    srand((unsigned)time(NULL));    // random seed
    
    for (int i = 0; i < NODE_COUNT; i++) {    // make random list
        list_insert_tail(list, new Node(rand() % 1000000));
    }
}

int main(int argc, const char * argv[]) {
    
    struct timespec start, end;
    
    LinkedList* list = new LinkedList();
    LinkedList* list_copied;
    
    init(list);
    
    for (int i = 0; i < 3; i++) {
        
        list_copied = list_copy(list);      // make a copy of the list
        
        clock_gettime(_CLOCK_REALTIME, &start);
        list_sort_asc(list_copied, Sortings(i));
        clock_gettime(_CLOCK_REALTIME, &end);
        printf("%s: time(nano): %.0lf\n", SORTING[i],
               (end.tv_nsec - start.tv_nsec) + (end.tv_sec - start.tv_sec) * 1E9);
        
        cout << "sorted checking... "
             << (is_sorted(list_copied -> head) ? "true" : "false") << endl;
    }
}
