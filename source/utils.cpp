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

static void list_dir(const char *path) {
  cout << path << endl;
  struct dirent *entry;
  DIR *dir = opendir(path);
  if (dir == NULL)
    return;
  
  while ((entry = readdir(dir)) != NULL) {
    string file(entry->d_name);
    if (file.at(0) != '.')
      cout << file << endl;
  }

  closedir(dir);
}

void InsertTimeSpent(string csvTitle, string csvHeader, void (*InsertFunction) (string fileName), int storageUse) {
  struct dirent *entry;
  string folder("folder/"), filePath;
  DIR *dir = opendir(folder.c_str());
  if (dir == NULL)
    return;
  
  fstream csvFile;

  csvFile.open(csvTitle, ios::out | ios::trunc);
  csvFile << csvHeader << "\n";
  const clock_t begin_time = clock();
  float time_spent;

  while ((entry = readdir(dir)) != NULL) {
    string file(entry->d_name);
    if (file.at(0) != '.') {
      cout << file << endl;
      filePath.assign(folder);
      filePath.append(file);
      cout << filePath << endl;
      InsertFunction(filePath);
      time_spent = float( clock () - begin_time ) / CLOCKS_PER_SEC;
      csvFile << storageUse << "," << time_spent << "\n";
      // cout << storageUse << "," << time_spent << "\n";
    }
  }
  csvFile.close();
  closedir(dir);
}