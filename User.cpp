#include <iostream>
#include <string>
using namespace std; 

// USER CLASS
class User {
// protected so that only member and the child classes can use them
protected:
    int userID;
    string username;
    string password;
    string email;
    string name;
    RoleType role;
    // need to fix role type 

// public so that everything can use it
public:
    // constructor 
    // automatically runs and saves info
    User(int id, string u, string p, string e, string n, RoleType r) {
        userID = id;
        username = u;
        password = p;
        email = e;
        name = n;
        role = r;
    }

    // LOGIN
    bool login() {
        cout << name << "logged in.\n";
        return true;
    }

    // LOGOUT
    void logout() {
        cout << name << "logged out.\n";
    }

    // VIEW PROFILE
    virtual void viewProfile() {
        std::cout << "Name: " << name << endl;
        std::cout << "Email: " << email << endl;
    }

    // UPDATING PROFILE 
    virtual void updatePofile(string newName, string newEmail) {
        name = newName;
        email = newEmail;
    }

    // virtual makes sure the right clean up happens 
    // ~User cleans up the object 
    virtual ~User(){}
};
