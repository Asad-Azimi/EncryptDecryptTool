Encryption and Decryption Tool
Overview
This project is a command-line tool for encrypting and decrypting text using two popular ciphers: 
the Caesar Cipher and the Vigenère Cipher. The tool allows users to either input text directly via the console or read text from a file.
It supports both encryption and decryption operations.

Features
Caesar Cipher: A substitution cipher where each letter in the plaintext is shifted a certain number of places down or up the alphabet.
Vigenère Cipher: A method of encrypting alphabetic text by using a simple form of polyalphabetic substitution.

Usage
Running the Program
To run the program, compile the encryptDecrypt.cpp file and execute the resulting binary.

```cpp
g++ -o encryption_tool encryptDecrypt.cpp
./encryption_tool
```

Menu Options
Upon running the program, you will be presented with a menu to choose the cipher you want to use:

1. Caesar Cipher
2. Vigenère Cipher
3. Exit


Caesar Cipher
1. Encrypt: Encrypt text using the Caesar Cipher.

  Console Input: Enter the text and the key directly in the console.
  File Input: Provide the name of the file containing the text and the key.

2. Decrypt: Decrypt text using the Caesar Cipher.

  Console Input: Enter the encrypted text and the key directly in the console.
  File Input: Provide the name of the file containing the encrypted text and the key.



Vigenère Cipher
1. Encrypt: Encrypt text using the Vigenère Cipher.

  Console Input: Enter the text and the key directly in the console. The key should only contain lowercase alphabets.
  File Input: Provide the name of the file containing the text and the key.

2. Decrypt: Decrypt text using the Vigenère Cipher.

Console Input: Enter the encrypted text and the key directly in the console.
File Input: Provide the name of the file containing the encrypted text and the key.


Example
Caesar Cipher
Encryption:

Enter the text you want to encrypt: hello
Enter the key: 3
The encrypted text is: khoor

Decryption:

Enter the encrypted text you want to decrypt: khoor
Enter the key: 3
The decrypted text is: hello

Vigenère Cipher
Encryption:

Enter the text you want to encrypt: hello
Enter the key: key
The encrypted text is: riijv

Decryption:

Enter the encrypted text you want to decrypt: riijv
Enter the key: key
The decrypted text is: hello

Implementation Details
Classes
  EncryptDecrypt: Contains methods for encrypting and decrypting text using both the Caesar and Vigenère ciphers.

Methods
  EncryptCaesarCipher: Encrypts text using the Caesar Cipher.
  DecryptCaesarCipher: Decrypts text using the Caesar Cipher.
  EncryptVigenereCipher: Encrypts text using the Vigenère Cipher.
  \DecryptVigenereCipher: Decrypts text using the Vigenère Cipher.

Contributing
Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.
