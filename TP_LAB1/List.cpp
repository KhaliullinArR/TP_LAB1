#include "List.h"
#include "ListException.h"


template< typename T >
List< T >::List() : m_head(nullptr) {
}

template< typename T >
List< T >::~List() {
    while (m_head) {
        remove();
    }
}
template< typename T >
void List< T >::append(const T& t) {

    if (m_head == nullptr) {
        m_head = new Node(t);
    }
    else {

        Node* cur = m_head;
        while (cur->m_next != nullptr) {
            cur = cur->m_next;
        }

        cur->m_next = new Node(t);
    }
}

template< typename T >
void List< T >::remove() {
    if (m_head) { 
        
        Node* newHead = m_head->m_next;

        
        delete m_head;

        
        m_head = newHead;
    }
    else throw NoElemsExecpetion();
}

template<typename T>
T List<T>::head() const
{
    return *m_head.m_t;
}

template< typename T >
typename List< T >::Iterator List< T >::begin() const {
    
    return Iterator(m_head);
}

template< typename T >
typename List< T >::Iterator List< T >::end() const {
   
    return Iterator(nullptr);
}

template< typename T >
size_t List< T >::size() const {
    size_t s = 0;
    for (Iterator it = begin(); it != end(); ++it) {
        ++s;
    }
    return s;
}
