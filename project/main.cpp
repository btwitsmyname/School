#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <sstream>
#include "accounts.h"
// prototypes
void admin();
void create();
void login();
void user();
void mail();
void reset();
bool accounts::change(const string& email,const string& username);
bool checkCredentialsu(const string& username, const string& password);
bool checkCredentialse(const string& email, const string& password);
using namespace std;
int main()
{
    accounts a;
    // display menu options
    cout << "----Menu----\n1. Login\n2. Create account\n3. Admin\n4. exit\n";
    int input;
    cin >> input;
    switch (input)
    {
        // login to system
        case 1:
            a.login();
            break;
            // create new account
        case 2:
            a.create();
            break;
            // login to admin account
        case 3:
            a.admin();
            break;
            // exit system
        case 4:
            cout << "exiting";
            return 0;
            // error
        default:
            cout << "Input error";
            main();
    }
    return 0;
}
