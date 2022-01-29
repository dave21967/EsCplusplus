#include <iostream>
#include <fstream>

using namespace std;

typedef struct Persona {
  string nome;
  string cognome;
  Persona* next;
} Persona;

typedef struct result {
  Persona* found;
  Persona* prev;
} Result;

Persona* push_head(Persona* l, string n, string c);
Persona* push_back(Persona* l, string n, string c);
void print_list(Persona* l);
Result* find(Persona* l, string nome_cercato, string cognome_cercato);
Persona* remove(Persona* l, string nome_da_cancellare, string cognome_da_cancellare);
bool empty(Persona* l);

int main(int argc, char* argv[]) {
  Persona* lista = NULL;
  ifstream f1;
  f1.open("ciao.txt");
  string data = " ";
  string delimiter = " ";

  while(getline(f1, data)) {
    string nome = data.substr(0, data.find(' '));
    string cognome = data.substr(data.find(' ')+1, (data.find(' '))+(data.size()));

    lista = push_back(lista, nome, cognome);
  }
  f1.close();

  cout << "lista prima della cancellazione" << endl;
  print_list(lista);

  lista = remove(lista, "gianni","fantoni");
  cout << "lista dopo la cancellazione" << endl;
  print_list(lista);

  return 0;
}

bool empty(Persona* l) {
  if(l == NULL)
    return true;
  else
    return false;
}

Persona* push_head(Persona* l, string n, string c) {
  if(!empty(l)) {
    Persona* temp = l;
    l = new Persona;
    l->nome = n;
    l->cognome = c;
    l->next = temp;
  }
  else {
    l = new Persona;
    l->nome = n;
    l->cognome = c;
    l->next = NULL;
  }
  return l;
}

Persona* push_back(Persona* l, string n, string c) {
  if(!empty(l)) {
    Persona* temp = l;
    while(temp->next != NULL) {
      temp = temp->next;
    }
    temp->next=push_head(NULL, n, c);
  }
  else {
    l=push_head(l, n, c);
  }
  return l;
}

//ricordati se usi la var di appoggio usala sempre
void print_list(Persona* l) {
  Persona* temp = l;
  while(temp != NULL) {
    cout << "Nome: " << temp->nome << endl;
    cout << "Cognome: " << temp->cognome << endl;
    temp = temp->next;
  }
}

Result* find(Persona* l, string nome_cercato, string cognome_cercato) {
  Persona* prev = NULL;
  Result* res = NULL;
  Persona* p = NULL;
  bool trovato = false;
  while(!empty(l) && !trovato) {
    if((l->nome.compare(nome_cercato)==0) && (l->cognome.compare(cognome_cercato)==0)) {
      res = new Result;
      res->found = l;
      res->prev = prev;
      trovato = true;
    }
    else {
      prev = l;
      l = l->next;
    }
  }
  return res;
}

Persona* remove(Persona* l, string nome_da_cancellare, string cognome_da_cancellare) {
  Persona* temp = l;
  Result* pos = find(temp, nome_da_cancellare, cognome_da_cancellare);
  if(!empty(pos->found)) {
    if(empty(pos->prev)) {
      temp = temp->next;
      delete pos->found;
    }
    else {
      pos->prev->next = pos->found->next;
      delete pos->found;
    }
  }
  return temp;
}