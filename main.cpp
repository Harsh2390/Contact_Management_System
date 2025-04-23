#include<sstream>
//=================================================================================
#include<iostream>
#include<cstdlib>
#include<fstream>
#include "myvector.h"
#include "contact.h"
#include "contactbst.h"
#include <string>



//==========================================================
void listCommands()
{
	cout<<"----------------------------------"<<endl;
	cout<<"import <path>      :Import contacts from a CSV file"<<endl
		<<"export <path>      :Export contacts to a CSV file"<<endl
		<<"add                :Add a new contact"<<endl
		<<"update <key>       :Update a contact's details"<<endl
		<<"remove <key>       :Delete a contact"<<endl
		<<"searchFor <key>    :Search for a contact"<<endl
		<<"markFav <key>      :Mark as favourite"<<endl
		<<"unmarkFav <key>    :Unmark as favourite"<<endl
		<<"printASC           :Print contacts in ascending order"<<endl
		<<"printDES           :Print contacts in descending order"<<endl
		<<"printFav           :Print all favourite contacts"<<endl
		<<"help               :Display the available commands"<<endl
		<<"exit               :Exit the program"<<endl;
}
//==========================================================

// to be completed with ALL the necessary method definitions

//==========================================================
int main(void)
{
	ContactBST contactbst;
	string command;
	string key;
	string user_input;
	listCommands();

	while(true){
		
		cout << "Enter a command: ";
		getline(cin, user_input);

		stringstream sstr(user_input);
		getline(sstr , command, ' ');
		getline(sstr , key);

		Node *root = contactbst.getRoot();

		if (command == "import"){
			int count = contactbst.importCSV(key);
			cout << count << " contacts imported." << endl;
		}
		else if (command == "export"){
			ofstream outfile(key);
			int count = contactbst.exportCSV(root, outfile);
			cout << count << " contacts exported." << endl;
			outfile.close();
			//contactbst.exportCSV(root,outfile);
		}
		else if (command == "add"){
			cout << "Enter the contact details: " << endl;
			string fn, ln, em, ph, city, cu, fav;
			bool isfav;

			cout << "First Name: ";
			getline(cin, fn);
			cout << "\nLast Name: ";
			getline(cin, ln);
			do {
				cout << "\nEmail: ";
				getline(cin, em);
				if (em.find("@") == string::npos || em.find(".") == string::npos)
				{
					cout << "Invalid email. Please try again." << endl;
				}
			} while (em.find("@") == string::npos || em.find(".") == string::npos);
			

			do {
				cout << "\nPhone: ";
				getline(cin, ph);

				if (ph.find_first_not_of("0123456789+") != string::npos) {
					cout << "Invalid phone number. Please try again." << endl;
				}
			} while (ph.find_first_not_of("0123456789+") != string::npos);
			
			cout << "\nCity: ";
			getline(cin, city);
			cout << "\nCountry: ";
			getline(cin, cu);

			do {
				cout << "\nIs Favorite? (Y/N): ";
				// string fav;
				getline(cin, fav);

				if (fav != "Y" && fav != "y" && fav != "N" && fav != "n")
				{
					cout << "Invalid input. Please try again." << endl;
				}
			
			} while (fav != "Y" && fav != "y" && fav != "N" && fav != "n");
			
			if (fav == "Y" || fav == "y")
				isfav = true;
			else
				isfav = false;


			Contact* ct = new Contact(fn, ln, em, ph, city, cu, isfav);
			string nodekey = (fn + " " + ln);
			contactbst.add(root, nodekey, ct);
		}
		else if (command == "update"){
			contactbst.update(key);
		}
		else if (command == "remove"){
			contactbst.remove(root,key);
		}
		else if (command == "searchFor"){
			// contactbst.searchFor(root,key);
			Node* node = contactbst.searchFor(root,key);
			if (node != NULL){
				cout << "Contact found!" << endl;
				contactbst.printnode(node);
			}
			else
				cout << "Contact not found!" << endl;
		}
		else if (command == "markFav"){
			bool tem = contactbst.markFav(key);
			if (tem){
				cout << "Contact marked as favourite." << endl;
			}
		}
		else if (command == "unmarkFav"){
			bool tem = contactbst.unmarkFav(key);
			if (tem){
				cout << "Contact unmarked as favourite." << endl;
			}
		}
		else if (command == "printASC"){
			if (root == NULL){
				cout << "No contacts to print." << endl;
			}
			contactbst.printASC(root);
		}
		else if (command == "printDES"){
			if (root == NULL){
				cout << "No contacts to print." << endl;
			}
			contactbst.printDES(root);
		}
		else if (command == "printFav"){
			if (root == NULL){
				cout << "No contacts to print." << endl;
			}
			contactbst.printFav(root);
		}
		else if (command == "help"){
			listCommands();
		}
		else if (command == "exit"){
			cout << "Exiting the program..." << endl;
			// exit(0);
			return(0);
		}
		else
			cout << "Invalid command. Please try again." << endl;
		
	}

	return 0;
}
