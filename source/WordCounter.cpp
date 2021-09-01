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

void WordCounter::OpenFile(string fileName) {
  string line, word, subs;
  fstream file;
  int i;
  static string eraseMap(".:;,?!/-_\\");

  file.open(fileName);

  cout << "Aqui" << endl;

  if (file.is_open()) {
    while (getline(file, line) ) {
      istringstream stream(line);

      while (stream) {
        stream >> subs;
        for (i = 0; i < eraseMap.length(); i++) {
          subs.erase(remove(subs.begin(), subs.end(), eraseMap.at(i)), subs.end());
        }
        cout << "Substring: " << subs << endl;
      }
      // cout << line << "\n";
    }

    file.close();
  }
}

WordCounter::WordCounter(string filePath) {

  string pathEnding = filePath.substr( filePath.length() - 4 );

  if ( !pathEnding.compare(".txt") ) { 
    cout << "file" << endl;
    WordCounter::OpenFile(filePath);
    cout << "Puta merda" << endl;
  } else
    cout << "folder" << endl;
  

}