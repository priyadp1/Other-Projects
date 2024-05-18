//
//  main.cpp
//  Project1
//
//  Created by Prisha Priyadashini on 9/24/23.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;
class WordSearch{
public:
    bool findWord(char* word);
    void readFile(string s1);
    vector <vector <char> > singles;
    vector <vector <char> > singles2;
    void print();
    bool checkRight(char* word);
    bool checkLeft(char* word);
    bool checkUp(char* word);
    bool checkDown(char* word);
    bool checkDiagRUp(char* word);
    bool checkDiagRDown(char* word);
    bool checkDiagLUp(char* word);
    bool checkDiagLDown(char* word);
    void copyMatrix(char* word);
    void showWord(char* word);
};
void WordSearch::readFile(string s1){
    fstream input;
    input.open(s1);
    string line;
    bool firstTime = true;
    while(!input.eof()){
        getline(input , line);
        if(!firstTime){
            vector<char> letters;
            for(int i = 0; i < line.length(); i++){
                if(line[i] != ' '){
                    letters.push_back(line[i]);
                }
            }
            if (letters.size() > 0){
                singles.push_back(letters);
            }

        }
        
        firstTime = false;
    }
    input.close();
}
void WordSearch::copyMatrix(char* word){
    for(int i = 0; i < singles.size(); i++){
        for(int j = 0; j < singles[i].size(); j++){
            singles2[i][j] = '*';
        }
    }
}
void WordSearch::showWord(char* word){
    for(int i = 0; i < singles.size(); i++){
        for(int j = 0; j < singles[i].size(); j++){
            if(word[0] == singles[i][j]){
                checkRight(word) || checkLeft(word)|| checkUp(word) ||
                checkDown(word) || checkDown(word)|| checkDiagRUp(word)||
                checkDiagRDown(word)||checkDiagLUp(word)|| checkDiagLDown(word);
            }
        }
    }
    for(int i = 0; i < singles2.size(); i++){
        for(int j = 0; j < singles2[i].size(); j++){
            cout<<singles2[i][j];
        }
        cout << endl;
    }
}
bool WordSearch::checkRight(char* word){
    int endX = singles.size() - 1;
    int endY = (strlen(word) - 1) + y;
    if(endY > singles.size() - 1){
        return false;
    }
    else{
        for(int j = y; j <= endY; j++){
            if( singles[x][j] != word[j - y]){
                return false;
            }
        }
        return true;
    }
}
bool WordSearch::checkLeft(char* word){
    //int endX = x;
    int endY = y - (strlen(word) - 1);
    if(endY > 0){
        return false;
    }
    else{
        for(int j = y; j <= endY; j--){
            if( singles[x][j] != word[y - j]){
                return false;
            }
        }
        return true;
    }
        }
bool WordSearch::checkUp(char* word){
    int endX = x - (strlen(word) - 1);
    int endY = y;
    if(endX < 0){
        return false;
    }
    else{
        for(int i = x; i <= endX; i--){
            if( singles[i][y] != word[x - i]){
                return false;
            }
        }
        return true;
    }
}
bool WordSearch::checkDown(char* word){
    int endX = x + (strlen(word) - 1) ;
    int endY = y;
    if(endX > singles.size() - 1){
        return false;
    }
    else{
        for(int i = x; i <= endX; i++){
            if( singles[i][y] != word[i - x]){
                return false;
            }
        }
        return true;
    }
}
bool WordSearch::checkDiagRUp(char* word){
    int endX = x - (strlen(word) - 1);
    int endY = y + (strlen(word) - 1);
    if(endY > singles.size() - 1 || endX < 0){
        return false;
    }
    else{
        for(int j = y; j <= endY; j++){
            for(int i = x; i <= endX; i--){
                if(singles[x][y] != word[j - y]){
                    return false;
                }
            }
        }
        
        return true;
        
    }
}
bool WordSearch::checkDiagRDown(char* word){
    int endX = x + (strlen(word) - 1);
    int endY = y + (strlen(word) - 1) ;
    if(endX > singles.size() - 1 || endY > singles.size() - 1){
        return false;
    }
    else{
        for(int j = y; j <= endY; j++){
            for(int i = x; i <= endX; i++){
                if(singles[x][y] != word[j - y]){
                    return false;
                }
            }
        }
        
        return true;
    }
}
bool WordSearch::checkDiagLUp(char* word){
    int endX = x - (strlen(word) - 1) ;
    int endY = y - (strlen(word) - 1) ;
    if(endY < 0 || endX < 0){
        return false;
    }
    else{
        for(int j = y; j <= endY; j--){
            for(int i = x; i <= endX; i--){
                if(singles[x][y] != word[y - j]){
                    return false;
                }
            }
        }
        
        return true;
    }
}
bool WordSearch::checkDiagLDown(char* word){
    int endX = x - (strlen(word) - 1);
    int endY = (strlen(word) - 1) + y;
    if(endY > singles.size() - 1 || endX < 0){
        return false;
    }
    else{
        for(int j = y; j <= endY; j++){
            for(int i = x; i <= endX; i--){
                if(singles[x][y] != word[j - y]){
                    return false;
                }
            }
        }
        
        return true;
    }
}
bool WordSearch::findWord(char *word){
    for (int i = 0; i < singles.size(); i++){
        for(int j = 0; j < singles[i]; j++){
            bool found = false;
                if(found){
                    singles[i][j] = "*";
                }
                else{
                    for(int k = 1; k < strlen(word) k++){
                        if(singles[i][j] != word[k]){
                            return checkRight(word) || checkLeft(word)|| checkUp(word) ||
                            checkDown(word) || checkDown(word)|| checkDiagRUp(word)||
                            checkDiagRDown(word)||checkDiagLUp(word)|| checkDiagLDown(word);
                        }
                    }
                    singles[i][j] = "*";
                }
            }
        }
        
    }


int main(int argc, char* argv[]) {
    //char inputs;
    char* word;
    cout << "Enter your words: ";
    for(int i = 1; i < argc; i++){
        word = argv[i];
        cout << argv[i] <<"\n";
    }
    cin >> word;
    string fileName = argv[2];
    WordSearch file;
    file.readFile(fileName);
    if(!file.findWord(word)){
        for(int i = 0; i < singles.size(); i++){
            for(int j = 0; j <singles[i]; j++){
                singles[i][j] = "*";
            }
        }
    }
    return 0;
}
