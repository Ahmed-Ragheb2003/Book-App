#include "Book.h"
#include <iostream>
using namespace std;
Book::Book(string title, string author, string iSBN, string genre, bool available)
{
    Title = title;
    Author = author;
    ISBN = iSBN;
    Genre = genre;
    Available = available;
}

string Book::GetTitle()
{
    return Title;
}

string Book::GetAuthor()
{
    return Author;
}
string Book::GetISBN()
{
    return ISBN;

}
string Book::GetGenre()
{
    return Genre;
}

bool Book::operator<(const Book& other)const
{
    return Title < other.Title;
}
bool Book::operator==(const Book& other)const
{
    return Title == other.Title;
}
bool Book::operator>(const Book& other)const
{
    return Title > other.Title;
}

void Book::ReadInfoBook()
{
    cout << "Enter the Title of the book: " << endl;
    cin >> Title;
    cout << "\nEnter the Author of the book: " << endl;
    cin >> Author;
    cout << "\nEnter the ISBN of the book: " << endl;
    cin >> ISBN;
    cout << "\nEnter the Genre of the book: " << endl;
    cin >> Genre;
}

ostream& operator<<(ostream& output, Book book)
{
    cout << "====================================\n";
    output << "The Title Book is  : " << book.Title << endl;
    output << "The Author Book is : " << book.Author << endl;
    output << "The ISBN Book is   : " << book.ISBN << endl;
    output << "The Genre Book is  : " << book.Genre << endl;
    cout << "====================================\n";
    return output;
}
