#include <iostream>
using namespace std;

struct Node{
  int data;
  struct Node *next;
  Node(int d){
    data =d;
  }
  Node(){
    data = 0;
    next = NULL;
  }
};

struct LinkedList{
  Node * head;
  int size;
  LinkedList(){
    size = 0;
    head = NULL;
  }

  LinkedList(struct Node *i , int s){
    size = s;
    head = i;
  }

  void addFirst (struct Node * i){
    size ++;
    if (size == 1){
      head = i;
    } 
    else{ //Checar double pointer
      i -> next = head;
      head = i;
    }
  }

  void addLast (int f){
    Node *a = head;
    size ++;
    if (size == 1){
      head = new Node(f);
    }
    else{
      while(a -> next != NULL){ 
        a = a -> next; 
      }
      a -> next = new Node(f);
    }
  }

  void removeFirst(){
    Node *a = head;
    if (size == 0){ //para eliminar el espacio (1)
      cout << "ERROR" << endl;
    } 
    else{
      size--;
      head = head -> next;
      a = NULL;
      delete a;
    }
  }

  void removeLast(){
    Node *a = head;
    if (size == 0){
      cout << "ERROR" << endl;
    }
    else if(size == 1){
      size --;
      head = NULL;
    }
    else{
      size --;
      while(a -> next -> next != NULL){ 
        a = a -> next; 
      }
      a -> next = NULL;
    }
  }
  void print(){
    Node *a = head;
    while (a != NULL){
      cout << a -> data << " ";
      a = a -> next;
    }
  }
  void remove(int d){
    Node* aux= head;
    if (aux == NULL){
      return;
    }
    if(aux->data == d){
      head = head -> next;
      size --;
      return;
    }
    while(aux -> next != NULL){
      if(aux -> next -> data == d){
        aux -> next = aux -> next -> next;
        size --;
        return;
      }
      else{
        aux = aux -> next;
      }
    }
  }
};


