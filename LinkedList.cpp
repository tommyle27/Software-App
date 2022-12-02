#include <iostream>
#include <stdio.h>
#include "LinkedList.hpp"
#include "Course.hpp"

using namespace std;

//node constructor
node::node(Course courseData) {
    data = courseData;
    next = NULL;
}

//Linked list constructor
LinkedList::LinkedList() {
    length = 0;
    list_head = NULL;
    list_tail = NULL;
}

//Creates and inserts new node containing course data
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

//Pops the node at the head of the list and returns that nodes course object
Course LinkedList::pop() {
    if(length >= 1) {
        node *removed_node = nullptr;
        removed_node = list_head;
        list_head = list_head->next;
        length = length - 1; 

        return removed_node->data;
    }
    else {
        cout << "Cannot remove from an empty list!";
        exit(3);
        return Course();
    }
}

//Returns linked list length
int LinkedList::getLength() {
    return length;
}