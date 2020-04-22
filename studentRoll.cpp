#include <string>
#include "studentRoll.h"
#include <sstream>
#include <iostream>
using namespace std;

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
    if(head == NULL && tail == NULL){
        head = tail = new Node();
    } else{
        tail->next = new Node();
        tail = tail->next;
    }
    tail->next = 0;
    tail->s = new Student(s);
}

std::string StudentRoll::toString() const {
    std::stringstream oss;
    oss<<"[";
    for(Node* p = head; p; p = p->next){
        if(p != head){
            oss << ",";
        }
        oss << p->s->toString();
    }    
    oss << "]";
  return oss.str();
}
 
StudentRoll::StudentRoll(const StudentRoll &orig) {
    if(orig.head == NULL){
        head = tail = NULL;
        return;
    }
    Node* temp = orig.head;
    Node* link = new Node();
    head = link;
    while(temp && temp->next){
        link->next= new Node();
        link->s = new Student(*temp->s);
        link = link->next;
        temp = temp->next;
    }
    link->s = new Student(*temp->s);
    link->next = 0;
    tail = link;
}


StudentRoll::~StudentRoll() {
    Node* p(head),* t;    
    while(p) {
        t = p;
        p = p->next;
        delete t->s;
        delete t;
    }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
    
    StudentRoll* temp = new StudentRoll(right);
    swap(head,temp->head);
    swap(tail,temp->tail);
    delete temp;

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}
