#include <iostream>
#include <stdio.h>
#include "LinkedList.hpp"
#include "Course.hpp"

using namespace std;

node::node(Course courseData) {
    data = courseData;
    next = NULL;
}

LinkedList::LinkedList() {
    length = 0;
    list_head = NULL;
    list_tail = NULL;
}

void LinkedList::insert(Course course) {
    node *new_node = new node(course);
    if(length == 0) {
        list_head = new_node;
        list_tail = new_node;
        length = length + 1;
    }
    else {
        list_tail->next = new_node;
        list_tail = new_node;
        length = length + 1;
    }
}

Course LinkedList::pop() {
    if(length >= 1) {
        node *removed_node = nullptr;
        removed_node = list_head;
        list_head = list_head->next;
        length = length - 1; 

        return removed_node->data;
    }
    else {
        return Course();
    }
}

int LinkedList::getLength() {
    return length;
}

node LinkedList::search(string code) {
    return node();
}