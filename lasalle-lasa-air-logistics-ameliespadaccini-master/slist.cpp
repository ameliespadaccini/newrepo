#include "slist.h"
#include <iostream>
using namespace std;

void LinkedList::add(Airport& port) {
     Node* newNode = new Node(port);
      if (head == nullptr)
      {
        newNode->next = head; 
        head = newNode;
      }
      else
      {
        Node* last = head; 

        while (last->next != nullptr) {
          last = last->next;
        }
        last->next = newNode;
      }
}


void LinkedList::toString() {
     Node* temp = head;
      int index = 0;
      while (temp) {
           cout << temp->data.code << " long: " << temp->data.longitude
                     << " lat: " << temp->data.latitude << endl;
           temp = temp->next;
           index++;
        }
     }

void LinkedList::insert(int position, const Airport& port) {
     Node* newNode = new Node(port);
        // at beginning
        if (position == 0 || head == nullptr) {
            newNode->next = head;
            head = newNode;
            return;
        }
     
      Node* temp = head;
      int index = 0;

      // inserts before position
      while (temp->next != nullptr && index < position - 1) {
          temp = temp->next;
          index++;
      }

      newNode->next = temp->next;
      temp->next = newNode;
     }
bool LinkedList::equals(LinkedList right) {
     int index = 0;
      Node* temp = head;
      Node* tempRight = right.head;
      while (temp->next != nullptr && tempRight->next != nullptr) {
        //cout << temp->data.longitude;
        //cout << tempRight->data.longitude;
        if (temp->data.longitude != tempRight->data.longitude)
          return false;
        temp = temp->next;
        //get tempRight next value
        index++;
      }
      return true;
    }
Airport LinkedList::get(int index) {
     int position = 0;
      Node* temp = head;
      while (temp->next != nullptr && position < index) {
          temp = temp->next;
          position++;
      }
      return temp->data;
    }

void LinkedList::swap(int index1, int index2) {
if (index1 > index2)
        { //making index 1 the smaller value
          int tempint = index2;
          index2=index1;
          index1=tempint;
        }
      int position = 0;
      Node* prev1 = head; //node before temp
      while (prev1->next != nullptr && position < index1-1) {
          prev1 = prev1->next;
          position++;
      }
      Node *temp = prev1->next;
      Node *next1 = temp->next;


      position =0 ;
      Node* prev2 = head; //node before temp
      while (prev2->next != nullptr && position < index2-1) {
          prev2 = prev2->next;
          position++;
      }
      Node* temp2 = prev2->next;
      Node* next2 = temp2->next;


      if (next2 != nullptr)
      {


        //Node* swapperTemp = temp;
        Node* swapperNext = next1;


        prev1->next = temp2;
        temp2->next = next1;


        prev2->next = temp;
        temp->next = next2;
      }
      else
      {
        //Node* swapperTemp = temp;


        prev1->next = temp2;
        temp2->next = next1;


        prev2->next = temp;
        temp->next = nullptr;
      }
}
    
void LinkedList::remove(int index){
    int position = 0;
          Node* prev = head;
      Node* at;
          while (prev->next != nullptr && position < index-1) {
              prev = prev->next;
              position++;
          }
      if (prev->next == nullptr){
        return;
      }
      at= prev->next; //at index where it needs to be removed
      if (at->next == nullptr){
        prev->next = nullptr;
        return;
    }
      prev->next = at->next;
    }


int LinkedList::size(){
      int count = 0;
        Node* prev = head;
      while (prev->next != nullptr) {
                prev = prev->next;
                count++;
            }
        return count;
      }


void LinkedList::clear(){
      head->next = nullptr;
    }


bool LinkedList::isEmpty(){
      if (head->next == nullptr){
        return true;
    }
    return false;
    }


LinkedList LinkedList::subList(int start, int length){
      LinkedList newList;
      int position = 0;
      Node* prev = head;
      while (position < start)
      {
        prev = prev->next;
        position++;
      }
      int index = 0;
      Node* first;
      first->data = prev->data;
      first->next = prev->next;
      while (first->next != nullptr && index < length-1) {
        if (index==0)
        {
          newList.head = first;
        }
        first = first->next;
        index++;
        //newList.toString();
      }
      first->next = nullptr;
      return newList;
    }