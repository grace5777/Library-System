#include <iostream>

// creating predefined rules for the roles
// in capitals because it prevents invalid roles
enum RoleType {
    MEMBER,
    LIBRARIAN,
    ADMINISTRATOR,
};

enum BookStatus {
    AVALABLE,
    BORROWED,
    RESERVED
};
