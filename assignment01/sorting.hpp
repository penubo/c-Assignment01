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

void exchange_sort(LinkedList*);

void merge_sort(LinkedList*, int, int);

void quick_sort(LinkedList*);

#endif /* sorting_hpp */
