#ifndef MYVECTOR_H
#define MYVECTOR_H
#include "contact.h"
template <typename T>
class MyVector
{
	private:
		T *data;						//pointer to int(array) to store elements
		int v_size;						//current size of vector (number of elements in vector)
		int v_capacity;					//capacity of vector
	public:
		//MyVector();						//Default Constructor
		MyVector(int cap=0);				//One Argument Constructor
		~MyVector();					//Destructor
		void push_back(T element);		//Add an element at the end of vector
		void insert(int index, T element); //Add an element at the index 
		void erase(int index);			//Removes an element from the index
		T& at(int index); 				//return reference of the element at index
		const T& front();				//Returns reference of the first element in the vector
		const T& back();				//Returns reference of the Last element in the vector
		int size() const;				//Return current size of vector
		int capacity() const;			//Return capacity of vector
		bool empty() const; 			//Return true if the vector is empty, False otherwise
		void shrink_to_fit();			//Reduce vector capacity to fit its size
		void display();
		friend class ContactBST;
};
#endif
