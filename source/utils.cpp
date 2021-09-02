#include "utils.h"

void OpenFile(string fileName) {
  string line;
  fstream file;
  file.open(fileName.append(".txt"));

  if (file.is_open()) {
    while (getline(file, line) ) {
      cout << line << "\n";
    }

    file.close();
  }
}

string getFilePath() {
  string answer, filePath;
  char tmp[256];
  getcwd(tmp, 256);
  string dir(tmp);


  cout << "\n----------------------------------------------------------------------------------------------\n";
  cout << "Bem vindo ao contador de palavras.\nO que deseja fazer?\n";
  cout << "1. Abrir um arquivo .txt\n";
  cout << "2. Abrir um lote de arquivos .txt (todos dentro de uma pasta)\n";
  cout << "3. Qualquer outra tecla encerra o programa\n\nDigite aqui: ";
  cin >> answer;
  cout << "\n----------------------------------------------------------------------------------------------\n";

  if (answer == "1") {
    cout << "\n\nDigite o nome do arquivo .txt que deseja abrir" << endl;
    cout << "ATENÇÃO: Seu diretório atual é " << dir;
    cout << "\nCaso o arquivo esteja nessa pasta, digite somente o nome do arquivo.";
    cout << "\nCaso contrário, digite o caminho inteiro\n\nDigite aqui: ";
    cin >> filePath;
    filePath.append(".txt");

  } else if (answer == "2") {
    cout << "Digite o nome da pasta que deseja abrir. Garanta que hajam arquivos .txt dentro" << endl;
    cout << "ATENÇÃO: Seu diretório atual é " << dir;
    cout << "\nCaso a pasta esteja nesse diretório, digite somente o nome da pasta";
    cout << "\nCaso contrário, digite o caminho inteiro\n\nDigite aqui: ";
    cin >> filePath;
    

  } else {
    cout << "Encerrando programa" << endl;
    exit(1);
  }

  if (filePath.find('/') != string::npos) 
    dir = "";

  
  dir.append("/");
  dir.append(filePath);

  return dir;
}

Hashlist::Hashlist(uint m) {
  length = m;
  wordCount = 0;
  table = (HashNode_t **) malloc(m * sizeof(HashNode_t));
}

uint Hashlist::hashString (string k) {
  hash<string> h1;
  size_t h = h1(k);
  return (uint) (h % length);
}

void Hashlist::Insert(string word) {
  cout << 1 << endl;
  uint h = hashString( word );
  cout << 2 << endl;

  HashNode_t *newNode = (HashNode_t *) malloc( sizeof(HashNode_t) );
  cout << 3 << endl;
  newNode->count = 1;
  cout << "4" << endl;
  int i;
  for (i = 0; i < word.length(); i++)
    printf("\t%d\n", word.at(i));

  cout << 4.1 << endl;  
  newNode->info = (string) word;
  cout << 5 << endl;
  
  if ( table[h] == nullptr) {
    newNode->next = nullptr;
    table[h] = newNode;
    wordCount += 1;
  } else{
    HashNode_t *node = table[h];
    while (node != nullptr) {
      if (node->info == newNode->info){
        node->count += 1;
        break;
      } 
      node = node->next;
    }

    if (node == nullptr) {
      newNode->next = table[h];
      table[h] = newNode;
      wordCount += 1;
    }
  }
}

void Hashlist::Print() {
  uint i;
  HashNode_t *aux;
  for (i = 0; i < length; i++) {
    printf("[%d] -> ", i);
    aux = table[i];

    while (aux != nullptr) {
      printf("%s(%d) ->  ", aux->info.c_str(), aux->count);
      aux = aux->next;
    }

    printf("NULL\n");
  }
  printf("\nWords: %d\n", wordCount);
}