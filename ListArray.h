#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
	    T* arr;
	    int max;
	    int n;
	    static const int MINSIZE = 2;

	    void resize(int new_size){
		    T* new_arr = new [new_size];
		    for(int i = 0; i < n; i++){
			    new_arr[i] = arr[i];
		    }
		    delete[arr];
		    arr = new_arr;
		    max = new_size;
	    }

    public:
	    ListArray();
	    ~ListArray();

	    T operator[](int pos);
	    friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list);

	    void insert(int pos, T e) override {
		    if (pos < 0 || pos > n){
			    throw std::out_of_range("Posición inválida en insert()");
		    }
		    if (n == max){
			    resize(max * 2);
		    }
		    for (int i = n; i > pos; i--){
			    arr[i] = arr[i - 1];
		    }
		    arr[pos] = e;
		    n++;
	    }

	    void append(T e) override {
		    insert(n, e);
	    }
	    void prepend(T e) override {
		    insert(0, e);
	    }
};
