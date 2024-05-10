#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <sstream>
#ifndef accounts_h
#define account_h
using namespace std;
class accounts
{
    private:
        string username;
        string password;
        string email;
    public:
        void admin();
        void create();
        void login();
        void user();
        void mail();
        void reset();
        bool accounts::change(const string& email,const string& username);
        bool checkCredentialsu(const string& username, const string& password);
        bool checkCredentialse(const string& email, const string& password);
       // bool checkCredentialse(const string& email, const string& password)
};
#endif
