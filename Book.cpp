using namespace std;

class Book {
private:
	string title;
	string author;
	string genre;
	BookStatus status;
  // BOOK STATUS

public:
	Book(string t, string a, string g) {
		title = t;
		author = a;
		genre = g;
		status = AVAILABLE;
	}

	string getTitle() {
		return title;
	}

	bool isAvaliable() {
		return status == AVAILABLE;
	}

	void setStatus(BookStatus s) {
		status = s;
	}

	void display() {
		cout << title << " by " << author << endl;
	}
};
