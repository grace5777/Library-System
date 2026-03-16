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

    // MAKING BOOKS
    vector<Book> books;
    books.push_back(Book("Alice's Adventures in Wonderland", "Lewis Carroll", "Fantasy"));
    books.push_back(Book("Winnie-the-pooh", "EH Shepard", "Cartoon"));
    books.push_back(Book("Charlotte's Web", "Garth Williams", "Thriller"));
    books.push_back(Book("The BFG", "Roald Dahl", "Horror"));
    books.push_back(Book("Marry Poppins", "PL Travers", "Fantasty"));

    // making a new library member called m1 to be able to fill in the deatils
    Member m1(id, username, password);

    m1.login();
    m1.menu(books);
    m1.viewProfile();

    return 0;
}
