#include "contactbst.h"
using namespace std;

//=============================================================
ContactBST::ContactBST()
{
   this->root = NULL;
}

//=============================================================
ContactBST::~ContactBST()
{
   // destructor
   while(root){
      remove(root, root->key);
   }
   
}


//=============================================================
Node* ContactBST::getRoot()
{
   return this->root;
}

//=============================================================
void ContactBST::add(Node* ptr,string key, Contact *data)
{
   // first search for the key in the tree

   Node* tem = searchFor(ptr, key);

   if (tem != nullptr){ // if the key is found
      tem->contactVector.push_back(data); // add the data to the vector
      return;
   }
   else{ // if the key is not found
      if (this->root == NULL){ // if the tree is empty
         this->root = new Node(key, data); // create a new node and make it the root
         return;
      }
      else if (key < ptr->key){ // if the key is less than the current node's key
         if (ptr->left == NULL){ // if the left child is NULL
            ptr->left = new Node(key, data); // create a new node and make it the left child
            ptr->left->parent = ptr; // set the parent of the new node to the current node
            return;
         }
         else{ // if the left child is not NULL
            add(ptr->left, key, data); // add the key to the left subtree
         }
      }
      else{ // if the key is greater than the current node's key
         if (ptr->right == NULL){ // if the right child is NULL
            ptr->right = new Node(key, data); // create a new node and make it the right child
            ptr->right->parent = ptr; // set the parent of the new node to the current node
            return;
         }
         else{ // if the right child is not NULL
            add(ptr->right, key, data); // add the key to the right subtree
         }
      }

   }
}

//=============================================================
Node* ContactBST::findMin(Node* ptr)
{
   if (ptr == nullptr){
      return nullptr;
   }

   Node *temp = ptr;
   while (temp->left != nullptr){
      temp = temp->left;
   }
   return temp;
   
}

//=============================================================


void ContactBST::remove(Node* ptr, string key)
{  
    Node* temp = searchFor(ptr, key); // search for the key in the tree
    if (temp == nullptr){
        cout << "record not found" << endl;
        return;
    }

    if (temp->left == nullptr && temp->right == nullptr){ // if the node is a leaf
        if (temp->parent != nullptr) { // check if temp has a parent
            if (temp->parent->left == temp){ // if the node is the left child of its parent
                temp->parent->left = nullptr; // set the parent's left child to NULL
            }
            else{ // if the node is the right child of its parent
                temp->parent->right = nullptr; // set the parent's right child to NULL
            }
        }
        else { // if temp does not have a parent, it is the root node
            root = nullptr; // set the root to NULL
        }
        for(int i = 0; i < temp->contactVector.size(); i++) {
         delete temp->contactVector.at(i); // Delete each Contact object
         }
         delete temp; // delete the node
    }
    else if (temp->left == nullptr){ // if the node has only a right child
        if (temp->parent != nullptr) { // check if temp has a parent
            if (temp->parent->left == temp){ // if the node is the left child of its parent
                temp->parent->left = temp->right; // set the parent's left child to the node's right child
                temp->right->parent = temp->parent; // set the right child's parent to the node's parent
            }
            else{ // if the node is the right child of its parent
                temp->parent->right = temp->right; // set the parent's right child to the node's right child
                temp->right->parent = temp->parent; // set the right child's parent to the node's parent
            }
        }
        else { // if temp does not have a parent, it is the root node
            root = temp->right; // set the root to the node's right child
            temp->right->parent = nullptr; // set the right child's parent to NULL
        }
        for(int i = 0; i < temp->contactVector.size(); i++) {
            delete temp->contactVector.at(i); // Delete each Contact object
        }
        delete temp; // delete the node
    }
    else if (temp->right == nullptr){ // if the node has only a left child
        if (temp->parent != nullptr) { // check if temp has a parent
            if (temp->parent->left == temp){ // if the node is the left child of its parent
                temp->parent->left = temp->left; // set the parent's left child to the node's left child
                temp->left->parent = temp->parent; // set the left child's parent to the node's parent
            }
            else{ // if the node is the right child of its parent
                temp->parent->right = temp->left; // set the parent's right child to the node's left child
                temp->left->parent = temp->parent; // set the left child's parent to the node's parent
            }
        }
        else {
            root = temp->left; // set the root to the node's left child
            temp->left->parent = nullptr; // set the left child's parent to NULL
        }
        for (int i = 0; i < temp->contactVector.size(); i++) {
            delete temp->contactVector.at(i); // Delete each Contact object
        }
         delete temp; // delete the node
    }

    else if (temp->right!=nullptr && temp->left!=nullptr){
         Node* min = findMin(temp->right);
         temp->key = min->key;
         while(temp->contactVector.size()>0)
         {
             delete temp->contactVector.at(0); // Delete each Contact object
             temp->contactVector.erase(0);
         }
         for(int i=0; i<min->contactVector.size(); i++)
         {
            Contact* data = min->contactVector.at(i);
            temp->contactVector.push_back(data);
            //temp->contactVector.push_back(min->contactVector.at(i));
         }
         remove(temp->right, min->key);
    }
}
   

//=============================================================
void ContactBST::update(string key)
{
   Node* temp = searchFor(this->root, key); // search for the key in the tree
    if (temp != NULL){ // if the key is found
        temp->print(); // print the node
        
        
        int num;
        cout << "Enter the number of the record you want to edit: ";
        cin >> num;
        cin.ignore(); // ignore the newline character left in the input buffer
        if (num > 0 && num <= temp->contactVector.size()){ // if the number is valid
            Contact* ct = temp->contactVector.at(num-1); // get the contact at the index
            cout << "Which Field do you want to edit?" << endl;
            cout << "1. First Name 2. Last Name 3.Email 4. Phone 5. City 6. Country : ";
            // int choice;
            // cin >> choice;
            int choiceNum;
            cin >> choiceNum;
            cin.ignore(); // ignore the newline character left in the input buffer
            string newValue;
            // string choice;
            // getline(cin, choice);
            // int choiceNum = stoi(choice);
            switch(choiceNum){
                case 1:
                    cout << "Enter the new first name: ";
                    getline(cin, newValue); // get the new first name
                    ct->fname = newValue; // update the first name
                    //cin >> ct->fname; // update the first name
                    break;
                case 2:
                    cout << "Enter the new last name: ";
                    cin >> ct->lname; // update the last name
                    break;
                case 3:
                    cout << "Enter the new email: ";
                    getline(cin, newValue); 
                    ct->lname = newValue;
                    break;
                case 4:
                    cout << "Enter the new phone number: ";
                    getline(cin, newValue); 
                    ct->phone = newValue;
                    break;
                case 5:
                    cout << "Enter the new city: ";
                    getline(cin, newValue); 
                    ct->city = newValue;
                    break;
                case 6:
                    cout << "Enter the new country: ";
                    getline(cin, newValue); 
                    ct->country = newValue;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
            }

        }
        else{ // if the number is not valid
            cout << "Invalid number!" << endl;
        }
    }
    else{ // if the key is not found
        cout << "Contact not found!" << endl;
    }
}

//=============================================================
Node* ContactBST::searchFor(Node* ptr,string key)
{
   if (ptr == NULL) // if the tree is empty
   {
      return NULL; // return NULL
   }
   else if (key == ptr->key) // if the key is found
   {
      return ptr; // return the node
   }
   else if (key < ptr->key) // if the key is less than the current node's key
   {
      return searchFor(ptr->left, key); // search the left subtree
   }
   else // if the key is greater than the current node's key
   {
      return searchFor(ptr->right, key); // search the right subtree
   }
   return NULL;
}

//=============================================================


bool ContactBST::markFav(string key)
{
   Node* ptr = searchFor(this->root, key);

   if (ptr != NULL){
      ptr->print();

      
      cout << "Enter the number of the record you want to mark as favorite: ";
      
      string num;
      getline(cin, num);
      int num1 = stoi(num);

      if (num1 > 0 && num1 <= ptr->contactVector.size()){
         ptr->contactVector.at(num1-1)->isFav = true;
         return true;
      }
      else{
         cout << "Invalid number!" << endl;
         return false;
      }
   }
   else{
      cout << "Contact not found!" << endl;
      return false;
   }
}

//=============================================================
bool ContactBST::unmarkFav(string key)
{
   Node* ptr = searchFor(this->root, key);

   if (ptr != NULL){
      ptr->print();

      // MyVector<Contact*> temp = ptr->getData();
      cout << "Enter the number of the record you want to unmark as favorite: ";
      // int num;
      // cin >> num;
      string num;
      getline(cin, num);
      int num1 = stoi(num);

      if (num1 > 0 && num1 <= ptr->contactVector.size()){
         ptr->contactVector.at(num1-1)->isFav = false;
         return true;
      }
      else{
         cout << "Invalid number!" << endl;
         return false;
      }
   }
   else{
      cout << "Contact not found!" << endl;
      return false;
   }
}

//=============================================================
void ContactBST::printASC(Node* ptr)
{
   if (ptr == nullptr){
      return;
   }
   printASC(ptr->left);
   // printnode2(ptr);
   ptr->print2(cout);
   printASC(ptr->right);
}

//=============================================================
void ContactBST::printDES(Node* ptr)
{
   if (ptr == nullptr){
      return;
   }
   printDES(ptr->right);
   ptr->print2(cout);
   printDES(ptr->left);
}

//=============================================================
void ContactBST::printFav(Node* ptr)
{
   Node* ptr1 = ptr;
   if (ptr1 == NULL){
      return;
   }
   printFav(ptr1->left);
   //MyVector<Contact*> temp = ptr->getData();
   for (int i = 0; i < ptr1->contactVector.size(); i++){
      if (ptr1->contactVector.at(i)->isFav){
         cout << ptr1->contactVector.at(i)->fname << " " << ptr1->contactVector.at(i)->lname << " " << ptr1->contactVector.at(i)->email << " " << ptr1->contactVector.at(i)->phone << " " << ptr1->contactVector.at(i)->city << " " << ptr1->contactVector.at(i)->country << " " << ptr1->contactVector.at(i)->isFav << endl;
      }
   }
   printFav(ptr1->right);
}

//=============================================================
int ContactBST::importCSV(string path)
{
   ifstream myfile(path, ios::in);
   if(myfile.fail()){
         cout<<"File not found!"<<endl;
         return 0;
   }
   int count = 0; // count the number of contacts
   string line;
   bool fave;
   while(getline(myfile, line)){
        stringstream ss(line);
        string fname, lname, email, phone, city, country;
        getline(ss, fname, ',');
        getline(ss, lname, ',');
        getline(ss, email, ',');
        getline(ss, phone, ',');
        getline(ss, city, ',');
        getline(ss, country, ',');
        getline(ss, line, ',');
        if (line == "1"){
            fave = true;
        }
        else{
            fave = false;
        }
        Contact* ct = new Contact(fname, lname, email, phone, city, country, fave);
        string nodekey = (fname + " " + lname);
		   add(root, nodekey, ct);
        count++;
   }
   myfile.close();
   return count;
}

//=============================================================
int ContactBST::exportCSV(Node* ptr, ostream& file)
{
   if (ptr == nullptr){
        return 0;
    }
    else{
        int count = 0;
         count += exportCSV(ptr->left, file);
         MyVector<Contact*> temp = ptr->getData();
         for (int i = 0; i < temp.size(); i++){
             Contact *ct = temp.at(i);
             file<<ct->fname<<","<<ct->lname<<","<<ct->email<<","<<ct->phone<<","<<ct->city<<","<<ct->country<<","<<ct->isFav<<endl;
             count++;
         }
         count += exportCSV(ptr->right, file);
         return count;

      
    }
}

//=============================================================
void ContactBST::printnode(Node* ptr){
    MyVector<Contact*> temp = ptr->getData();
    for (int i = 0; i < temp.size(); i++){
        Contact *ct = temp.at(i);
        cout<<" "<<i+1<<". "<<ct->fname<<","<<ct->lname<<","<<ct->email<<","<<ct->phone<<","<<ct->city<<","<<ct->country<<","<<ct->isFav<<endl;

        // cout << i+1 << ". " << temp.at(i)->fname << " " << temp.at(i)->lname << endl;
    }
}

