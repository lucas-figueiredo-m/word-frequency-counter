#include "WordCounter.h"

static void list_dir(const char *path) {
  cout << path << endl;
  struct dirent *entry;
  DIR *dir = opendir(path);
  if (dir == NULL) {
      return;
  }

  while ((entry = readdir(dir)) != NULL) {
    string file(entry->d_name);
    if (file.at(0) != '.')
      cout << file << endl;
  }

  closedir(dir);
}

WordCounter::WordCounter() {
  string answer, filePath;
  char tmp[256];
  getcwd(tmp, 256);
  string dir(tmp);


  cout << "\n----------------------------------------------------------------------------------------------\n";
  cout << "Bem vindo ao contador de palavras.\nO que deseja fazer?\n";
  cout << "1. Abrir um arquivo .txt\n";
  cout << "2. Abrir um lote de arquivos .txt (todos dentro de uma pasta)\n";
  cout << "3. Fechar o programa\n\nDigite aqui: ";
  cin >> answer;
  cout << "\n----------------------------------------------------------------------------------------------\n";


  if (answer == "1") {
    cout << "\n\nDigite o nome do arquivo .txt que deseja abrir" << endl;
    cout << "ATENÇÃO: Seu diretório atual é " << dir;
    cout << "\nCaso o arquivo esteja nessa pasta, digite somente o nome do arquivo.";
    cout << "\nCaso contrário, digite o caminho inteiro\n\nDigite aqui: ";
    cin >> filePath;
  } else if (answer == "2") {
    cout << "Digite o nome da pasta que deseja abrir. Garanta que hajam arquivos .txt dentro" << endl;
    cout << "ATENÇÃO: Seu diretório atual é " << dir;
    cout << "\nCaso a pasta esteja nesse diretório, digite somente o nome da pasta";
    cout << "\nCaso contrário, digite o caminho inteiro\n\nDigite aqui: ";
    cin >> filePath;
    
    if (filePath.find('/') != string::npos) {
      dir = getenv("HOME");

    } else {
      
    }
      dir.append("/");
      dir.append(filePath);
      list_dir(dir.c_str());

  } else if (answer == "3") {
    cout << "Encerrando programa" << endl;
    exit(1);
  } else {
    cout << "Foi outra" << endl;
  }

}