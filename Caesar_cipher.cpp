#include <iostream>
using namespace std;
string operation;
int key;
void info();
void encrypt();
void decrypt();
int main(){
    info();
    if(operation=="encrypt")
        encrypt();
    else if(operation=="decrypt")
        decrypt();
    return 0;
} 
void info(){            //input operations and key
    cout << "Choose operation (encrypt/decrypt): ";
    cin >> operation;
    if(operation!="encrypt"&&operation!="decrypt")
        cout << "Invalid input!";
    else{
        cout << "Input the key: ";
        cin >> key;
    }
    return;
}
void encrypt(){         //encrypt the plain text
    string plain_text;
    int cipher_text;
    cout << "Input the plain text: ";
    cin.ignore();       //handle the enter after inputing the key
    getline(cin, plain_text);
    cout << "The cipher text is: ";
    for (int i = 0; i < plain_text.length();i++){
        if(plain_text[i]>='A'&&plain_text[i]<='Z'){     //handle the letter which is upper-case
            cipher_text = plain_text[i] + key - 'A';    //rather than start with 0, the upper-case letter start from 'A'(ASCII: 65)
            cipher_text %= 26;                          //the relative position of cipher_text starting from 0
            cipher_text += 'A';                         //plus the start position, it will become the absolute position
            cout << ((char)cipher_text);
        }
        else if(plain_text[i]>='a'&&plain_text[i]<='z'){//handle the letter which is lower-case
            cipher_text = plain_text[i] + key - 'a';    //rather than start with 0, the upper-case letter start from 'a'(ASCII: 97)
            cipher_text %= 26;                          //the relative position of cipher_text starting from 0
            cipher_text += 'a';                         //plus the start position, it will become the absolute position
            cout << ((char)cipher_text);
        }
        else
            cout << plain_text[i];      //if it's not a english letter, output it directly
    }
    cout << endl;
    return;
}
void decrypt(){                         //decryption is roughly in contrast to encryption                               
    string cipher_text;
    int plain_text;
    cout << "Input the cipher text: ";
    cin.ignore();
    getline(cin, cipher_text);
    cout << "The plain text is: ";
    for (int i = 0; i < cipher_text.length();i++){
        if(cipher_text[i]>='A'&&cipher_text[i]<='Z'){       //handle the letter which is upper-case
            plain_text = 'Z' - (cipher_text[i] - key);
            plain_text %= 26;
            plain_text = 'Z' - plain_text;
            cout << ((char)plain_text);
        }
        else if(cipher_text[i]>='a'&&cipher_text[i]<='z'){  //handle the letter which is lower-case
            plain_text = 'z' - (cipher_text[i] - key);
            plain_text %= 26;
            plain_text = 'z' - plain_text;
            cout << ((char)plain_text);
        }
        else
            cout << cipher_text[i];         //if it's not a english letter, output it directly
    }
    cout << endl;
    return;
}