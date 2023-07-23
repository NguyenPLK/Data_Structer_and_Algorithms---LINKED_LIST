#include "Linked_List_Class.h"

Linked_list::Linked_list()
{
    head = NULL;
    tail = NULL;
};

Linked_list::Node *Linked_list::Create_a_node(const Student &student)
{
    Node *temp_ptr = new Node;

    temp_ptr->m_student.set_ID(student.get_ID());
    temp_ptr->m_student.set_last_name(student.get_last_name());
    temp_ptr->m_student.set_first_name(student.get_first_name());
    temp_ptr->m_student.set_room_number(student.get_room_number());

    return temp_ptr;
};

void Linked_list::Print_list(const std::string &ID_number)
{
    Node *search_ptr = Linked_list::head;

    while (search_ptr != NULL && (search_ptr->m_student.get_ID() != ID_number))
    {
        search_ptr = search_ptr->next;
    }
    if (search_ptr == NULL)
    {
        std::cout << "No ID Student is included !\n";
        return;
    }
    else
    {

        std::cout << "Student name: " << search_ptr->m_student.get_first_name() << " " << search_ptr->m_student.get_last_name() << std::endl;
        std::cout << "Student ID number: " << search_ptr->m_student.get_ID() << std::endl;
        std::cout << "Student room number: " << search_ptr->m_student.get_room_number() << std::endl;
    }
};

void Linked_list::Insert_first_processing(const Student &student)
{
    Node *creation_ptr = Create_a_node(student);

    creation_ptr->next = Linked_list::head;
    Linked_list::head = creation_ptr;

    if (Linked_list::tail != NULL)
        return;
    else
        Linked_list::tail = creation_ptr;
};

void Linked_list::Insert_last_processing(const Student &student)
{
    Node *creation_ptr = Create_a_node(student);
    creation_ptr->next = NULL;

    if (Linked_list::head == NULL)
    {
        Insert_first_processing(student);
    }
    else
    {
        Node *temp_ptr = Linked_list::tail;
        temp_ptr->next = creation_ptr;
        Linked_list::tail = creation_ptr;
    }
};

void Linked_list::Insert_depend_on_index(const uint32_t &ordinal_number, const Student &student)
{
    Node *creation_ptr = Create_a_node(student);
    creation_ptr->next = NULL;

    if (Linked_list::head == NULL)
    {
        Insert_first_processing(student);
    }
    else
    {
        Node *temp_ptr = Linked_list::tail;
        temp_ptr->next = creation_ptr;
        Linked_list::tail = creation_ptr;
    }
};