#pragma once
#include <iostream>
#include "Book.h"
#include "LinkedList.h"
using namespace std;    

class Library
{
private:
    LinkedList<Book> catlog;
    int NumberBooks, NumberBorrowedBooks, NumberavailableBooks;
public:
    Library();
    void addBook(Book book);
    void BorrowedBook(Book book);
    void DeleteBook(Book book);
    void SearchBook(Book book);
    void PrintBooks();
    void sortListBook();
    void printStatistics();
    void printMenu();
    void ShowMainMenu();

};
