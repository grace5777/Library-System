int main() {
    // declaring the variables for user to give details 
    int id;
    int age;
    string username;
    string password;
    string email;
    string name;
    string address;
    string phone;

    // inputting the details 
    cout << "Please enter your ID: ";
    cin >> id;

    cout << "Please enter your username: ";
    cin >> username;

    cout << "Please enter your password: ";
    cin >> password;

    cout << "Please enter your name: ";
    cin >> name;

    cout << "Please enter your email: ";
    cin >> email;

    cout << "Please enter your phone number: ";
    cin >> phone;

    cout << "Please enter your age: ";
    cin >> age;


    Book b1("Book1", "Jane Doe", "Workbook");

    // making a new library member called m1 to be able to fill in the deatils
    Member m1(id, username, password, email, name, address, phone, age);

    m1.login();
    m1.menu(b1);
    m1.viewProfile();

    return 0;
}
