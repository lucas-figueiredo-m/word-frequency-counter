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
  int i, j = 0;
  int count1 = 0, count2 = 0, count3 = 0;
  static string eraseMap(".:;,?!/-_\\()[]{}=\"*#\n\r ");

  Hashlist hash(37);

  file.open(fileName);

  if (file.is_open()) {
    while (getline(file, line)) {
      stringstream stream(line);
      j+=1;

      if (line.length() > 0 && line != " ") {
        stream >> subs;
        cout << line << endl;
        while (stream) {
          for (i = 0; i < eraseMap.length(); i++) 
            subs.erase(remove(subs.begin(), subs.end(), eraseMap.at(i)), subs.end());
          
          // cout << "Substring: " << subs << "\tLength: " << subs.length() << endl;
          count1 += 1;
          if (subs.length() > 0 && subs != " " && subs.at(0) != ' ' ) {
            count2 += 1;
            cout << subs << "\tLength: " << subs.length() << endl; 
            hash.Insert(subs);
          } else {
            count3 += 1;
          }
          stream >> subs;
        }
        // cout << "\n\n" << endl;
      }

      // cout << line << "\n";
    }

    file.close();
  }

  hash.Print();
  cout << "\n\nCount 1: " << count1 << endl;
  cout << "Count 2: " << count2 << endl;
  cout << "Count 3: " << count3 << endl;
}

WordCounter::WordCounter(string filePath) {

  string pathEnding = filePath.substr( filePath.length() - 4 );

  if ( !pathEnding.compare(".txt") ) { 
    cout << "file" << endl;
    WordCounter::OpenFile(filePath);
  } else
    cout << "folder" << endl;
  

}