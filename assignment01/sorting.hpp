//
//  sorting.hpp
//  assignment01
//
//  Created by Joon on 2018/09/09.
//  Copyright © 2018 penubo. All rights reserved.
//


#ifndef sorting_hpp
#define sorting_hpp

#include <stdio.h>
#include "linked_list.hpp"
#include "enum_sortings.h"

// exchange sort
void exchange_sort(LinkedList*);

// merge sort
void merge_sort(LinkedList*, int, int);

// overloading of merge sort
void merge_sort(LinkedList*);

// quick_sort
void quick_sort(LinkedList*);

#endif /* sorting_hpp */
