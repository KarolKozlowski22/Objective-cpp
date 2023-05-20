#include "Node.h"
#include <algorithm>
#pragma once

using std::ostream;

template <typename T>
class PLinkedList{

    //overloaded << operator printing the list
    friend ostream & operator<<(ostream & out, const PLinkedList<T> & obj){
        Node<T>* temp=obj.head();
        while(temp){
            if(temp->getNext()){
                out << temp->getVal() << " -> ";
            }
            else{
                out << temp->getVal();
            }
            
            temp=temp->getNext();
        }
        return out;
    }

    private:
    Node<T>* _head;

    public:

    //basic constructor
    PLinkedList():_head(nullptr){}

    //loud copy constructor 
    PLinkedList(const PLinkedList & other){

        cout << "--- copying list: ";
        if(other._head==nullptr){
            _head=nullptr;
        }
        else{
            _head=new Node<T>(*other._head);
            Node<T>* current=head();
            Node<T>* othercurrent=other._head->getNext();
            while(othercurrent){
                current->setNext(new Node<T>(*othercurrent));
                current=current->getNext();
                othercurrent=othercurrent->getNext();
            }
        }
        cout << *this << "\n";

    }

    //loud move constructor
    PLinkedList(PLinkedList && other) noexcept{
        cout << "--- moving list: ";
        _head=std::move(other._head);
        other._head=nullptr;
        cout << *this << "\n";
    }


    //head getter
    Node<T>* head()const{
        return _head;
    }

    //function adding data to the front of the list
    PLinkedList & addFront(Node<T>* newNode){
        Node<T>* temp=new Node<T>(*newNode);
        temp->setNext(_head);
        _head=temp;
        return *this;
    }

    //copy assignment operator overloaded
    PLinkedList & operator=(const PLinkedList & other){
        
        if(this!=&other){
            Node<T> *temp=new Node<T>(other._head);
            std::swap(_head,temp._head);
            return *this;
        }
        return *this;

    }

    //move assignment operator overloaded 
    PLinkedList & operator=(PLinkedList && other) noexcept{
        if(this==&other){
            return *this;
        }
        _head=std::move(other._head);
        other._head=nullptr;
        return *this;

    }

    //destructor
    ~PLinkedList(){
        Node<T>* current=_head;
        while(current){
            Node<T>* next=current->getNext();
            delete current;
            current=next;
        }
    }

};