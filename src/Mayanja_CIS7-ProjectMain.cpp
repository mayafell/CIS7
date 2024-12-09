#include <iostream>
#include <string>
using namespace std;
// Functions
string encrypt(string plainText, string inKey);
string decrypt(string plainText, string inKey);
string key(string plainText, string inKey);

int main() {
// Main asks the user to choose between encryption 
// and decryption. For both choices, the program subsequently 
// requests the user to input both their plaintext and their 
// key. Once input, the program calls upon either encrypt() 
// or decrypt() depending on what the user chose earlier. 
// After those functions finish, the program displays the 
// resulting text.
  string inKey, plainText, endText;
  int choice;
  
  cout << "Please input your initial text.\n"
       << "Non-alphabetic characters will be removed:\n";
  getline(cin,plainText);
  cout << "\nPlease input your key:\n" << endl;
  getline(cin,inKey);
  cout << "\nInput '1' for encryption, and input '2' for decryption:\n";
  cin >> choice;
  
  switch (choice)
  {
    case 1:
      endText = encrypt(plainText, inKey);
      break;
    case 2:
      endText = decrypt(plainText, inKey);
      break;
    default:
      break;
  }
  
  cout << "\n\nYour ending text is as follows: " << endText;
  return 0;
}
//

string encrypt(string plainText, string inKey) {
// This function encrypts the input text and returns it.
  string endTextE, trueKey;
  char j = 0; // key counter 
  
  trueKey = key(plainText, inKey);
  
  for (int i=0; i < plainText.length(); i++) 
  {
    //normalize
    char c = plainText[i];
    c = toupper(c);
    
    //encrypt & skip characters
    if ((plainText[i] >= 'a') && (plainText[i] <= 'z'))
    {
		  int x = (c + trueKey[j] - 6) % 26;
		  x += 'a';
		  endTextE.push_back(x);
		
      j++;
    }
    else if ((plainText[i] >= 'A') && (plainText[i] <= 'Z'))
    {
		  int x = (c + trueKey[j] - 6) % 26;
		  x += 'A';
		  endTextE.push_back(x);
		
      j++;
    }
    else
    {
      continue;
    }
    
  }
  
  return endTextE; 
}
//

string decrypt(string plainText, string inKey) {
// This function decrypts the input text and returns it.
  string endTextD, trueKey;
  char j = 0; // key counter 
  
  trueKey = key(plainText, inKey);
  
  for (int i=0; i < plainText.length(); i++) 
  {
    //normalize
    char c = plainText[i];
    c = toupper(c);
    
    //decrypt & skip characters
    if ((plainText[i] >= 'a') && (plainText[i] <= 'z'))
    {
		  int x = (c - trueKey[j] + 58) % 26;
		  x += 'a';
		  endTextD.push_back(x);
		
      j++;
    }
    else if ((plainText[i] >= 'A') && (plainText[i] <= 'Z'))
    {
		  int x = (c - trueKey[j] + 58) % 26;
		  x += 'A';
		  endTextD.push_back(x);
		
      j++;
    }
    else
    {
      continue;
    }
    
  }
  
  return endTextD; 
}
//
  
string key(string plainText, string inKey) {
// This function creates a key with more
// length than plainText and returns it.
  string trueKey = inKey;
  int keyNum;
  
  //Find the difference in length between the key and the text
 
    keyNum = plainText.length() - inKey.length();
  
  //Add to the key until it's greater length
    
    if (keyNum > 0)
    {
      do 
      {
        trueKey = trueKey + inKey;
        keyNum = keyNum - inKey.length();
      } while (keyNum >= inKey.length());
      
      if (keyNum < inKey.length())
      {
        for (int i=0; i < inKey.length(); i++)
        {
          char c = inKey[i];
      
          trueKey = trueKey + c;
          keyNum = keyNum - 1;
        }
      }
    }
    else
    {
        trueKey = trueKey + inKey;
    }
  
  return trueKey;
}
//
