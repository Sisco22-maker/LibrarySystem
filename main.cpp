/*
(اللهم صلْ وسلم وزد وبارك على سيدنا محمد )

꧁IslaM_SobhY꧂

 */
#include <bits/stdc++.h>
using namespace std;
#define SUPERPOWER ios_base::sync_with_stdio(false); cout.tie(0);
#define ll long long
#define  el "\12"

//Defining the constants of the containers size
const int Max_Users = 100;
const int Max_books = 100;
//-------------------------------------//

//Defining the struct of the books

struct Books
{
    string name;
    int id;
    int quantatiy;
    int borrow;
    string Who_Browed[Max_Users];
    //constructor to initialize the varibles
    Books()
    {
        id = 0;
        name = "";
        quantatiy = 0;
        borrow = 0;
    }
    //Functio to initialize the new book
    void Add_Books(const int& Id,const string& Name,const int& Quantatiy)
    {
        id = Id;
        name = Name;
        quantatiy = Quantatiy;
    }
    const int& GetId()
    {
        return id;
    }

    const string& GetName()
    {
        return name;
    }
    const int& GetQuantity()
    {
        return quantatiy;
    }
    const int& GetBorrow()
    {
        return borrow;
    }
     const int& GetBrrower()
    {
        return borrow;
    }
    void Add_Borrower_To_Book(const string& Borrower_Name)
    {
        Who_Browed[borrow++] = Borrower_Name;
        quantatiy--;
    }
};
//--------------------------------------//

//Defining the struct of the users
struct Users
{
    string name;
    int id;
    int borrowed = 0;
    string Borrowed_books[Max_books];
    //constructor to initialize the variables
    Users()
    {
        name = "";
        id = 0;
        borrowed;
    }

    //constructor to initialize the new user
    void Add_Users(const string &Name, const int &Id)
    {
        name = Name;
        id = Id;
    }
    void User_Add_borrowed(const string& Borrowed_Book)
    {
        Borrowed_books[borrowed++] = Borrowed_Book;
    }
    const string& GetName()
    {
        return name;
    }
    const int& GetId()
    {
        return id;
    }
    const int& GetBorrowed()
    {
        return borrowed;
    }

};


//-------------------------------------//

//Function to sort the Sturct by id
  bool Sort_By_ID( const Books &first, const Books &second)
    {
       return first.id < second.id;
    }
//--------------------------------------//

//Function to sort the struct by name
bool Sort_By_Name( const Books &first, const Books &second)
{
    return first.name < second.name;
}

//-----------------------------------//
struct Libarary_System
{
    //Defining The Main Objects
    Books books[Max_books];
    Users users[Max_Users];
    int Users_Number;
    int Books_Number;
    //constructor to initialize the Starting poss;
    Libarary_System()
    {
        Users_Number = 0;
        Books_Number = 0;
    }

    //Start the functionality

    //  1- Adding a book

    void Add_book()
    {
        cout << "Enter book info Id, Name, Quantity: ";
        int id;
        int quantity;
        string name;
        cin >> id >> name >> quantity;
        books[Books_Number++].Add_Books(id,name,quantity);
    }
    //---------------------------------------//

    // 2- Search book by prefix

    void Search_Book_By_Prefix()
    {
        cout<< "Enter the Prefix of the book: ";
        string prefix;
        cin >> prefix;
        bool Prefix_Match = 1;
        for(int i = 0; i < Books_Number; i++)
        {
            if(prefix.size() > books[i].GetName().size())
                continue;
                bool founded = 1;
                string Name = books[i].GetName();
            for(int j = 0; j < prefix.size() &&founded; j++)
            {
                if( prefix[j] != Name[j])founded = 0;
            }
            if(founded)
            {
                Prefix_Match = 0;
                cout << Name << el;
            }

        }
        if(Prefix_Match)cout << "Invalid Book Name!";

    }
    //---------------------------------------//

    // 3- Function to Print who borrowed book by name
    void Print_Who_Borrowed_book_By_Name()
    {
        cout << "Enter the book name : " ;
        string name;
        cin >> name;
        bool founded_book = 1;
        bool matched_in_DB = 1;
        for(int i = 0; i < Books_Number; i++)
        {
            if(books[i].GetName() == name)
            {
                matched_in_DB = 0;
                for(int j = 0; j < books[i].GetBorrow(); j++)
                {
                    founded_book = 0;
                    cout << books[i].Who_Browed[j] << el;
                }
                break;
            }
        }
        if(matched_in_DB)
            cout << "This Book is not in our DataBase!";
        else if(founded_book)
            cout << "No users borrowed this book yet!";
    }

    //---------------------------------------//

    //instance function to print the whole opject
    void Print_Struct()
    {
          for(int i = 0; i < Books_Number&& Books_Number > 0; i++)
        {
            cout << "id = "<<books[i].GetId()
            << " name = " << books[i].GetName()
            << " total_quantity "<< books[i].GetQuantity()
            << " total_borrowed " << books[i].GetBorrow();
            cout << el;
        }
        if(Books_Number == 0)
            cout << "There is no books!" << el;
    }

    //------------------------------------------//

    // 4- Print library by id

    void Print_library_by_id()
    {
       sort(books,books+Books_Number,Sort_By_ID);
       Print_Struct();

    }

    //--------------------------------------//


    // 5- Print library by name
     void Print_library_by_name()
     {
         sort(books,books+Books_Number,Sort_By_Name);
         Print_Struct();
     }

    //-------------------------------------//

    // 6- Function to add a user
    void Add_User()
    {
        cout << "Enter user name, national id : ";
        string name;
        int national_id;
        cin >> name >> national_id;
        bool Dont_Use = 1;
        for(int i = 0; i < Users_Number; i++)
        {
            if(users[i].GetId() == national_id)
            {
                cout << "Duplicated national id please re check the user national id !";
                Dont_Use = 0;
                break;
            }
        }
        if(Dont_Use)
        users[Users_Number++].Add_Users(name,national_id);

    }

    //--------------------------------------//

    // 7- User borrow book
    void User_Borrow_Book()
    {
        cout << "Enter user name, book name : ";
        string user_name;
        string book_name;
        cin >> user_name >> book_name;
        bool Dont_Use = 1;
        bool I_Found_Book = 1;
       for(int i = 0; i < Books_Number; i++)
        {
            if(books[i].GetName() == book_name)
            {
                I_Found_Book = 0;
                if(books[i].GetQuantity() > 0)
                {
                    books[i].Add_Borrower_To_Book(user_name);
                }else
                {
                     cout << "Can not borrow! There is no avilable books!";
                    Dont_Use = 0;
                    break;
                }


            }
        }
        bool User = 1;
        for(int i = 0; i < Users_Number; i++)
        {
            if(users[i].GetName() == user_name)
            {
                User = 0;
                if(Dont_Use&&I_Found_Book)
               users[i].User_Add_borrowed(book_name);
               break;
            }
        }
       if(I_Found_Book&& User)
       {
           cout << "In valid Data! The user name and the book name is not exist in Our DataBase";
       }else if(I_Found_Book && !User)
       {
           cout << "This book is not exist in our DataBase!";
       }else if(!I_Found_Book && User)
       {
           cout << "The user is not exist in our DataBase!";
       }




    }

    //-------------------------------------//

    // 8* User return a book

    void User_Return_A_Book()
    {
      cout << "Enter user_name, book_name: ";
      string user_name;
      string book_name;
      cin >> user_name >> book_name;
      bool Has_user = 1;
      bool Has_borrowed = 1;
       for(int i = 0; i < Users_Number; i++)
        {
            if(users[i].GetName() == user_name)
            {
                Has_user = 0;
               for(int j = 1; j < users[i].GetBorrowed(); j++)
               {
                   users[i].Borrowed_books[j-1] = users[i].Borrowed_books[j];
               }
               users[i].borrowed--;
               break;
            }
        }
        for(int i = 0; i < Books_Number; i++)
        {
            if(books[i].GetName() == book_name&& books[i].GetBorrow() > 0)
            {
                Has_borrowed = 0;
               for(int j = 1; j < books[i].GetBorrow(); j++)
               {
                   books[i].Who_Browed[j-1] =  books[i].Who_Browed[j];
               }
               books[i].borrow--;
               books[i].quantatiy++;
            }
        }
         if(Has_borrowed&&Has_user)
            cout<< "The user and the book name are not Valid !";
        else if(Has_borrowed)
            cout << "Can't return this book, This book has not been borrowed from the library!";
        else if(Has_user)
            cout << "Can't return this book, This user did not exists in our DataBase!";


    }
    //-------------------------------------------------//

    // 9- Print all users with their books
    void Print_All_Users_With_Books()
    {
        for(int i = 0; i < Users_Number; i++)
        {
            if(users[i].GetBorrowed() == 0)
            {
                 cout << "user : " << users[i].GetName() << " id : "
                 << users[i].GetId() << " Did not borrowed any books! " << el;
                 continue;
            }
            cout << "user : " << users[i].GetName() << " id : " << users[i].GetId() << " borrowed books names : " <<el;
            for(int j = 0; j < users[i].GetBorrowed(); j++)
            {
                cout << users[i].Borrowed_books[j] << " ";
            }
            cout << el;
        }
        if(Users_Number == 0)
            cout << "There is no Users At The moment!";
    }
    //------------------------------------------------//

    //Function to print the menu
    int Print_Menu()
    {
        cout << "Library Munu : " << el;
        cout << "1) Add book " << el;
        cout << "2) Search book by prefix " << el;
        cout << "3) Print who borrow book by name " << el;
        cout << "4) Print library by id " << el;
        cout << "5) Print library by name " << el;
        cout << "6) Add user " << el;
        cout << "7) User borrow book" << el;
        cout << "8) User return book " << el;
        cout << "9) Print Useres " << el;
        cout << "10) Exit " << el;
        int choice;
         cout <<  "Enter Your Choice : ";
        cin >> choice;
        return choice;
    }

    //--------------------------------------------------//

    void Run()
    {
        while(1)
        {
        int ret  = Print_Menu();

        if(ret == 1)
        {
            Add_book();
        }else if(ret == 2)
        {
            Search_Book_By_Prefix();
        }else if(ret == 3)
        {
            Print_Who_Borrowed_book_By_Name();
        }else if(ret == 4)
        {
            Print_library_by_id();
        }else if(ret == 5)
        {
            Print_library_by_name();
        }else if(ret == 6)
        {
            Add_User();
        }else if(ret == 7)
        {
            User_Borrow_Book();
        }else if(ret == 8)
        {
           User_Return_A_Book();
        }else if(ret == 9)
        {
            Print_All_Users_With_Books();
        }else
        {
            cout << "Bye!" << el;
            break;
        }
         cout <<el <<  "---------------------------------------------------------------" << el;
    }

    }
};
int main() {
     SUPERPOWER;
int t = 1;//cin >> t;
while(t--)
{
    //write the code here
    //int n;cin >> n;
Libarary_System library;
library.Run();

}
  return 0;
}





