// Scrivi un programma basato sulla tecnica dell'
// accesso indiretto ad un vettore per realizzare una lista di interi inseriti da tastiera,
// l'inserimento deve proseguire fin tanto che non viene inserito il numero 0, poi la lista viene stampata. 
// Realizza un secondo programma che affidi ad una funzione, l'operazione di stampa. 

#include <iostream>
#include <cstring>

using namespace std;

void stampa_parole(char word[]) {
  cout << word <<  endl;
}

int main(int argc, char* argv[]) {
  char parola1[30];
  char parola2[30];

  cout << "Inserisci una parola" << endl;
  cin >> parola1;
  char *p = parola1;
  char *j = parola2;

  while((*p) != '\0') {
    *j = *p;
    *p++;
    *j++;
  }

  *j = '\0';

  stampa_parole(parola2);

  return 0;
}