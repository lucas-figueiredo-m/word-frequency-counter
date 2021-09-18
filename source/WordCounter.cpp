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
  u_long i;
  static string eraseMap(".:;,?!/-_\\()[]{}=\"*#\n\r\0r");
  int num;

  Hashlist hash(37);

  file.open(fileName);

  if ( file.is_open() ) {
    while ( getline(file, line) ) {

      stringstream stream(line);
      
      cout << line << endl;

      for (i = 0; i < eraseMap.length(); i++) 
        line.erase(remove(line.begin(), line.end(), eraseMap.at(i)), line.end());

      cout << line << endl;

      if ( line.length() > 0 && line != " " && line != "" ) {
        stream >> subs;

        while (stream) {

          for (i = 0; i < eraseMap.length(); i++) 
            subs.erase(remove(subs.begin(), subs.end(), eraseMap.at(i)), subs.end());
          cout << subs << endl;
          hash.Insert(subs);
          stream >> subs;
        }
      }
    }

    hash.Print();
  }
}

// void WordCounter::OpenFile(string fileName) {
//   string line, word, subs;
//   fstream file;
//   u_long i;
//   static string eraseMap(".:;,?!/-_\\()[]{}=\"*#\n\r ");
//   int num;

//   Hashlist hash(37);

//   file.open(fileName);

//   if (file.is_open()) {
//     while ( getline(file, line) ) {
//       stringstream stream(line);

//       if (line.length() > 0 && line != " ") {
//         stream >> subs;
//         cout << line << endl;
//         while (stream) {
//           for (i = 0; i < eraseMap.length(); i++) 
//             subs.erase(remove(subs.begin(), subs.end(), eraseMap.at(i)), subs.end());
          
//           if (subs.length() > 0 && subs != " " && subs.at(0) != ' ' ) {
//             cout << subs << "\tLength: " << subs.length() << endl; 
//             hash.Insert(subs);
//           }
//           stream >> subs;
//         }
//       }
//     }

//     file.close();
//   }

//   hash.Print();
// }

WordCounter::WordCounter(string filePath) {

  string pathEnding = filePath.substr( filePath.length() - 4 );

  if ( !pathEnding.compare(".txt") ) {
    WordCounter::OpenFile(filePath);
  } else
    cout << "folder" << endl;
}
