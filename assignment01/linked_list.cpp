//
//  linked_list.cpp
//  assignment01
//
//  Created by Joon on 2018/09/07.
//  Copyright © 2018 penubo. All rights reserved.
//

#include "linked_list.hpp"
#include "sorting.hpp"
/*
 * Accessor function
 *
 * return size of the given LinkedList object.
 *
 */
int list_cnt(LinkedList* list) {
    return list -> size;
}

/*
 * Modifier function
 *
 * add new node in front of the first node.
 * 
 */
void list_insert_head(LinkedList* list, Node* node) {
    if (list -> head == NULL) {
        list -> head = node;
        list -> tail = list -> head;
    } else {
        node -> next = list -> head;
        list -> head -> prev = node;
        list -> head = node;
    }
    
    list -> size++;
}

/*
 * Modifier function
 *
 * add new node behind the last node.
 *
 */
void list_insert_tail(LinkedList* list, Node* node) {
    if (list -> tail == NULL) {
        list -> tail = node;
        list -> head = list -> tail;
    } else {
        list -> tail -> next = node;
        node -> prev = list -> tail;
        list -> tail = node;
    }
    
    list -> size++;
}

/*
 * Modifier function
 *
 * add new node at the given index.
 * if list is empty and index is given for 0, then just insert node.
 *
 * @exception: std::invalid_argument
 *
 * if (@param) index is over range of the list, throw exception.
 * else if (@param) index is 0, insert it in front of the head.
 * else if (@param) index is last index, insert it after the tail.
 * else insert it to the position refered by (@param) index.
 *
 */
void list_insert_index(LinkedList* list, int index, Node* node) {
    if (index < 0 || index > list_cnt(list)) {
        throw std::invalid_argument( "received unvalid index number " );
    } else if (index == 0) {
        list_insert_head(list, node);
    } else if (index == list_cnt(list) - 1) {
        list_insert_tail(list, node);
    } else {
        
        Node* current = list -> head;
        
        for(int i = 0; i < index; i++, current = current -> next);
        
        current -> prev -> next = node;
        node -> prev = current -> prev;
        node -> next = current;
        current -> prev = node;
        
        list -> size++;
        
    }
}


/*
 * Modifier function
 *
 * remove the first node from the list and return the node.
 *
 * @exception: std::underflow_error
 *
 * if the list is empty, throw exception.
 *
 */
Node* list_delete_head(LinkedList* list) {
    
    Node* node = list -> head;

    if (list -> size == 0) {            // when list is empty.
        throw std::underflow_error(" there is no node to be deleted ");
    } else if (list -> size == 1) {     // when list has only one node.
        list -> head = NULL;
        list -> tail = NULL;
    } else {                            // when list has more than two nodes.
        list -> head -> next -> prev = NULL;
        list -> head = list -> head -> next;
        node -> next = NULL;
    }
    
    list -> size--;

    return node;
}

/*
 * Modifier function
 *
 * remove the last node and return the node.
 *
 * @exception: std::underflow_error
 *
 * if the list is empty, throw exception.
 *
 */
Node* list_delete_tail(LinkedList* list) {
    
    Node* node = list -> tail;
    
    if (list -> size == 0) {            // when list is empty.
        throw std::underflow_error(" there is no node to be deleted ");
    } else if (list -> size == 1) {     // when list has only one node.
        list -> head = NULL;
        list -> tail = NULL;
    } else {                            // when list has more than two nodes.
        list -> tail = list -> tail -> prev;
        list -> tail -> next = NULL;
        node -> prev = NULL;
    }
    
    list -> size--;
    return node;
}


/*
 * Modifier function
 *
 * remove a node at the given index.
 *
 * @exception: std::invalid_argument
 *
 * if (@param) index is over range of the list, throw exception.
 * else if (@param) index is 0, delete the head.
 * else if (@param) index is last index, delete the tail.
 * else delete the node in order of (@param) index.
 *
 */
Node* list_delete_index(LinkedList* list, int index) {
    
    Node* node = NULL;
    
    if (index < 0 || index > list_cnt(list)) {
        throw std::invalid_argument( " received unvalid index number " );
    } else if (index == 0) {
        list_delete_head(list);
    } else if (index == list_cnt(list) - 1) {
        list_delete_tail(list);
    } else {
        
        Node* current = list -> head;
        
        for(int i = 0; i < index; i++, current = current -> next);
        node = current;
        
        current -> prev -> next = current -> next;
        current -> next -> prev = current -> prev;
        node -> next = NULL;
        node -> prev = NULL;
        list -> size--;
    }
    
    return node;
}

/*
 * Modifier function
 *
 * remove the data from the list.
 *
 * if data is in the list, call (@function) list_delete_index(LinkedList*, int)
 * after counting index of the data. And return the node removed from the list.
 *
 * if data is not in the list, return NULL.
 *
 */
Node* list_delete_data(LinkedList* list, int data) {
    
    Node* node = NULL;
    Node* current = list -> head;
    int index_count = 0;
    
    while (current != NULL && current -> data != data) {    // counting index
        current = current -> next;
        index_count++;
    }
    
    if (current != NULL) {
        node = current;
        list_delete_index(list, index_count);               // delete data.
    }
    
    return node;
}


/*
 * Accessor function
 *
 * search a node at the given index.
 *
 * @exception: std::invalid_argument
 *
 * if index is out of range of the list, throw exception.
 * After find the node, return it.
 *
 */
Node* list_search_index(LinkedList* list, int index) {
    
    Node* node = NULL;
    
    if (index < 0 || index > list_cnt(list)) {
        throw std::invalid_argument( " received unvalid index number " );
    } else {
        
        Node* current = list -> head;
        
        for(int i = 0; i < index; i++, current = current -> next);
        
        node = current;
        
    }
    
    return node;
}

/*
 * Accessor function
 *
 * search a node of having the given data.
 *
 * if data is not in the list, return NULL.
 *
 */
Node* list_search_data(LinkedList* list, int data) {
    
    Node* node = NULL;
    Node* current = list -> head;
    
    while (current != NULL && current -> data != data) {    // counting index
        current = current -> next;
    }
    
    node = current;
    
    return node;
}

/*
 * Modifier function
 *
 * clear the list.
 *
 * Since we are using allocation memory access for nodes,
 * we should free memory of each node in the list.
 *
 */
void list_clear(LinkedList* list) {
    
    Node* current = NULL;
    
    do {
        current = list -> head;
        list -> head = list -> head -> next;
        delete current;
    } while (list -> head != NULL);
    
    list -> size = 0;
}

/*
 * Accessor function
 *
 * copy the list from {@code} index_from to {@code} index_to.
 * range is index_from <= index < index_to. (exclusive index_to)
 *
 * dynamically copy each node in the original list and paste to
 * new linked list.
 *
 */
LinkedList* list_copy(LinkedList* list, int index_from, int index_to) {
    
    LinkedList* new_list = new LinkedList();
    
    int n = index_to - index_from;
    
    if (n > list_cnt(list)) {
        n = list_cnt(list);
    }
    
    Node* current = list_search_index(list, index_from);
    
    for (int i = 0; i < n; i++) {
        list_insert_tail(new_list, new Node(current -> data));
        current = current -> next;
    }
   
    return new_list;
}

LinkedList* list_copy(LinkedList* list) {
    return list_copy(list, 0, list_cnt(list));
}


// sort the list by ascending order.
void list_sort_asc(LinkedList* list, Sortings sort) {
    switch(sort) {
        case EXCHANGE:
            exchange_sort(list);
            break;
        case MERGE:
            merge_sort(list, 0, list_cnt(list));
            break;
        case QUICK:
            quick_sort(list);
            break;
        default:
            break;
    }
}

// sort the list by decending order.
void list_sort_dec(LinkedList*) {
    
}

void list_exchange_data(Node* node_a, Node* node_b) {
    int temp = node_a -> data;
    node_a -> data = node_b -> data;
    node_b -> data = temp;
}























