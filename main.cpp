#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Book {
    string title;
    string author;
    int publicationYear;
    int pages;
    double price;
};

double getValue(Book book, int criteria) {

    if (criteria == 1)
        return book.publicationYear;

    else if (criteria == 2)
        return book.pages;

    else
        return book.price;
}

void insertionSort(vector<Book>& books, int criteria) {

    int n = books.size();

    for (int i = 1; i < n; i++) {

        Book key = books[i];
        int j = i - 1;

        while (j >= 0 &&
               getValue(books[j], criteria) >
               getValue(key, criteria)) {

            books[j + 1] = books[j];
            j--;
        }

        books[j + 1] = key;
    }
}

void displayBooks(const vector<Book>& books) {

    cout << "\n========== BOOK LIST ==========\n";

    for (const Book& book : books) {

        cout << "Title: " << book.title << endl;
        cout << "Author: " << book.author << endl;
        cout << "Year: " << book.publicationYear << endl;
        cout << "Pages: " << book.pages << endl;
        cout << "Price: " << book.price << endl;

        cout << "-------------------------------\n";
    }
}

int main() {

    vector<Book> books = {
        {"Al-Aiam", "Taha Hussien", 1929, 320, 150},
    {"3abkrit Omar", "Abbas Mahmoud", 1941, 280, 120},
    {"Awlad 7aretna", "Nagib Ma7fouz", 1959, 560, 200}
};

    int criteria;

    cout << "Choose Sorting method:\n";
    cout << "1. Publication Year\n";
    cout << "2. Number of Pages\n";
    cout << "3. Price\n";

    cout << "Your choice: ";
    cin >> criteria;

    if (criteria < 1 || criteria > 3) {
        cout << "Invalid choice!\n";
        return 0;
    }

    insertionSort(books, criteria);

    displayBooks(books);

    return 0;
}
