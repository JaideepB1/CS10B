#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int charCnt (string fileName, char ch) {
ifstream CharFS;

CharFS.open(fileName);
if (!CharFS.is_open()) {
    cout << "Error opening " << fileName << endl;
    exit(EXIT_FAILURE);
}

int Count = 0;
char input;


while (CharFS >> noskipws >> input) {
if (input == ch) {
    Count += 1;
}
}

CharFS.close();

return Count;

}

int main() {
   string fileName;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> fileName;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(fileName, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}