#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
  private:
    Node<T>* first;
    int n;

  public:
    ListLinked() {
      first = nullptr;
      n = 0;
    }
    
    ~ListLinked() {
      Node<T>* aux;
      while(first != nullptr){
        aux = first->next;
        delete first;
        first = aux;
      }
      n = 0;
    }

    T operator[](int pos){
      if (pos < 0 || pos >= n){
        throw std::out_of_range("Posición invalida");
      }
      Node<T>* aux = first;
      for (int i = 0; i < pos; i++){
        aux = aux -> next;
      }
      return aux->data;
    }

    friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
      Node<T>* aux = list.first;
      out << "[";
      while (aux != nullptr){
        out << aux->data;
        if (aux->next != nullptr){
          out << ",";
        }
        aux = aux->next;
      }
      out << "]";
      return out;
    }

    void insert(int pos, T e) override{
      if (pos < 0 || pos > n){
        throw std::out_of_range("Posición inválida");
      }
      if (pos == 0){
        first = new Node<T>(e, first);
      }
      else{
        Node<T>* aux = first;
        for(int i = 0; i < pos-1; i++){
          aux = aux->next; 
        }
        aux->next = new Node<T>(e, aux->next);
      }
      n++;
    }

    void append(T e) override{
      insert(n, e);
    }

    void prepend(T e) override{
      insert(0, e);
    }

    T remove(int pos) override{
      if (pos < 0 || pos >= n){
        throw std::out_of_range("Posición invalida");
      }
      T removeData;
      Node<T>* aux;
      if (pos == 0){
        aux = first;
        removeData = first->data;
        first = first->next;
      }
      else{
        Node<T>* prev = first;
        for(int i = 0; i < pos-1; i++){
          prev = prev->next;
        }
        aux = prev->next;
        removeData = aux->data;
        prev->next = aux->next;
      }
      delete aux;
      n--;
      return removeData;
    }
    
    T get(int pos) override{
      if (pos < 0 || pos >= n){
        throw std::out_of_range("Posición invalida");
      }
      Node<T>* aux = first;
      for(int i = 0; i < pos; i++){
        aux = aux->next;
      }
      return aux->data;
    }
    
    int search(T e) override{
      Node<T>* aux = first;
      int pos = 0;
      while(aux != nullptr){
        if (aux->data == e){
          return pos;
        }
        aux = aux->next;
        pos++;
      }
      return -1;
    }

    bool empty() override{
      return n == 0;
    }

    int size() override{
      return n;
    }
};
