#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;

    // Constructor to initialize 
    Book(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
    }

    // Default constructor
    Book() {
        id = 0;
        title = "";
        author = "";
    }

    void display() {
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author << endl;
    }
};

// Function prototypes
void addBook(Book books[], int &bookCount);
void displayBooks(Book books[], int bookCount);
void searchBook(Book books[], int bookCount);
void updateBook(Book books[], int bookCount);
void deleteBook(Book books[], int &bookCount);

int main() {
    Book books[100]; // Array to store books
    int bookCount = 0; 
    int choice;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search for a Book by ID\n";
        cout << "4. Update Book Details\n";
        cout << "5. Delete a Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(books, bookCount);
                break;
            case 2:
                displayBooks(books, bookCount);
                break;
            case 3:
                searchBook(books, bookCount);
                break;
            case 4:
                updateBook(books, bookCount);
                break;
            case 5:
                deleteBook(books, bookCount);
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}

// Function to add a book
void addBook(Book books[], int &bookCount) {
    int id;
    string title, author;
    
    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore(); // To ignore the newline character left by previous input
    cout << "Enter Book Title: ";
    getline(cin, title); // Read title with spaces
    cout << "Enter Book Author: ";
    getline(cin, author); // Read author with spaces

    books[bookCount] = Book(id, title, author); // Create a new book object and add it to the array
    bookCount++; // Increment book count

    cout << "Book added successfully!\n";
}

// Function to display all books
void displayBooks(Book books[], int bookCount) {
    if (bookCount == 0) {
        cout << "No books in the library.\n";
        return;
    }

    cout << "\nBooks in the Library:\n";
    for (int i = 0; i < bookCount; i++) {
        books[i].display();
    }
}

// Function to search for a book by ID
void searchBook(Book books[], int bookCount) {
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            cout << "Book found:\n";
            books[i].display();
            return;
        }
    }
    cout << "Book with ID " << id << " not found.\n";
}

// Function to update a book's details
void updateBook(Book books[], int bookCount) {
    int id;
    cout << "Enter Book ID to update: ";
    cin >> id;

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            string newTitle, newAuthor;
            cout << "Enter new title: ";
            cin.ignore(); // To consume the newline character
            getline(cin, newTitle); // Read new title
            cout << "Enter new author: ";
            getline(cin, newAuthor); // Read new author

            books[i].title = newTitle;
            books[i].author = newAuthor;
            cout << "Book details updated successfully!\n";
            return;
        }
    }
    cout << "Book with ID " << id << " not found.\n";
}

// Function to delete a book by ID
void deleteBook(Book books[], int &bookCount) {
    int id;
    cout << "Enter Book ID to delete: ";
    cin >> id;

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            // Shift all books after the found book to the left
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1]; // Move the next book to the current position
            }
            bookCount--; // Decrease the book count
            cout << "Book with ID " << id << " deleted successfully!\n";
            return;
        }
    }
    cout << "Book with ID " << id << " not found.\n";
}
