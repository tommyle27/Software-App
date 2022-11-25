#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <stdio.h>
#include "Course.hpp"

using namespace std;

struct node {
    public:
        node(Course courseData = Course());
        Course data;
        node *next;
};

class LinkedList {
    private:
        node *list_head;
        node *list_tail;
        int length;
    public:
        LinkedList();
        void traverse();
        void insert(Course course);
        Course pop();
        int getLength();
        node search(string code);
};

#endif