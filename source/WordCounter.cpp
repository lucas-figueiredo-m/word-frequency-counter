#include "WordCounter.h"

WordCounter::WordCounter(string filePath) {
  string pathEnding = filePath.substr( filePath.length() - 4 );
  Trie *trie = new Trie();
  
  tr = trie;

  Hashlist *hash = new Hashlist(37);

  list = hash;

  if ( !pathEnding.compare(".txt") ) {
    WordCounter::OpenFile(filePath);
  } else
    cout << "folder" << endl;
}

void WordCounter::InsertIntoList (string word) {
  list->Insert(word);
}

void WordCounter::InsertIntoTrie (string word) {
  
}

void WordCounter::InsertIntoStructure (string fileName, void (WordCounter::*InsertFn)(string word)) {
  string line, subs;
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
          (this->*InsertFn)(subs);
          stream >> subs;
        }
      } 
    }
    
    file.close();
  }
}

void WordCounter::InsertListTime() {
  struct dirent *entry;
  string folder("folder2/"), filePath;
  DIR *dir = opendir(folder.c_str());
  if (dir == NULL)
    return;
  
  fstream csvFile;

  csvFile.open("list_insert.csv", ios::out | ios::trunc);
  csvFile << "data_size,time_spent" << "\n";
  const clock_t begin_time = clock();
  float time_spent;

  this->InsertFn = &WordCounter::InsertIntoList;

  while ((entry = readdir(dir)) != NULL) {
    string file(entry->d_name);
    if (file.at(0) != '.') {
      cout << file << endl;
      filePath.assign(folder);
      filePath.append(file);
      cout << filePath << endl;
      InsertIntoStructure(filePath, this->InsertFn );
      time_spent = float( clock () - begin_time ) / CLOCKS_PER_SEC;
      csvFile << list->totalWords << "," << time_spent << "\n";
      cout << list->totalWords << "," << time_spent << "\n";
    }
  }
  csvFile.close();
  closedir(dir);
}

void WordCounter::OpenFile(string fileName) {
  this->InsertFn = &WordCounter::InsertIntoList;
  // InsertIntoStructure(fileName, this->InsertFn);
}
