#include "List_int.h"

struct List_int::Impl {
    std::vector<int> v;
};

List_int::List_int()  {
    pimpl = new Impl;
}

List_int::List_int(const List_int &l) {
    pimpl = new Impl;
    pimpl->v = l.pimpl->v;
}

List_int::~List_int() {
    delete pimpl;
}

void List_int::prepend(int el) {
    pimpl->v.resize(pimpl->v.size()+1);
    for(int i = pimpl->v.size() - 1; i > 0; i--)
        pimpl->v[i] = pimpl->v[i - 1];
    pimpl->v[0] = el;
}

void List_int::append(int el) {
    pimpl->v.push_back(el);
}

void List_int::stampa() const {
    for(auto e: pimpl->v)
        std::cout << e << std::endl;
}