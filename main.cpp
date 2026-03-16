int main() {
    // declaring the variables for user to give details 
    int id;
    string username;
    string password;

    // inputting the details 
    cout << "Please enter your ID: ";
    cin >> id;

    cout << "Please enter your username: ";
    cin >> username;

    cout << "Please enter your password: ";
    cin >> password;

    Book b1("Book1", "Jane Doe", "Workbook");

    // making a new library member called m1 to be able to fill in the deatils
    Member m1(id, username, password);

    m1.login();
    m1.menu(b1);
    m1.viewProfile();

    return 0;
}
