#include <iostream>
#include <cstring>

using namespace std;

char* maiuscolo(char word[]);

int main(int argc, char* argv[]) {
  char parola[20];

  cout << "inserisci una parola" << endl;
  cin >> parola;
  cout << "parola: " << parola << endl;

  char *primo_carattere = maiuscolo(parola);
  
  cout << "parola maiuscola: " << parola << endl;
  cout << "primo carattere maiuscolo: " << *primo_carattere << endl;

  return 0;
}

char* maiuscolo(char word[]) {
  char* primo;
  for(int i=0;i<strlen(word);i++) {
    if(word[i] >= 97 || word[i] <= 122) {
      word[i] -= 32;
    }
  }
  primo = word;
  return primo;
}