# Contact Management System

## Overview
The Contact Management System is a C++ console application designed for efficiently managing contacts. It uses a Binary Search Tree (BST) data structure for organizing contacts, providing optimal search, insertion, and deletion operations. The system allows users to maintain contact information, mark favorites, and import/export contacts in CSV format.

## Features
### Core Functionality

Contact Management

- Add new contacts with comprehensive details
- Update existing contact information
- Remove contacts from the system
- Search contacts by name (first name + last name)


Contact Organization

- Mark/unmark contacts as favorites
- View all favorite contacts
- Display contacts in ascending alphabetical order
- Display contacts in descending alphabetical order


Data Persistence

- Import contacts from CSV files
- Export contacts to CSV files
- Preserves all contact details including favorite status

### Contact Details Stored

- First Name
- Last Name
- Email Address (with validation)
- Phone Number (with validation)
- City
- Country
- Favorite Status

### Technical Implementation
Data Structures

- Binary Search Tree (BST)

    - Efficiently organizes contacts by name
    - O(log n) search, insert, and delete operations for balanced trees
    - Each node contains a key (first name + last name) and a vector of contact pointers


- Custom Vector Implementation

    - Dynamic array implementation (MyVector)
    - Supports push_back, insert, erase, at operations
    - Automatic capacity management with doubling strategy

### Memory Management

- Dynamic allocation and deallocation of Contact objects
- Proper cleanup in destructors to prevent memory leaks
- Careful pointer handling throughout the application

### Project Structure
contact-management-system/
├── Makefile                # Build configuration
├── contact.h               # Contact class declaration
├── contact.cpp             # Contact class implementation
├── contactbst.h            # ContactBST and Node class declarations
├── contactbst.cpp          # ContactBST and Node implementations
├── myvector.h              # MyVector template class declaration
├── myvector.cpp            # MyVector template class implementation
├── main.cpp                # Program entry point and UI
└── README.md               # Project documentation

### Class Documentation
__Contact Class__
__Purpose:__ Stores individual contact information
**Members:**

* <span style="color:red">string fname</span> - First name
* <span style="color:red">string lname</span> - Last name
* <span style="color:red">string email</span> - Email address
* <span style="color:red">string phone</span> - Phone number
* <span style="color:red">string city</span> - City
* <span style="color:red">string country</span> - Country
* <span style="color:red">bool isFav</span> - Favorite status

**Methods:**

* <span style="color:red">Contact(string fname, string lname, string email, string phone, string city, string country, bool isFav)</span> - Constructor

**Node Class**
**Purpose:** Represents a node in the Binary Search Tree
**Members:**

* <span style="color:red">string key</span> - Search key (first name + last name)
* <span style="color:red">MyVector<Contact*> contactVector</span> - Vector of contacts with the same key
* <span style="color:red">Node* left</span> - Pointer to left child
* <span style="color:red">Node* right</span> - Pointer to right child
* <span style="color:red">Node* parent</span> - Pointer to parent node

**Methods:**

* <span style="color:red">Node(string key, Contact *data)</span> - Constructor
* <span style="color:red">string getKey()</span> - Returns the node's key
* <span style="color:red">MyVector<Contact*> getData()</span> - Returns the contact vector
* <span style="color:red">void print()</span> - Prints contacts with numbering
* <span style="color:red">void print2(ostream &os)</span> - Prints contacts without numbering

**MyVector Class**
**Purpose:** Custom implementation of a dynamic array
**Template Parameters:**

* <span style="color:red">typename T</span> - Type of elements stored in the vector

**Members:**

* <span style="color:red">T *data</span> - Pointer to array storing elements
* <span style="color:red">int v_size</span> - Current number of elements
* <span style="color:red">int v_capacity</span> - Total capacity of the vector

**Methods:**

* <span style="color:red">MyVector(int cap=0)</span> - Constructor with optional capacity
* <span style="color:red">~MyVector()</span> - Destructor
* <span style="color:red">void push_back(T element)</span> - Add element to end
* <span style="color:red">void insert(int index, T element)</span> - Insert element at position
* <span style="color:red">void erase(int index)</span> - Remove element at position
* <span style="color:red">T& at(int index)</span> - Access element with bounds checking
* <span style="color:red">const T& front()</span> - Access first element
* <span style="color:red">const T& back()</span> - Access last element
* <span style="color:red">int size() const</span> - Get number of elements
* <span style="color:red">int capacity() const</span> - Get vector capacity
* <span style="color:red">bool empty() const</span> - Check if vector is empty
* <span style="color:red">void shrink_to_fit()</span> - Reduce capacity to match size
* <span style="color:red">void display()</span> - Print all elements

**ContactBST Class**
**Purpose:** Binary Search Tree for managing contacts
**Members:**

* <span style="color:red">Node* root</span> - Pointer to the root node of the BST

**Methods:**

* <span style="color:red">ContactBST()</span> - Constructor
* <span style="color:red">~ContactBST()</span> - Destructor
* <span style="color:red">Node* getRoot()</span> - Returns root node
* <span style="color:red">void add(Node* ptr, string key, Contact *data)</span> - Add a contact
* <span style="color:red">void update(string key)</span> - Update a contact
* <span style="color:red">void remove(Node* ptr, string key)</span> - Remove a contact
* <span style="color:red">void printnode(Node* ptr)</span> - Print node data
* <span style="color:red">Node* searchFor(Node* ptr, string key)</span> - Find a node by key
* <span style="color:red">bool markFav(string key)</span> - Mark contact as favorite
* <span style="color:red">bool unmarkFav(string key)</span> - Unmark contact as favorite
* <span style="color:red">void printASC(Node* ptr)</span> - Print contacts in ascending order
* <span style="color:red">void printDES(Node* ptr)</span> - Print contacts in descending order
* <span style="color:red">void printFav(Node* ptr)</span> - Print favorite contacts
* <span style="color:red">int importCSV(string path)</span> - Import contacts from CSV
* <span style="color:red">int exportCSV(Node* ptr, ostream& file)</span> - Export contacts to CSV
* <span style="color:red">Node* findMin(Node* ptr)</span> - Find minimum node (helper method)

### Requirements

* C++ Compiler (C++11 or later)
* Make (for building with the provided Makefile)

### How to Build and Run

```
# Clone the repository
git clone https://github.com/yourusername/contact-management-system.git

# Navigate to the project directory
cd contact-management-system

# Build the project
make

# Run the application
./contacts 
```

### Usage Guide
**First Run**
When you first run the application, you'll see a list of available commands. You can start by:

* Importing contacts from a CSV file:
`import path/to/contacts.csv`

* Or adding contacts manually:
`add`

### Basic Workflow

* Add Contacts: Use the add command to enter contact details.
* Search Contacts: Use searchFor FirstName LastName to find specific contacts.
* Update Contacts: Use update FirstName LastName to modify contact details.
* Delete Contacts: Use remove FirstName LastName to delete contacts.
* View All Contacts: Use printASC to display all contacts alphabetically.
* Mark Favorites: Use markFav FirstName LastName to mark contacts as favorites.
* Save Your Work: Use export path/to/save.csv to save your contacts.