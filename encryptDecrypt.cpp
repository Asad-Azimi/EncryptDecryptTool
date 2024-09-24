#include <iostream>
#include <string> 
#include <limits>   // For numeric limits (used in clearing input buffer)
#include <fstream>  // For file input/output operations
#include <cctype>   // For character handling functions (e.g., isupper, islower)
#include <algorithm>// For algorithms like remove, transform

using namespace std;


// Class for handling encryption and decryption
class EncryptDecrypt 
{
    private:
        string text; // Stores the text to be encrypted or decrypted
        int key;     // Stores the key used for encryption/decryption

    public: 
        // Default constructor
        EncryptDecrypt()
        {
            text = "";
            key = 0;
        }

        // Parameterized constructor
        EncryptDecrypt(string text, int key)
        {
            this -> text = text;
            this -> key = key;
        }

        // Function to encrypt text using Caesar Cipher
        string EncryptCaesarCipher(string text, int key)
        {
            string encryptedText = "";
            for (int i = 0; i < text.length(); i++)
            {
                // If character is uppercase
                if (isupper(text[i]))
                {
                    // Shift character by key positions within uppercase letters range
                    encryptedText += char(int((text[i] + key) - 65) % 26 + 65);
                }
                // If character is lowercase
                else if (islower(text[i]))
                {
                    // Shift character by key positions within lowercase letters range
                    encryptedText += char(int(text[i] + key - 97) % 26 + 97);
                }
                else
                {
                    // Non-alphabetic characters remain unchanged
                    encryptedText += text[i];
                }
            }
            return encryptedText;
        }


        // Function to decrypt text using Caesar Cipher
        string DecryptCaesarCipher(string text, int key)
        {
            string decryptedText = "";

            // Decrypt each character in the text
            for (int i = 0; i < text.length(); i++)
            {
                // If character is uppercase
                if (isupper(text[i]))
                {
                    // Shift character back by key positions within uppercase letters range
                    decryptedText += char(int((text[i] - key) - 65) % 26 + 65);
                }
                // If character is lowercase
                else if (islower(text[i]))
                {
                    // Shift character back by key positions within lowercase letters range
                    decryptedText += char(int(text[i] - key - 97) % 26 + 97);
                }
                else
                {
                    // Non-alphabetic characters remain unchanged
                    decryptedText += text[i];
                }
            }
            return decryptedText;
        }


        // Function to encrypt text using Vigenere Cipher
        string EncryptVigenereCipher(string text, string key)
        {
            string encryptedText = "";

            // Encrypt each character in the text
            for (int i = 0; i < text.length(); i++)
            {
                // Encrypt the character using the Vigenère cipher (Auto-Key variant):
                if (islower(text[i]))
                {

                    encryptedText += char ((((int (key[i] - 97)) + (int (text[i] - 97))) % 26) + 97);
                }
            }
            return encryptedText;
        }

        string DecryptVigenereCipher(string text, string key)
        {
            string decryptedText = "";
            string new_key = key;
            for (int i = 0; i < text.length(); i++)
            {
                // Decrypt the character using the Vigenère cipher (Auto-Key variant):
                // Step-by-step explanation:
                // 1. Convert the encrypted character to its 0-25 alphabet index:
                //    (text[i] - 'a')
                // 2. Convert the key character to its 0-25 alphabet index:
                //    (new_key[i] - 'a')
                // 3. Subtract the key index from the encrypted character index:
                //    (text[i] - 'a') - (new_key[i] - 'a')
                // 4. Add 26 to handle negative results (ensures the value is positive):
                //    ((text[i] - 'a') - (new_key[i] - 'a') + 26)
                // 5. Apply modulus 26 to wrap around the alphabet if necessary:
                //    (( (text[i] - 'a') - (new_key[i] - 'a') + 26 ) % 26 )
                // 6. Convert the result back to a lowercase ASCII character:
                //    (( ... ) % 26 ) + 'a'
                // 7. Cast the final result to a character:
                //    char c = char( ... );
                if (islower(text[i]))
                {
                    char c = char((((int (text[i]) - 97) - (int (new_key[i] - 97))+26) % 26) + 97);
                    decryptedText += c;
                    new_key += c;
                }
            }
            return decryptedText;
        }
};



/*
    Function to handle Caesar Cipher operations
    Encrypt or Decrypt text using Caesar Cipher based on user input
*/
void CaesarCipher()
{
    cout << "You have selected Caesar Cipher" << endl;
    cout << "Please select the operation you want to perform: " << endl;
    cout << "1. Encrypt" << endl;
    cout << "2. Decrypt" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    int operation; cin >> operation;
    cout << "Please select the mode you want to use: " << endl;
    cout << "1. Write the text in the console" << endl;
    cout << "2. Read the text from a file" << endl;
    cout << "Enter your choice: ";
    int mode; cin >> mode;

    if (operation == 1)
    {
        if (mode == 1) {
        cout << "Enter the text you want to encrypt: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string text; getline (cin, text);
        cout << "Enter the key: ";
        int key; cin >> key;
        cout << "The text you entered is: " << text << endl;
        cout << "The key used is: " << key << endl;
        EncryptDecrypt  encrypte;
        string encryptedText = encrypte.EncryptCaesarCipher(text, key);
        cout << "The encrypted text is: " << encryptedText << endl;
        }
        else if (mode == 2)
        {
            cout << "Enter the name of the file you want to read the text from: ";
            string fileName = "";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, fileName);
            cout << "Enter the key: "; 
            int key; cin >> key;
            ifstream file(fileName);
            if (file.is_open())
            {
                string text = "";
                string line;
                while (getline(file, line))
                {
                    text += line;
                }
                cout << "The text in the file is: " << text << endl;
                cout << "The key used is: " << key << endl;
                EncryptDecrypt encrypte;
                string encryptedText = encrypte.EncryptCaesarCipher(text, key);
                cout << "The encrypted text is: " << encryptedText << endl;
                
            }
            else
            {
                cout << "The file could not be opened" << endl;
                cout << "Please make sure the file exists and the name is correct" << endl;
                cout << "Please make sure the file is in the same directory "
                        "as the executable file" << endl;
            }
            file.close();
        }
    }
    else if (operation == 2)
    {
        if (mode == 1) {
        cout << "Enter the encrypted text you want to decrypt: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string text; getline (cin, text);
        cout << "Enter the key: ";
        int key; cin >> key;
        cout << "The text you entered is: " << text << endl;
        cout << "The key used is: " << key << endl;
        EncryptDecrypt  decrypte;
        string decryptedText = decrypte.DecryptCaesarCipher(text, key);
        cout << "The decrypted text is: " << decryptedText << endl;
        }
        else if (mode == 2)
        {
            cout << "Enter the name of the file you want to read the text from: ";
            string fileName = "";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, fileName);
            cout << "Enter the key: "; 
            int key; cin >> key;
            ifstream file(fileName);
            if (file.is_open())
            {
                string text = "";
                string line;
                while (getline(file, line))
                {
                    text += line;
                }
                cout << "The text in the file is: " << text << endl;
                cout << "The key used is: " << key << endl;
                EncryptDecrypt decrypte;
                string decryptedText = decrypte.DecryptCaesarCipher(text, key);
                cout << "The decrypted text is: " << decryptedText << endl;
            }
            else
            {
                cout << "The file could not be opened" << endl;
                cout << "Please make sure the file exists and the name is correct" << endl;
                cout << "Please make sure the file is in the same directory "
                        "as the executable file" << endl;
            }
            file.close();
        }
    }
}




/*
    Function to extend the key to the length of the text
    by appending the the plaintext to the key
    until the key is the same length as the text
*/
string extend_key(string text, string key)
{
    string new_key = key;
    for (int i = 0; i < text.length() - key.length(); i++)
    {
        new_key += text[i];
    }
    return new_key;
}



/*
    Function to handle Vigenere Cipher operations
    Encrypt or Decrypt text using Vigenere Cipher based on user input
*/
void VigenereCipher()
{
    cout << "You have selected Polyalphabetic Vigenere Cipher" << endl;
    cout << "Please select the operation you want to perform: " << endl;
    cout << "1. Encrypt" << endl;
    cout << "2. Decrypt" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    int operation; cin >> operation;
    cout << "Please select the mode you want to use: " << endl;
    cout << "1. Write the text in the console" << endl;
    cout << "2. Read the text from a file" << endl;
    cout << "Enter your choice: ";
    int mode; cin >> mode;
    if (operation == 1)
    {
        if (mode == 1) {
            cout << "Enter the text you want to encrypt: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string text; getline (cin, text);
            text.erase(remove(text.begin(), text.end(), ' '), text.end());
            transform(text.begin(), text.end(), text.begin(), ::tolower);
            cout << "Enter the key (only lowercase alphabets are allowed): ";
            string key; cin >> key;
            transform(key.begin(), key.end(), key.begin(), ::tolower);
            cout << "The text you entered is: " << text << endl;
            cout << "The key used is: " << key << endl;
            key = extend_key(text, key);
            EncryptDecrypt encrypte;
            string encryptedText = encrypte.EncryptVigenereCipher(text, key);
            cout << "The encrypted text is: " << encryptedText << endl;
        }
        else if (mode == 2)
        {
            cout << "Enter the name of the file you want to read the text from: ";
            string fileName; 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, fileName);
            cout << "Enter the key (only lowercase alphabets are allowed): ";
            string key; cin >> key;
            transform(key.begin(), key.end(), key.begin(), ::tolower);
            ifstream file(fileName);
            if (file.is_open())
            {
                string text = "";
                string line;
                while (getline(file, line))
                {
                    text += line;
                }
                text.erase(remove(text.begin(), text.end(), ' '), text.end());
                transform(text.begin(), text.end(), text.begin(), ::tolower);
                cout << "The text in the file is: " << text << endl;
                cout << "The key used is " << key << endl;
                key = extend_key(text, key);
                EncryptDecrypt encrypte;
                string encryptedText = encrypte.EncryptVigenereCipher(text, key);
                cout << "The encrypted text is: " << encryptedText << endl;
            }
            else 
            {
                cout << "The file could not be open" << endl;
                cout << "Please make sure the file exists and the name is correct" << endl;
                cout << "Please make sure the file is in the same directory "
                        "as the executable file" << endl;
            }
            file.close();
        }
    }
    else if (operation == 2)
    {
        if (mode == 1) 
        {
            cout << "Enter the encrypted text you want to decrypt: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string text; getline (cin, text);
            text.erase(remove(text.begin(), text.end(), ' '), text.end());
            transform(text.begin(), text.end(), text.begin(), ::tolower);
            cout << "Enter the key: ";
            string key; cin >> key;
            key.erase(remove(key.begin(), key.end(), ' '), key.end());
            transform(key.begin(), key.end(), key.begin(), ::tolower);
            cout << "The text you entered is: " << text << endl;
            cout << "The key used is: " << key << endl;
            EncryptDecrypt decrypte;
            string decryptedText = decrypte.DecryptVigenereCipher(text, key);
            cout << "The decrypted text is: " << decryptedText << endl;
        }
        else if (mode == 2)
        {
            cout << "Enter the name of the file you want to read the text from: ";
            string fileName; 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, fileName);
            cout << "Enter the key (only lowercase alphabets are allowed): ";
            string key; cin >> key;
            transform(key.begin(), key.end(), key.begin(), ::tolower);
            ifstream file(fileName);
            if (file.is_open())
            {
                string text = "";
                string line;
                while (getline(file, line))
                {
                    text += line;
                }
                text.erase(remove(text.begin(), text.end(), ' '), text.end());
                transform(text.begin(), text.end(), text.begin(), ::tolower);
                cout << "The text in the file is: " << text << endl;
                cout << "The key used is " << key << endl;
                key = extend_key(text, key);
                EncryptDecrypt encrypte;
                string encryptedText = encrypte.EncryptVigenereCipher(text, key);
                cout << "The encrypted text is: " << encryptedText << endl;
            }
            else
            {
                cout << "The file could not be open" << endl;
                cout << "Please make sure the file exists and the name is correct" << endl;
                cout << "Please make sure the file is in the same directory "
                        "as the executable file" << endl;
            }
            file.close();
        }
    }
}




int main()
{
    cout << "This is a tool to Encrypt and Decrypt text using Caesar Cipher"
            " and Vigenere Cipher" << endl;
    bool running = true;
    while (running)
    {
        cout << "Please select the cipher you want to use: " << endl;
        cout << "1. Caesar Cipher" << endl;
        cout << "2. Vigenere Cipher" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        int choice; cin >> choice;

        switch (choice)
        {
            case 1:
                CaesarCipher();
                break;
            case 2: 
                VigenereCipher();
                break;
            case 3:
                cout << "Exiting the program" << endl;
                running = false;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
    
}