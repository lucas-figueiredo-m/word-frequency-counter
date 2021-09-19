#include "WordCounter.h"

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

void WordCounter::InsertIntoList (string fileName) {
  string line, word, subs;
  fstream file;
  u_long i;
  static string eraseMap(".:;,?!/-_\\()[]{}=\"*#\n\r\'\0");
  int num;
  const clock_t begin_time = clock();


  file.open(fileName);

  if ( file.is_open() ) {
    while ( getline(file, line) ) {
      
      for (i = 0; i < eraseMap.length(); i++) 
        line.erase(remove(line.begin(), line.end(), eraseMap.at(i)), line.end());

      stringstream stream(line);

      if ( line.length() > 0 && line != " " && line != "" ) {
        stream >> subs;

        while (stream) {
          list->Insert(subs);
          stream >> subs;
        }
      }
      
    }

    cout << "Time spent: " << float( clock () - begin_time ) / CLOCKS_PER_SEC << endl;
    cout << list->totalWords << "," << float( clock () - begin_time ) / CLOCKS_PER_SEC << "\n";
    
    list->Print();
  }

  file.close();
}

void WordCounter::InsertIntoTrie (string fileName) {
  
}

void WordCounter::InsertListTime() {
  fstream csvFile;
  csvFile.open("teste.csv", ios::out | ios::trunc);
  const clock_t begin_time = clock();


}

void WordCounter::OpenFile(string fileName) {
  fstream csvFile;
  csvFile.open("teste.csv", ios::out | ios::trunc);

  const clock_t begin_time = clock();
  InsertIntoList(fileName);
  float time_spent = float( clock () - begin_time ) / CLOCKS_PER_SEC;

  cout << "Time spent: " << time_spent << endl;

  csvFile << "file_size,time_spent" << "\n";
  csvFile << list->totalWords << "," << time_spent << "\n";


}

WordCounter::WordCounter(string filePath) {

  string pathEnding = filePath.substr( filePath.length() - 4 );

  Hashlist hash(37);
  *list = hash;

  if ( !pathEnding.compare(".txt") ) {
    WordCounter::OpenFile(filePath);
  } else
    cout << "folder" << endl;
}
