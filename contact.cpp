#include "contact.h"
#include<iostream>

using namespace std;

Contact::Contact(string fname, string lname, string email, string phone, string city, string country, bool isFav){
    this->fname = fname;
    this->lname = lname;
    this->email = email;
    this->phone = phone;
    this->city = city;
    this->country = country;
    this->isFav = isFav;
}


