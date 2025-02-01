#pragma once
#include <iostream>
using namespace std;

class Book
{
public:
    string Title, Author, ISBN, Genre;
    bool Available;
    Book(string title = "", string author = "", string ISBN = "", string genre = "", bool available = 1);
    string GetTitle();
    string GetAuthor();
    string GetISBN();
    string GetGenre();
    void ReadInfoBook();
    bool operator<(const Book& other)const;
    bool operator==(const Book& other)const;
    bool operator>(const Book& other)const;
    friend ostream& operator<<(ostream& output, Book book);

};
