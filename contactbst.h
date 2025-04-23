#ifndef ContactBST_H
#define ContactBST_H

#include<iostream>
#include "myvector.h"
#include "contact.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


class Node
{
	private:
		string key;
		MyVector<Contact*> contactVector;
		Node* left;
		Node* right;
		Node* parent;
	public:
		//Node(string key, MyVector<Contact> *contactVector);
		Node(string key, Contact *data): key(key),left(nullptr),right(nullptr),parent(nullptr) {contactVector.push_back(data);}
		
		string getKey() { return this->key;}
		MyVector<Contact*> getData() { return this->contactVector;}
		void print()		//print with numberings
		{
			cout<<contactVector.size()<<" records found:"<<endl;
			for(int i=0; i<contactVector.size(); i++)
			{
				Contact *ct = contactVector.at(i);
				cout<<" "<<i+1<<". "<<ct->fname<<","<<ct->lname<<","<<ct->email<<","<<ct->phone<<","<<ct->city<<","<<ct->country<<","<<ct->isFav<<endl;
			}
		}
		void print2(ostream &os)		//print without numberings
		{
			for(int i=0; i<contactVector.size(); i++)
			{
				Contact *ct = contactVector.at(i);
				os<<ct->fname<<","<<ct->lname<<","<<ct->email<<","<<ct->phone<<","<<ct->city<<","<<ct->country<<","<<ct->isFav<<endl;
			}
		}
		friend class ContactBST;
};


//=============================================================================
class ContactBST
{
	private:
		Node* root;
	public:
		ContactBST();									//constructor
		~ContactBST();									//destructor
		//void destroy(Node* ptr);						//destructor helper function (recursive
		Node* getRoot();						//returns the root of the Tree
		void add(Node* ptr,string key, Contact *data);		//add key into tree/subtree with root ptr
		void update(string key); 	//Edit the node with key
		void remove(Node* ptr,string key);		//Delete a node with key from the tree/subtree with root
		void printnode(Node* ptr);		//Print the data at the node with key
		
		Node* searchFor(Node* ptr,string key);		//Find and returns the node with key
		bool markFav(string key);  				//Mark a contact as favorite 
		bool unmarkFav(string key);  //Unmark a contact as favorite 
		void printASC(Node* ptr);		//Recursive method that prints the data at nodes in an ascending order
		void printDES(Node* ptr);		//Recursive method that prints the data at nodes in a descending order
		void printFav(Node* ptr);           //Print the favorite data at nodes in an ascending order
		int importCSV(string path); //Load all the contacts from the CSV file to the BST
		int exportCSV(Node* ptr,ostream& file); //Export all the contacts from the BST to a CSV file in an ascending order
	private:
		Node* findMin(Node* ptr);					//Needed for remove method
};
#endif
