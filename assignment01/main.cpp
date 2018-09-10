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

int node_cnt = 50000;

int main(int argc, const char * argv[]) {
    
    struct timespec start, end;
    
    LinkedList* list = new LinkedList();
    
    srand((unsigned)time(NULL));
    
    for (int i = 0; i < node_cnt; i++) {
        list_insert_tail(list, new Node(rand() % 1000000));
    }
    
    printf("before sorted\n");
    print_list(list -> head);
    printf("size is : %d\n", list_cnt(list));
    
    clock_gettime(_CLOCK_REALTIME, &start);
    list_sort_asc(list, MERGE);
//    std::this_thread::sleep_for(std::chrono::seconds(5));
    clock_gettime(_CLOCK_REALTIME, &end);
    


    
    printf("after sorted\n");
    print_list(list -> head);
    printf("size is : %d\n", list_cnt(list));
    
    printf("time(nano): %.0lf\n", (end.tv_nsec - start.tv_nsec) + (end.tv_sec - start.tv_sec) * 1E9);

    
    
}
