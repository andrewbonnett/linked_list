#pragma once
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "LinkedListInterface.h"

using namespace std;

template<typename T>

class LinkedList : public LinkedListInterface<T> {

    private:
        struct Node {
            Node(T val) {
                value = val;
                next = NULL;
            }
    
            T value;
            Node *next;
        };
        
        Node *head;
        int n = 0;

    
    public:
    
    	LinkedList() {
    	    head = NULL;
    	    n = 0;
    	}
    	
    	~LinkedList() {
    	    clear();
    	}
    
        void insertHead(T value) {
            if (find(value)) { return; }
                Node *u = new Node(value);
                if (n == 0) {
                    head = u;
                }
                else {
                    u->next = head;
                    head = u;
                }
                n++;
        }
    
    	void insertTail(T value) {
    	    if (find(value)) { return; }
        	    if (head == NULL || n == 0) {
        	        insertHead(value);
        	        return;
        	    }
        	    else {
        	        Node *u = new Node(value);
        	        u->next = NULL;
        	        Node* temp = head;
        	        while (temp->next != NULL) {
        	            temp = temp->next;
        	        }
        	        temp->next = u;
        	        n++;
        	    }
    	}
    
    	void insertAfter(T value, T insertionNode) {
    	    if (!find(insertionNode)) { return; }
    	    if (find(value)) { return; }
    	    
    	    Node *temp = head;
    	    while (temp != NULL) {
    	        if (temp->value == insertionNode) {
    	            Node *u = new Node(value);
    	            u->next = temp->next;
    	            temp->next = u;
    	            break;
    	        }
    	        temp = temp->next;
    	    }
    	    n++;
    	}
    
    	void remove(T value) {
    	    if (!find(value)) { return; }
    	    Node *temp = head;
    	    Node *hold = NULL;
    	    //check if the head contains the value we want to remove.
    	    if(head->value == value) {
    	        hold = temp;
    	        head = temp->next;
    	        delete hold;
    	        n--;
    	        return;
    	    }
    	    //check the rest of the list
    	    while (temp != NULL || temp->next != NULL) {
    	        if (temp->next->value == value) {
    	            hold = temp->next;
    	            temp->next = temp->next->next;
    	            delete hold;
    	            break;
    	        }
    	        temp = temp->next;
    	    }
    	    n--;
    	}
    
    	void clear() {
    	    while (head != NULL) {
                remove(head->value);
            }
            n = 0;
    	}
    
    	T at(int index) {
    	    if (index >= n || index < 0 || n == 0) { throw out_of_range("out_of_range");}
    	    else {
    	        Node *temp = head; //index 0;
    	        if (index == 0) {
    	            return temp->value;
    	        }
    	        for (int i = 1; i < index+1; i++) {
    	            temp = temp->next;
    	        }
    	        return temp->value;
    	        
    	    }
    	}
    
    	int size() {
    	    return n;
    	}
    
    	string toString() {
    	    stringstream ss;
    	    Node *temp = head;
    	    while (temp != NULL) {
                if (temp->next == NULL) {
                    ss << temp->value;
                }
                else {
                    ss << temp->value << " ";
                }
                temp = temp->next;
            }

    	    return ss.str();
    	}
    	
    	bool find(T value) {
    	    bool found = false;
    	    Node* temp = head;
    	    while (!found && temp != NULL) {
    	        if (temp->value == value) {
    	            found = true;
    	            break;
    	        }
    	        temp = temp->next;
    	    }
    	    return found;
    	}
    
};