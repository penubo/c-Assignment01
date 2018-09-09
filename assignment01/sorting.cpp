//
//  sorting.cpp
//  assignment01
//
//  Created by Joon on 2018/09/09.
//  Copyright © 2018 penubo. All rights reserved.
//

#include "sorting.hpp"

void exchange_sort(LinkedList* list) {
    Node* pivot = list -> head;
    Node* current = pivot -> next;
    
    for (; pivot != list -> tail; pivot = pivot -> next) {
        for (current = pivot -> next; current != NULL; current = current -> next) {
            if (current -> data < pivot -> data) {
                list_exchange_data(current, pivot);
            }
        }
    }
}


void merge(LinkedList* list, int from, int to) {
    int n = to - from;
   
    LinkedList* list_copied = list_copy(list, from, to);
    
    Node* left_node = list_copied -> head;
    Node* right_node = list_search_index(list_copied, n / 2);
    
    int left_index = from;
    int right_index = from + n / 2;
    
    int current = from;
    
    while (left_index < from + n / 2 && right_index < to) {
        if (left_node -> data <= right_node -> data) {
            Node* temp = left_node;
            left_node = left_node -> next;
            list_exchange_data(list_search_index(list, current++), temp);
            left_index++;
        } else {
            Node* temp = right_node;
            right_node = right_node -> next;
            list_exchange_data(list_search_index(list, current++), temp);
            right_index++;
        }
    }
    
    while (left_index < from + n / 2) {
        Node* temp = left_node;
        list_exchange_data(list_search_index(list, current++), temp);
        left_node = left_node -> next;
        left_index++;
    }    
}


void merge_sort(LinkedList* list, int from, int to) {
    int n = to - from;
    
    if (n <= 1) { return; }
    
    merge_sort(list, from, from + n / 2);
    merge_sort(list, from + n / 2, to);
    
    merge(list, from, to);
}



void quick_sort(LinkedList* list) {
    
}
