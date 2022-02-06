#include "list.hpp"

#include <iostream>
#include <cassert>
template <typename T>
class list<T>::node
{
public:
    value_type m_value;
    node* m_next;
    node* m_prev;

public:
    node(value_type v, node* n, node* p)
        : m_value(v)
        , m_next(n)
        , m_prev(p)
    {
    }

    ~node()
    {
    }
};

template <int>
std::ostream& operator<<(std::ostream& out, const list<int>& l)
{
    list<int>::node* current = l.m_head;
    while (current != nullptr) {
        out << current->m_value << " ";
        current = current->m_next;
    }
    return out;
}

template <typename T>
typename list<T>::size_type list<T>::size() const
{
    node* current = m_head;
    size_type count = 0;
    while (current != nullptr) {
        current = current->m_next;
        ++count;
    }
    return count;
}

template <typename T>
void list<T>::swap(node* n, node* p)
{
    value_type value = n->m_value;
    n->m_value = p->m_value;
    p->m_value = value;
}

template <typename T>
void list<T>::sort()
{
    node* current;
    bool swapped = true;

    while (swapped)
    {
        current = m_head;
        swapped = false;

        while (current != nullptr && current->m_next != nullptr)
        {
            T & curr_value = current->m_value;
            T & next_value = current->m_next->m_value;

            if (curr_value > next_value)
            {
                swap(curr_value, next_value);
                swapped = true;
            }
            current = current->m_next;
        }
    }
}

template<typename T>
void list<T>::swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
bool list<T>::empty() const
{
    return (m_head == nullptr);
}


template <typename T>
void list<T>::push_front(const value_type& value)
{
    node* new_node = new node(value, m_head, nullptr);
    if (m_head == nullptr) {
        m_head = new_node;
        m_tail = new_node;
    }
    else {
        m_head->m_prev = new_node;
        m_head = new_node;
    }
}


template <typename T>
void list<T>::push_back(const value_type& value)
{
    node* new_node = new node(value, nullptr, m_tail);
    if (m_head == nullptr) {
        m_head = new_node;
        m_tail = new_node;
    }
    else {
        m_tail->m_next = new_node;
        m_tail = new_node;
    }
}

template <typename T>
void list<T>::pop_front()
{
    assert(m_head != nullptr);
    node* n = m_head;
    m_head = m_head->m_next;
    delete n;
}

template <typename T>
void list<T>::pop_back()
{
    assert(m_tail != nullptr);
    if (m_tail == m_head) {
        m_head = nullptr;
        delete m_tail;
    }
    else {
        node* p = m_tail;
        m_tail = m_tail->m_prev;
        delete p;
    }
}

template <typename T>
typename list<T>::node* list<T>::access_helper(const size_type& index) const
{
    assert(index >= 0);
    assert(index < size());
    node* current = m_head;
    for (size_type i = 0; i < index; ++i) {
        assert(current != nullptr);
        current = current->m_next;
    }
    assert(current != nullptr);
    return current;
}

template <typename T>
typename list<T>::value_type list<T>::access(const size_type& index) const
{
    node* current = access_helper(index);
    assert(current != nullptr);
    return current->m_value;
}

template <typename T>
list<T>::list()
    : m_head(nullptr)
    , m_tail(nullptr)
{
    std::cout << "Default constructor" << std::endl;
}

template <typename T>
list<T>::list(size_type n, const value_type& default_value)
    : m_head(nullptr)
    , m_tail(nullptr)
{
    std::cout << "Constructor" << std::endl;
    for (size_type i = 0; i < n; ++i) {
        node* new_node = new node(default_value, nullptr, nullptr);
        if (m_tail != nullptr) {
            m_tail->m_next = new_node;
            m_tail->m_next->m_prev = m_tail;
        }
        else {
            assert(m_head == nullptr);
            m_head = new_node;
        }
        m_tail = new_node;
    }
}

template <typename T>
list<T>::list(const list& b)
{
    std::cout << "Copy constructor" << std::endl;
    while (!empty()) {
        pop_front();
    }
    node* current = b.m_head;
    while (current != nullptr) {
        node* new_node = new node(current->m_value, nullptr, nullptr);
        if (m_head != nullptr) {
            m_tail->m_next = new_node;
            m_tail->m_next->m_prev = m_tail;
        }
        else {
            m_head = new_node;
        }
        m_tail = new_node;
        current = current->m_next;
    }
}



template <typename T>
const list<T>& list<T>::operator=(const list& c)
{
    std::cout << "Assignment Operator" << std::endl;
    this->m_head = c.m_head;
    return *this;
}

template <typename T>
list<T>::~list()
{
    std::cout << "Destructor" << std::endl;
    while (!empty()) {
        pop_back();
    }
}
