/*
add reset password
add repeat users
add log file
*/
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <sstream>
#include "accounts.h"
using namespace std;
// check username and email
bool accounts::change(const string& email,const string& username)
{
    // open file
    ifstream file("users.csv");
    if (!file.is_open())
    {
        cerr << "Error opening CSV file.\n";
        return false;
    }
    string line;
    while(getline(file, line))
    {
        stringstream ss(line);
        string fileUsername, fileEmail, filePassword;
        if
        (
            getline(ss, fileUsername,',')&&
            getline(ss, fileEmail, ',')&&
            getline(ss, filePassword,',')
        )
        {
            if (fileEmail == email && fileUsername == username)
            {
                return true;
            }
        }
    }
}
void reset()
{
    string username,email,password;
    cout << "----Password-reset----\nPlease enter your username";
    cin.ignore();
    getline(cin,username);
    cout << "Please enter your email";
    getline(cin,email);
    cout << "Please enter your new password";
    getline(cin,password);
    if (change(email,username))
    {
        // Write to CSV
            ofstream file("users.csv", ios::app);
            if (file.is_open()) {
                file << username << "," << email << "," << password << endl;
                file.close();
                cout << "Account updated successfully.\n";
            }
    }
    else
    {
        cout << "Account information not found";
    }
}
// Function to check if the given username and password exist in a CSV file
bool accounts::checkCredentialse(const string& email, const string& password)
{
    ifstream file("users.csv"); // open the CSV file
    if (!file.is_open()) {
        cerr << "Error opening CSV file.\n"; // if file can't be opened
        return false;
    }

    string line; // to hold each line in the file
    while (getline(file, line)) { // read the file line by line
        stringstream ss(line); // create a stringstream from the line
        string fileUsername, fileEmail, filePassword;

        // assuming CSV format: "Username,Email,Password"
        if (getline(ss, fileUsername, ',') &&
            getline(ss, fileEmail, ',') &&
            getline(ss, filePassword, ',')) {
            // If email and password match
            if (fileEmail == email && filePassword == password) {
                return true; // credentials found
            }
            }
    }

    return false; // credentials not found
}
bool accounts::checkCredentialsu(const string& username, const string& password)
{
    ifstream file("users.csv"); // open the CSV file
    if (!file.is_open()) {
        cerr << "Error opening CSV file.\n"; // if file can't be opened
        return false;
    }

    string line; // to hold each line in the file
    while (getline(file, line))
    { // read the file line by line
        stringstream ss(line); // create a stringstream from the line
        string fileUsername, fileEmail, filePassword;

        // assuming CSV format: "Username,Email,Password"
        if (getline(ss, fileUsername, ',') &&
            getline(ss, fileEmail, ',') &&
            getline(ss, filePassword, ',')) {
            // If username and password match
            if (fileUsername == username && filePassword == password) {
                return true; // credentials found
            }
            }
    }

    return false; // credentials not found
}
void accounts::user()
{
    cout << "Username: ";
    string username;
    cin.ignore();
    getline(cin,username);
    cout << "Password: ";
    string password;
    getline(cin,password);
    if (checkCredentialsu(username, password))
    {
        cout << "Login successful!\n";
    }
    else
    {
        cout << "Invalid username or password.\n";
    }
}
void accounts::mail()
{
    cout << "E-mail: ";
    string email;
    cin.ignore();
    getline(cin,email);
    cout << "Password: ";
    string password;
    getline(cin,password);
    if (checkCredentialse(email, password)) {
        cout << "Login successful!\n";
    }
    else
    {
        cout << "Invalid E-mail or password.\n";
    }
}
void accounts::login()
{
    cout << "----Login----\n1. Username\n2. Email\n";
    int response;
    cin >> response;
    if (response == 1)
    {
        user();
    }
    if (response == 2)
    {
        mail();
    }
}

void accounts::create()
{
    cout << "----Create New Account----\n";
    bool valid;
    do {
        valid = true; // Assume valid unless proven otherwise
        string username, email, password;

        cout << "Please enter a username:\n(must be within 8 to 32 characters in length)\n";
        cin.ignore(); // To clear any leftover newline character
        getline(cin, username);

        cout << "Please enter an email address: ";
        getline(cin, email);

        cout << "Please enter a password:\n(must be at least 8 characters with at least 1 uppercase, 1 special character, and 1 digit)\n";
        getline(cin, password);

        // Check username constraints
        if (username.length() < 8 || username.length() > 32) {
            cout << "Error: Username must be between 8 and 32 characters.\n";
            valid = false;
        }

        // Check password constraints
        bool has_upper = false;
        bool has_special = false;
        bool has_digit = false;

        for (char c : password) {
            if (isupper(c)) has_upper = true;
            if (ispunct(c)) has_special = true;
            if (isdigit(c)) has_digit = true;
        }

        if (password.length() < 8) {
            cout << "Error: Password must be at least 8 characters.\n";
            valid = false;
        }

        if (!has_upper || !has_special || !has_digit) {
            cout << "Error: Password must contain at least 1 uppercase letter, 1 special character, and 1 digit.\n";
            valid = false;
        }

        if (valid) {
            // Write to CSV
            ofstream file("users.csv", ios::app);
            if (file.is_open()) {
                file << username << "," << email << "," << password << endl;
                file.close();
                cout << "Account created successfully.\n";
            } else {
                cout << "Error: Could not open the file.\n";
            }
        }
        else
        {
            cout << "Please correct the errors above and try again.\n";
        }
    }
    while (valid==false);
}
void accounts::admin()
{
    // display menu
    cout << "----Admin----\n";
    // default credentials
    string default_username = "Admin",default_password = "Hello123",username,password;
    cout << "Please enter username: ";
    cin.ignore();
    getline(cin, username);
    cout << "Please enter password: ";
    getline(cin, password);
    // Check if the username and password are correct
    bool username_correct = (username == default_username);
    bool password_correct = (password == default_password);

    if (username_correct && password_correct)
    {
        cout << "Login successful!\n";
        ifstream file("users.csv", ios::app);
    }
    else
    {
        cout << "Incorrect username or password.\n";
    }

}
