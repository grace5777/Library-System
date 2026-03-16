#include <iostream>
#include <string>
using namespace std;

class Member : public User {
// private for everything only the member has 
private:
    string address;
    string phoneNum;
    int age;
    int borrowLimit;
    int currentBorrowed; 

// public to inherit everything from user 
// can be accessed outside the class 
public:
    // the constructor 
    // : User calls the user constructor first 
    Member(int id, string u, string p) : User(id, u, p, "", "") {
        // empty strings because they haven't been filled in yet
        address = "";
        phoneNum = "";
        age = 0;

        borrowLimit = 5;
        currentBorrowed = 0;
    }

    // BORROW A BOOK 
    // Book& book refers to book and makes it able to change status
    void borrowBook(Book& book) {
        // CHECKING IF BOOK IS AVAILABLE
        // both conditions need to be true
        if (book.isAvailable() && currentBorrowed < borrowLimit) {
            // changes book status to borrowed
            book.setStatus(BORROWED);
            // changes member borrwed counter to add one 
            currentBorrowed++;
            cout << username << " has borrowed the book.\n";
        }
        else {
            cout << "Book is unavailable or you have reached the borrowing limit.\n";
        }
    }

    // RETURN A BOOK 
    void returnBook(Book& book) {
        // changes the book status to available 
        book.setStatus(AVAILABLE);
        // changes the members borrowed count to take away one 
        currentBorrowed--;
        cout << username << " has returned the book.\n";
    }

    // RESERVING A BOOK 
    void reserveBook(Book& book) {
        // checking if the book isn't available 
        if (!book.isAvailable()) {
            // changes book status to reserved 
            book.setStatus(RESERVED);
            cout << username << " has reserved the book.\n";
        }
        else {
            cout << "The book is available and you can borrow it.\n";
        }
    }

    // VIEW PROFILE 
    // override so that member class can replace from user 
    void viewProfile() override {
        cout << "Member Profile\n";
        cout << "Name: " << name << endl;
        cout << "Phone Number: " << phoneNum << endl;
        cout << "Email: " << email << endl; 
        cout << "Age: " << age << endl;
    }

    // COMPLETING THE PROFILE
    void completeProfile() {
        cout << "Please enter your name: ";
        cin >> name;
    
        cout << "Please enter your email: ";
        cin >> email;
    
        cout << "Please enter your phone number: ";
        cin >> phoneNum;
    
        cout << "Please enter your age: ";
        cin >> age;
    }

    // SEARCH FOR BOOKS 
    // vector for the list of books
    void searchBook(vector<Book>& books) {
        string searchTitle;
    
        cout << "Please enter the books title to search: ";
        cin >> searchTitle;
    
        bool found = false;
    
        // looping through all the books
        for (Book& book : books) {
            // comparing book titles
            if (book.getTitle() == searchTitle) {
                book.display();
                found = true;
            }
        }
    
        // if book isn't found
        if (!found) {
            cout << "Book not found.\n";
        }
    }

    // MEMBER MENU
    void menu(vector<Book>& books) {
        int choice;
        do {
            cout << "\n--- MEMBER MENU ---\n";
            cout << "1. Search Book\n";
            cout << "2. Borrow Book\n";
            cout << "3. Return Book\n";
            cout << "4. Reserve Book\n";
            cout << "5. View Profile\n";
            cout << "6. Complete Profile\n";
            cout << "7. Logout\n";
            cout << "Choose an option: ";
            cin >> choice;

            // if statments for which choice the user picks 
            if (choice == 1) {
                searchBook(books);
            }
            
            else if (choice == 2) {
                borrowBook(books[0]);
            }
    
            else if (choice == 3) {
                returnBook(books[0]);
            }
    
            else if (choice == 4) {
                reserveBook(books[0]);
            }
    
            else if (choice == 5) {
                viewProfile();
            }

            else if (choice == 6) {
                completeProfile();
            }
    
            else if (choice == 7) {
                logout();
                cout << "You have been logged out\n";
            }
    
            else {
                cout << "Invalid option.\n";
            }
            
        } while (choice != 7);
    }
};
