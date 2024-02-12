#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Book {
public:
    string title;
    string author;
    string ISBN;
    bool available;

    Book(const string& t, const string& a, const string& i)
        : title(t), author(a), ISBN(i), available(true) {}
};

class Borrower {
public:
    string name;
    int borrowedBooks;
    
    Borrower(const string& n = "") : name(n), borrowedBooks(0) {}
};

class Transaction {
public:
    time_t checkoutDate;
    time_t returnDate;
    double fine;

    Transaction() : checkoutDate(0), returnDate(0), fine(0.0) {}
};

class Library {
public:
    vector<Book> books;
    vector<Borrower> borrowers;
    vector<Transaction> transactions;
    Borrower currentBorrower;
    
public:
    Library() : currentBorrower("") {}
    void addBook(const string& title, const string& author, const string& ISBN) {
        books.push_back(Book(title, author, ISBN));
        cout << "Book added: " << title << endl;
    }

    void displayBooks() const {
        cout << "-------- Book List --------" << endl;
        for (const auto& book : books) {
            if (book.available) {
                cout << "Title: " << book.title << endl;
                cout << "Author: " << book.author << endl;
                cout << "ISBN: " << book.ISBN << endl;
                cout << "Status: Available" << endl;
                cout << endl;
            }
            else 
            {
                cout << "Title: " << book.title << endl;
                cout << "Author: " << book.author << endl;
                cout << "ISBN: " << book.ISBN << endl;
                cout << "Status: Unvailable" << endl;
                cout << endl;
            }
        }
        cout << "----------------------------------------" << endl;
    }

    Book* findBook(const string& searchTerm) {
        for (auto& book : books) {
            if ((book.title == searchTerm || book.author == searchTerm || book.ISBN == searchTerm) && (book.available==true)){
                cout << "[Available] "; 
                return &book;
            }
            else if((book.title == searchTerm || book.author == searchTerm || book.ISBN == searchTerm) && (book.available==false)){
                cout << "[Unvailable] "; 
                return &book;
            }
        }
        return nullptr;
    }

    void checkoutBook(Borrower& borrower, Book& book) {
        if (book.available) {
            book.available = false;
            currentBorrower.borrowedBooks++;
            Transaction transaction;
            transaction.checkoutDate = time(nullptr);
            transactions.push_back(transaction);
            cout << "Book checked out successfully." << endl;
        } else {
            cout << "Book is not available for checkout." << endl;
        }
    }

    void returnBook(Borrower& borrower, Book& book) {
        if (!book.available) {
            book.available = true;
            currentBorrower.borrowedBooks--;
            auto& transaction = transactions.back();
            transaction.returnDate = time(nullptr);
            // Calculate fine for overdue books (e.g., 0.1 per day)
            double daysOverdue = difftime(transaction.returnDate, transaction.checkoutDate) / (24 * 3600);
            transaction.fine = max(0.0, daysOverdue * 0.1);
            cout << "Book returned successfully." << endl;
            cout << "Fine: $" << transaction.fine << endl;
        } else {
            cout << "Book is already available." << endl;
        }
    }

    void displayBorrowers() const {
        cout << "-------- Borrower List --------" << endl;
        for (const auto& borrower : borrowers) {
            cout << "Name: " << borrower.name << ", Borrowed Books: " << currentBorrower.borrowedBooks << endl;
        }
        cout << "-----------------------------" << endl;
    }
};

int main() {
    Library library;

    library.addBook("The Great Gatsby", "F. Scott Fitzgerald", "978-0743273565");
    library.addBook("To Kill a Mockingbird", "Harper Lee", "978-0061120084");
    library.addBook("1984", "George Orwell", "978-0451524935");

    string borrowerName;
    cout << "Enter borrower name: ";
    getline(cin, borrowerName);
    Borrower borrower(borrowerName);
    library.borrowers.push_back(borrower);

    char choice;
    do {
        cout << "\n-------- Library Management System --------\n";
        cout << "1. Display Book List\n";
        cout << "2. Search for a Book\n";
        cout << "3. Checkout a Book\n";
        cout << "4. Return a Book\n";
        cout << "5. Display Borrowers\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        cin.ignore(); // Clear newline from the buffer

        switch (choice) {
            case '1':
                library.displayBooks();
                break;
            case '2': {
                string searchTerm;
                cout << "Enter a book title, author, or ISBN to search: ";
                getline(cin, searchTerm);

                Book* foundBook = library.findBook(searchTerm);
           
                if (foundBook != nullptr) {
                    cout << "Book found: " << foundBook->title << endl;
                } else {
                    cout << "Book not found." << endl;
                }
                break;
            }
            case '3': {
                string bookTitle;
                cout << "Enter the title of the book to checkout: ";
                getline(cin, bookTitle);

                Book* bookToCheckout = library.findBook(bookTitle);

                if (bookToCheckout != nullptr) {
                    borrower.borrowedBooks++;
                    library.checkoutBook(borrower, *bookToCheckout);
                } else {
                    cout << "Book not found." << endl;
                }
                break;
            }
            case '4': {
                string bookTitle;
                cout << "Enter the title of the book to return: ";
                getline(cin, bookTitle);

                Book* bookToReturn = library.findBook(bookTitle);

                if (bookToReturn != nullptr) {
                    library.returnBook(borrower, *bookToReturn);
                } else {
                    cout << "Book not found." << endl;
                }
                break;
            }
            case '5':
                library.displayBorrowers();
                break;
            case '6':
                cout << "Exiting the Library Management System." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 6.\n";
        }

    } while (choice != '6');

    return 0;
}
