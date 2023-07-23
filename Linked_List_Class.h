#ifndef LINKED_LIST
#define LINKED_LIST

#include "Student_info.h"
#include <iostream>
#include <string>

class Linked_list
{
public:
    struct Node
    {
        Student m_student;
        Node *next;
    };

public:
    Linked_list();
    ~Linked_list(){};
    void Print_list(const std::string &);
    Node *Create_a_node(const Student &);
    void Insert_last_processing(const Student &);
    void Insert_first_processing(const Student &);
    void Insert_depend_on_index(const uint32_t &, const Student &);

private:
    Node *head;
    Node *tail;
};
#endif