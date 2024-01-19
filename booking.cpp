#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class to represent a Book
class Book {
public:
    string title;
    string author;
    int bookID;
    bool available;

    Book(string title, string author, int bookID)
        : title(title), author(author), bookID(bookID), available(true) {}
};

// Class to represent a Borrower
class Borrower {
public:
    string name;
    int borrowerID;

    Borrower(string name, int borrowerID)
        : name(name), borrowerID(borrowerID) {}
};

// Class to represent a Transaction
class Transaction {
public:
    int transactionID;
    Book* book;
    Borrower* borrower;
    string date;

    Transaction(int transactionID, Book* book, Borrower* borrower, string date)
        : transactionID(transactionID), book(book), borrower(borrower), date(date) {}
};

// Class to represent the Library and manage books, borrowers, and transactions
class Library {
private:
    vector<Book> books;
    vector<Borrower> borrowers;
    vector<Transaction> transactions;
    int transactionCounter;

public:
    Library() : transactionCounter(1) {}

    // Function to add a book to the library
    void addBook(string title, string author) {
        books.emplace_back(title, author, books.size() + 1);
    }

    // Function to add a borrower to the library
    void addBorrower(string name) {
        borrowers.emplace_back(name, borrowers.size() + 1);
    }

    // Function to display all books in the library
    void displayBooks() {
        cout << "Books in the Library:\n";
        for (const Book& book : books) {
            cout << "ID: " << book.bookID << ", Title: " << book.title << ", Author: " << book.author
                 << ", Available: " << (book.available ? "Yes" : "No") << endl;
        }
        cout << endl;
    }

    // Function to display all borrowers in the library
    void displayBorrowers() {
        cout << "Borrowers in the Library:\n";
        for (const Borrower& borrower : borrowers) {
            cout << "ID: " << borrower.borrowerID << ", Name: " << borrower.name << endl;
        }
        cout << endl;
    }

    // Function to handle book checkout
    void checkOutBook(int bookID, int borrowerID, string date) {
        Book* book = findBook(bookID);
        Borrower* borrower = findBorrower(borrowerID);

        if (book && borrower && book->available) {
            book->available = false;
            transactions.emplace_back(transactionCounter++, book, borrower, date);
            cout << "Book checked out successfully.\n";
        } else {
            cout << "Book not available or borrower not found.\n";
        }
    }

    // Function to handle book return
    void returnBook(int bookID, string date) {
        Book* book = findBook(bookID);

        if (book && !book->available) {
            book->available = true;
            cout << "Book returned successfully.\n";
        } else {
            cout << "Book not found or already returned.\n";
        }
    }

private:
    // Helper function to find a book by ID
    Book* findBook(int bookID) {
        for (Book& book : books) {
            if (book.bookID == bookID) {
                return &book;
            }
        }
        return nullptr;
    }

    // Helper function to find a borrower by ID
    Borrower* findBorrower(int borrowerID) {
        for (Borrower& borrower : borrowers) {
            if (borrower.borrowerID == borrowerID) {
                return &borrower;
            }
        }
        return nullptr;
    }
};

int main() {
    Library library;

    // Adding books to the library
    library.addBook("The Catcher in the Rye", "J.D. Salinger");
    library.addBook("To Kill a Mockingbird", "Harper Lee");
    library.addBook("1984", "George Orwell");

    // Adding borrowers to the library
    library.addBorrower("Alice Johnson");
    library.addBorrower("Bob Smith");

    // Displaying available books and borrowers
    library.displayBooks();
    library.displayBorrowers();

    // Performing transactions (checkout and return)
    library.checkOutBook(1, 1, "2024-01-16");
    library.displayBooks();

    library.returnBook(1, "2024-01-20");
    library.displayBooks();

    return 0;
}
