//
//  sorting.cpp
//  assignment01
//
//  Created by Joon on 2018/09/09.
//  Copyright © 2018 penubo. All rights reserved.
//

#include "sorting.hpp"

/*
 * Helper function
 *
 * check weather the given indicies are valid values for the list.
 *
 * @exception std::invalid_argument
 * if index_to (exclusive) is bigger than size of the list or
 * index_from (inclusive) is smaller than 0 or bigger than index_to,
 * throw exception.
 *
 */
void check_range(LinkedList* list, int index_from, int index_to) {
    if(list_cnt(list) < index_to) {
        throw std::invalid_argument("index_to is overrange");
    } else if (index_from > index_to || index_from < 0) {
        throw std::invalid_argument("index_from is overrange");
    }
}

/*
 * exchange sort
 *
 * exchange sort is executed by comparing between one pivot (from left) with last nodes.
 * for example below is the very first iteration of exchange sort.
 *
 *  O   O   O   O   O   O   O   O   O   O           (p) : pivot
 * (p) (c)
 *  O   O   O   O   O   O   O   O   O   O           (c) : current
 * (p)     (c)
 *  O   O   O   O   O   O   O   O   O   O
 * (p)          . . . . . . . . . . . .(c)
 *
 * if current is smaller than pivot during this iteration exchange pivot to current.
 *
 * After each iteration, it decides the smallest node at position of the pivot and
 * move the pivot to the right. do iteration until the pivot get to the tail.
 *
 * exchange sort sorts the list in ascending order.
 *
 * {@code} node_pivoted
 * the pivot node starts from head of the list. After each iteration, pivot will be
 * the smallest node among the list except nodes already decided by previous iteration.
 *
 * {@code} node_current
 * the current node is the very node to be examined to find smaller node than pivot.
 *
 */

void exchange_sort(LinkedList* list) {
    
    Node* node_pivoted = list -> head;
    Node* node_current = node_pivoted -> next;
    
    for (; node_pivoted != list -> tail; node_pivoted = node_pivoted -> next) {
        for (node_current = node_pivoted -> next; node_current != NULL; node_current = node_current -> next) {
            if (node_current -> data < node_pivoted -> data) {
                list_exchange_data(node_current, node_pivoted);
            }
        }
    }
}


/*
 * Helper function for merge_sort
 *
 * divide a linked_list into half
 *
 * first of all, it makes two pivot one of which moves twice at a time and
 * another moves once at a time. if faster pivot found the end of the list,
 * return the slower pivot.
 *
 */
Node* partition(Node* node) {
    
    if(!node) { return NULL; }
    
    Node* node_jumping_once = node;
    Node* node_jumping_twice = node;
    
    while (node_jumping_twice -> next && node_jumping_twice -> next -> next) {
        node_jumping_twice = node_jumping_twice -> next -> next;
        node_jumping_once = node_jumping_once -> next;
    }
    
    Node* node_head_of_after_half_list = node_jumping_once -> next;
    
    if (node_head_of_after_half_list) {
        node_head_of_after_half_list -> prev -> next = NULL;
        node_head_of_after_half_list -> prev = NULL;
    }
    
    return node_head_of_after_half_list;
}


/*
 * Helper function for merge_sort
 *
 * merge two lists, which is supposed to be sorted already, to an one list.
 *
 * recursively merge two lists. if one of the two lists are NULL, then return another
 * node. whenever it compares between first node and second node, if first node is smaller
 * then second node, we call merge function recursively and attach results to next first.
 *
 * {@code} first
 * the head of the first list.
 *
 * {@code} second
 * the head of the second list.
 *
 */
Node* merge(Node* first, Node* second) {
    
    if (!first) {
        return second;
    }
    if (!second) {
        return first;
    }
    
    if (first -> data > second -> data) {
        second -> next = merge(first, second -> next);
        return second;
    } else {
        first -> next = merge(first -> next, second);
        return first;
    }
}



/*
 * Helper function for merge_sort
 *
 * idea of merge sort is divide and conquer. Hence we first divide the list and
 * merge each pre-ordered lists into a whole sorted list recursively.
 *
 * Using partition function, it divides list ({@code} node_first) into half.
 * and call merge_sort recursively to the the first list and the second list.
 * and return the sorted list.
 *
 */

Node* merge_sort_rec(Node* node_first) {
    
    
    if (!node_first -> next) { return node_first; }     // stopping point of recursion.
    
    // divide the list first.
    Node* node_second = partition(node_first);
    Node* first = merge_sort_rec(node_first);
    Node* second = merge_sort_rec(node_second);
    
    // merge after division.
    return merge(first, second);
}

/*
 * merge sort
 */
void merge_sort(LinkedList* list) {
    list -> head = merge_sort_rec(list -> head);
}

/*
 * quick sort
 */
void quick_sort(LinkedList* list, int index_from, int index_to) {
    
    int n = index_to - index_from;

    if (n <= 1) { return; }
    
    Node* node_pivot = list_search_index(list, index_from);
    Node* node_left = node_pivot -> next;
    Node* node_right = list_search_index(list, index_to - 1);
    
    int index_left = index_from + 1;
    int index_right = index_to - 1;
    
    bool is_left_bigger = (node_left -> data > node_pivot -> data) ? true : false;
    bool is_right_smaller = (node_right -> data < node_pivot -> data) ? true : false;
    
    while (index_left <= index_right) {
        
        if (is_left_bigger && is_right_smaller) {
            list_exchange_data(node_left, node_right);
            is_left_bigger = false;
            is_right_smaller = false;
        }
        
        if (!is_left_bigger) {
            node_left = node_left -> next;
            index_left++;
            if (node_left != NULL && node_left -> data > node_pivot -> data) {
                is_left_bigger = true;
            }
        }
        
        if (!is_right_smaller) {
            index_right--;
            node_right = node_right -> prev;
            if (node_right != NULL && node_right -> data < node_pivot -> data) {
                is_right_smaller = true;
            }
        }
    }
    
    list_exchange_data(node_pivot, node_right);
    
    quick_sort(list, index_from, index_right);
    quick_sort(list, ++index_right, index_to);
}

void quick_sort_rec(Node* head, Node* tail, int index_from, int index_to) {
    if (index_to - index_from <= 1) { return; }
    
    Node* pivot = head;
    Node* left = head -> next;
    Node* right = tail;
    
    int index_left = index_from + 1;
    int index_right = index_to - 1;
    
    bool is_left_bigger = (left -> data > pivot -> data) ? true : false;
    bool is_right_smaller = (right -> data < pivot -> data) ? true : false;
    
    while (index_left <= index_right) {
        if (is_left_bigger && is_right_smaller) {
            list_exchange_data(left, right);
            is_left_bigger = false;
            is_right_smaller = false;
        }
        
        if (!is_left_bigger) {
            left = left -> next;
            index_left++;
            if (left != NULL && left -> data > pivot -> data) {
                is_left_bigger = true;
            }
        }
        
        if (!is_right_smaller) {
            right = right -> prev;
            index_right--;
            if (right != NULL && right -> data < pivot -> data) {
                is_right_smaller = true;
            }
        }
    }
    
    list_exchange_data(pivot, right);

    quick_sort_rec(head, right -> prev, index_from, index_right);
    quick_sort_rec(right -> next, tail, ++index_right, index_to);
}

/*
 * quick sort
 */
void quick_sort(LinkedList* list) {
//    quick_sort(list, 0, list_cnt(list));
    quick_sort_rec(list -> head, list -> tail, 0, list_cnt(list));
}

