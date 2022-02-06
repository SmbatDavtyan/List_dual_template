
#include "list.cpp"

#include <iostream>
#include <cassert>

void test_default_constructor()
{
    list<int> l;
    assert(l.empty());
    assert(l.size() == 0);
    list<int>* p = new list<int>;
    assert(p->empty());
    assert(p->size() == 0);
    delete p;
}

void test_constructor()
{
    list<int> l(6, 0);
    assert(!l.empty());
    assert(l.size() == 6);
}

void test_push_back()
{
    list<int> l;
    assert(l.empty());
    for (list<int>::size_type i = 0; i < 8; ++i) {
        l.push_back(2 * i);
    }
    assert(l.size() == 8);
}

void test_push_front()
{
    list<int> l;
    assert(l.empty());
    for (list<int>::size_type i = 0; i < 8; ++i) {
        l.push_front(2 * i);
    }
    assert(l.size() == 8);
}

void test_pop_back()
{
    list<int> l(5, 89);
    assert(l.size() == 5);
    while (!l.empty()) {
        l.pop_back();
    }
}

void test_pop_front()
{
    list<int> l(89, 5);
    assert(l.size() == 89);
    while (!l.empty()) {
        l.pop_front();
    }
}

void test_sort()
{
    list<int> l;
    assert(l.empty());
    for (list<int>::size_type i = 0; i < 8; ++i) {
        l.push_front(2 * i);
    }
    l.sort();
    assert(l.size() == 8);
    for (list<int>::size_type i = 0; i < 8; ++i) {
        assert(l.access(i) == int(i * 2));
    }
}

void test_copy_constructor()
{
    list<int> b(5, 0);
    assert(b.size() == 5);
    list<int> a(b);
    assert(a.size() == 5);
    for (list<int>::size_type i = 0; i < a.size(); ++i) {
        assert(a.access(i) == 0);
    }
}

int main()
{
    test_default_constructor();
    test_constructor();
    test_push_back();
    test_push_front();
    test_pop_back();
    test_pop_front();
    test_copy_constructor();
    test_sort();
    return 0;

}
