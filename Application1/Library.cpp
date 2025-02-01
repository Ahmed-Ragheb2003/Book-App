#include "Library.h"
Library::Library()
{
    NumberBooks = 0;
    NumberavailableBooks = 0;
    NumberBorrowedBooks = 0;
}

void Library::addBook(Book book)
{
    NumberBooks++;
    NumberavailableBooks++;
    catlog.insertRight(book);
}

void Library::DeleteBook(Book book)
{
    int bookIdx = catlog.search(book);
    if (bookIdx != -1)
    {
        NumberBooks--;
        NumberavailableBooks--;
        catlog.removeAtPosition(bookIdx);
        cout << "The Book Deleted Successfully:-)\n\n";
    }
    else
    {
        cout << "\n__________________________________________\n";
        cout << "\n" << " Sorry!, This Book is Not Founded:-(";
        cout << "\n__________________________________________\n\n";
    }
}


void Library::SearchBook(Book book)
{
    int bookIdx = catlog.search(book);
    if (bookIdx != -1)
    {
        cout << "\n__________________________________________\n";
        cout << "\n" << "This Book avabible in Library:-)";
        cout << "\n__________________________________________\n\n";
    }
    else
    {
        cout << "\n__________________________________________\n";
        cout << "\n" << " Sorry!, This Book is Not Founded:-(";
        cout << "\n__________________________________________\n\n";
    }
}

void Library::BorrowedBook(Book book)
{
    int bookIdx = catlog.search(book);
    if (bookIdx != -1)
    {
        NumberBorrowedBooks++;
        NumberavailableBooks--;
        catlog.removeAtPosition(bookIdx);
        cout << "The Book Borrowed Successfully:-)\n\n";
    }
    else
    {
        cout << "\n__________________________________________\n";
        cout << "\n" << " Sorry!, This Book is Not Founded:-(";
        cout << "\n__________________________________________\n\n";
    }
}

void Library::PrintBooks()
{
    cout << "\n__________________________________________\n";
    cout << "\n\tThe List Books Screen.";
    catlog.print();
}

void Library::sortListBook()
{
    cout << "\n__________________________________________\n";
    cout << "\n" << "  The List Book Sorted Successfully:-).";
    cout << "\n__________________________________________\n\n";
    catlog.sortList();
}

void Library::printStatistics()
{
    cout << "__________________________________________\n";
    cout <<"\n"<< "  The List Statistics Books Screen.";
    cout << "\n__________________________________________\n";
    cout << "===================================================\n";
    cout << "Number of books in the library is           : " << NumberBooks << "\n";
    cout << "Number of borrowed books in the library is  : " << NumberBorrowedBooks << "\n";
    cout << "Number of available books in the library is : " << NumberavailableBooks << "\n";
    cout << "===================================================\n\n";

}

void Library::printMenu()
{
    cout << "=========================================\n";
    cout << "\tMyTemplate Container\n";
    cout << "=========================================\n";
    cout << "[1] Add New Book.\n";
    cout << "[2] Borrow Book.\n";
    cout << "[3] Delete Book.\n";
    cout << "[4] Search Book.\n";
    cout << "[5] Print Books.\n";
    cout << "[6] Sort Books."<< "\n";
    cout << "[7] Print Statistics.\n";
    cout << "[8] Exits.\n";
    cout << "=========================================\n";
    cout << "Please Enter Your Choice [1 to 8]: ";
}

void Library::ShowMainMenu()
{
    while (true)
    {
        printMenu();
        int choice;
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
        {
            Book book;
            book.ReadInfoBook();
            cout << "\nThe Book Added Successfully:-)\n\n";
            addBook(book);
            break;
        }
        case 2:
        {
            Book book;
            book.ReadInfoBook();
            BorrowedBook(book);
            break;
        }
        case 3:
        {
            Book book;
            book.ReadInfoBook();
            DeleteBook(book);
            break;
        }
        case 4:
        {
            Book book;
            book.ReadInfoBook();
            SearchBook(book);
            break;
        }
        case 5:
        {
            system("cls");
            PrintBooks();
            break;
        }
        case 6:
        {
            system("cls");
            sortListBook();
            break;
        }
        case 7:
        {
            system("cls");
            printStatistics();
            break;
        }
        case 8:
        {
            cout << "Thanks :-)." << endl;
            return;
        }
        default:
            cout << "Invalid Choice, Please Choice From 1 to 7." << endl;
        }
    }
}
