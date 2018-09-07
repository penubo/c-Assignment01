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
    Node t1(11);
    Node t2(22, &t1);
    Node t3(33, &t2);
    print_list(&t3);
    
}
