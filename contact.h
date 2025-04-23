#ifndef CONTACT_H
#define CONTACT_H

#include<iostream>
using namespace std;

class Contact
{
	private:
		string fname;
		string lname;
		string email;
		string phone;
		string city;
		string country;
		bool isFav;

	public:
		//bool isFav;
		Contact(string fname, string lname, string email, string phone, string city, string country, bool isFav);
		friend class Node;
		friend class ContactBST;
		template <typename T>
		friend class MyVector;	
};

#endif

