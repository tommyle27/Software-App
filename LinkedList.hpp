#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <stdio.h>
#include "Course.hpp"

using namespace std;

//Declare linked list only structure node
struct node {
    public:
        node(Course courseData = Course());
        Course data;
        node *next;
};

class LinkedList {
    //Declare course variables and methods
    private:
        node *list_head;
        node *list_tail;
        int length;
    public:
        LinkedList();
        void insert(Course course);
        Course pop();
        int getLength();
};

#endif