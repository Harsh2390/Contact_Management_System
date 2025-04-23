#include "myvector.h"
#include "contact.h"

using namespace std;

template <typename T>
MyVector<T>::MyVector(int cap)
{
    v_size = 0;
    v_capacity = cap;
    data = new T[v_capacity];
}


template <typename T>
MyVector<T>::~MyVector()
{
    delete [] data;
}

template <typename T>
void MyVector<T>::push_back(T element)
{
    if (v_capacity == 0){
        v_capacity = 1;
        data = new T[v_capacity];
        data[0] = element;
        v_size++;
    }else if (v_size == v_capacity){
        v_capacity *= 2;
        T *temp = new T[v_capacity];
        for (int i = 0; i < v_size; i++){
            temp[i] = data[i];
        }
        delete [] data;
        data = temp;
        data[v_size] = element;
        v_size++;
    }

  
}

template <typename T>
void MyVector<T>::insert(int index, T element)
{
  if(index < 0 || index > v_size){
      cout << "Index out of range" << endl;
      exit(1);
  }
  if(v_size == v_capacity){ // if the vector is full
      v_capacity *= 2; // double the capacity
      T* temp = new T[v_capacity];
      for(int i = 0; i < v_size; i++){
          temp[i] = data[i];
      }
      delete[] data;
      data = temp;
  }
  for (int i = v_size; i > index; i--){
        data[i] = data[i-1];
  }
  data[index] = element;
    v_size++;
}

template <typename T>
void MyVector<T>::erase(int index)
{
  if (index < 0 || index >= v_size){
      cout << "Index out of range" << endl;
      exit(1);
  }
  for (int i = index; i < v_size; i++){
      data[i] = data[i+1];
  }
    v_size--;
}

template <typename T>
T& MyVector<T>::at(int index)
{
  	if (!empty()){
		if(index < 0 || index >= v_size){ // if the index is out of range
			cout << "Index out of range" << endl;
			exit(1);
		}
		return data[index];

	}
	else{
		cout << "Vector is empty" << endl;
		exit(1);
	}
}   

template <typename T>
const T& MyVector<T>::front()
{
    if (!empty()){
		return data[0];
	}
	else{
		cout << "Vector is empty" << endl;
		exit(1);
	}
  
}   

template <typename T>
const T& MyVector<T>::back()
{
    if (!empty()){
		return data[v_size-1];
	}
	else{
		cout << "Vector is empty" << endl;
		exit(1);
	}
  
}

template <typename T>
int MyVector<T>::size() const
{
    return v_size;
  
}

template <typename T>
int MyVector<T>::capacity() const
{
    return v_capacity;
  
}

template <typename T>
bool MyVector<T>::empty() const
{
    if (v_size == 0){
        return true;
    }
    return false;
  
}   

template <typename T>
void MyVector<T>::shrink_to_fit()
{
    if(v_size == 0){
		v_capacity = 0;
		delete[] data;
	}
	else{
		v_capacity = v_size;
		T* temp = new T[v_capacity];
		for(int i = 0; i < v_size; i++){
			temp[i] = data[i];
		}
		delete[] data;
		data = temp;
	}
  
}

template <typename T>
void MyVector<T>::display()
{
    for (int i = 0; i < v_size; i++){
        cout << data[i] << endl;
    }
  
}


template class MyVector<Contact *>;