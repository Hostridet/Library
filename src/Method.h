#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    string name;
    string author;
public:
    Book(const string name, const string author) {
        this->name = name;
        this->author = author;
    }
    const string getName() const {
        return name;
    }
    const string getAuthor() const {
        return author;
    }

    friend ostream&operator << (ostream &out, const Book book) {
        return out << book.name << " - " << book.author << endl;
    }

    Book&operator = (const Book &book) {
        name = book.name;
        author = book.author;
        return *this;
    }
};

class Library {
protected:
    vector<Book> Books;

public:
    Library(vector<Book> &books) {
        Books = books;
    }

    void add_book(Book &book) {
        Books.push_back(book);
    }

    void del_book(vector<Book> Books,int i) {
        Books.erase(Books.begin() + i);
    }

    int IsBookNamed(string name) {
        size_t size = Books.size();

        for (int i = 0; i < size; i++) {
            if (name == Books[i].getName()) {
                return i;
            }
        }
        return -1;
    }

    int IsBook(const Book &book) {
        string name = book.getName();
        string author = book.getAuthor();
        size_t size = Books.size();

        for (int i = 0; i < size; i++) {
            if ((name == Books[i].getName()) && (author == Books[i].getAuthor())) {
                return i;
            }
        }
        return -1;
    }

    int IsBookAuthored(string author) {
        size_t size = Books.size();

        for (int i = 0; i < size; i++) {
            if (author == Books[i].getAuthor()) {
                return i;
            }
        }
        return -1;
    }


};

class Librarian : public Library {

public:
    Librarian(vector<Book> Books) : Library(Books) {
        this->Books = Books;
    }

    Book Rent(string name, string author) {
        int i = IsBook({ name, author });
        Book book("","");
        if (i >= 0) {
            cout << "Получите свою книгу: " << Books[i] <<endl;
            book = Books[i];
            del_book(Books,i);
            return book;
        }
        else {
            cout << "Книги нет "<< endl;
            return book;
        }
    }
    Book RentName(string name) {
        int i = IsBookNamed(name);
        Book book("", "");
        if (i >= 0) {
            cout << "Получите свою книгу: "<< Books[i] << endl;
            book = Books[i];
            del_book(Books, i);
            return book;
        }
        else {
            cout << "Книги нет "<<endl;
            return book;
        }
    }
    Book RentAuthor(string author) {
        int i = IsBookAuthored(author);
        Book book("", "");
        if (i >= 0) {
            cout << "Получите свою книгу: "<< Books[i] << endl;
            book = Books[i];
            del_book(Books, i);
            return book;
        }
        else {
            cout << "Книги нет " << endl;
            return book;
        }
    }
};