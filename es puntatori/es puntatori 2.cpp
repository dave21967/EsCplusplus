#include <iostream>

using namespace std;

int* inserimento(int* l) {
  int i=0;

  l = new int;

  do {
    cout << "inserisci un numero, inserisci 0 per uscire" << endl;
    cin >> l[i];
    i++;
  }while(l[i-1]);

  return l;
}

int main(int argc, char* argv[]) {
  int* p;

  p = inserimento(p);

  cout << "stampa lista" << endl;
  for(int i=0;p[i];i++) {
    cout << p[i] << endl;
  }
  cout << "fine" << endl;

  return 0;
}