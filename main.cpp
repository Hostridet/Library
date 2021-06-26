#include "src/Method.h"

int main() {
    Book A{ "Harry Potter", "Papa Joe" };
    Book B{ "The Lord Of the Ring", "Blue Jack" };
    Book C{ "The song of the sirens", "John Forks" };

    vector<Book> Books = {A,B,C};

    Library library(Books);
    Librarian Libr(Books);

    Libr.Rent("The song of the sirens", "John Forks");
    Libr.RentAuthor("Blue Jack");
    Libr.RentName("Harry Potter");

    return 0;
}
