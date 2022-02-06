#ifndef LIST_HPP
#define LIST_HPP

#include <ostream>

template <typename T>
class list
{
private:
    class node;
public:
    typedef T value_type;
    typedef unsigned int size_type;
private:
    node* access_helper(const size_type& index) const;

public:
    size_type size() const;
    value_type access(const size_type& index) const;
    bool empty() const;
    void push_front(const value_type& value);
    void push_back(const value_type& value);
    void pop_front();
    void pop_back();
    void swap(node* n, node* p);
    void sort();

    template <int>
    friend std::ostream& operator<<(std::ostream& out, const list<int>& l);

    static void swap(T& a, T& b);

private:
    node* m_head;
    node* m_tail;

public:
    list();
    list(size_type n, const value_type& default_value);
    list(const list& b);
    const list& operator=(const list& c);
    ~list();
};

#endif
