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
    Member(int id, string u, string p, string e, string n, string ad, string phone, int a) : User(id, u, p, e, n) {
        address = ad;
        phoneNum = phone;
        age = a;

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
            cout << name << " has borrowed the book.\n";
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
        cout << name << " has returned the book.\n";
    }

    // RESERVING A BOOK 
    void reserveBook(Book& book) {
        // checking if the book isn't available 
        if (!book.isAvailable()) {
            // changes book status to reserved 
            book.setStatus(RESERVED);
            cout << name << " has reserved the book.\n";
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
        cout << "Address: " << address << endl; 
        cout << "Age: " << age << endl;
    }

    // MEMBER MENU
    void menu(Book& book) {
        int choice;
        do {
            cout << "\n--- MEMBER MENU ---\n";
            cout << "1. Search Book\n";
            cout << "2. Borrow Book\n";
            cout << "3. Return Book\n";
            cout << "4. Reserve Book\n";
            cout << "5. View Profile\n";
            cout << "6. Logout\n";
            cout << "Choose an option: ";
            cin >> choice;

            // if statments for which choice the user picks 
            if (choice == 2) {
                borrowBook(book);
                break;
            }
    
            else if (choice == 3) {
                returnBook(book);
                break;
            }
    
            else if (choice == 4) {
                reserveBook(book);
                break;
            }
    
            else if (choice == 5) {
                viewProfile();
                break;
            }
    
            else if (choice == 6) {
                logout();
                cout << "You have been logged out\n";
                break;
            }
    
            else {
                cout << "Invalid option.\n";
            }
            
        } while (choice != 6);
    }
};
