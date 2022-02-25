#ifndef TEMPLATE
#define TEMPLATE
#include "ListException.h"

template< typename T >
class List {
private:
    
    struct Node;

public:
    
    class Iterator {
    public:
        Iterator(Node* node) : m_node(node) { }

        
        bool operator==(const Iterator& other) const {
            if (this == &other) {
                return true;
            }
            return m_node == other.m_node;
        }

        
        bool operator!=(const Iterator& other) const {
            return m_node !=(other.m_node);
        }

       
        T& operator*() const {
            if (m_node) {
                return m_node->m_t;
            }
            else throw NoElemsExecpetion();
        }

        
        void operator++() {
            if (m_node) {
                m_node = m_node->m_next;
            }
            else throw NoElemsExecpetion();
        }

    private:
        Node* m_node;
       
    };

public:
    List();

    ~List();

    
    void append(const T& t);

    
    void remove();

   
    T head() const;

    
    Iterator begin() const;

    
    Iterator end() const;

    
    size_t size() const;

private:
    
    struct Node {
        Node() : m_next(nullptr) { }

        Node(const T& t) : m_t(t), m_next(nullptr) { }

       
        T m_t;

       
        Node* m_next;
    };

   
    Node* m_head;

};



#endif
