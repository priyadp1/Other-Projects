#include <iostream>
#include <cstdio>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
struct Info{
    string ssn;
};
string digits = "0123456789";
string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int elements = 1000;
Info* objects = new Info[elements];
int Indx = 0;
int iCounter = 0;
int dCounter = 0;
int rCounter = 0;

int search(string ssn){
    for(int i = 0; i < elements; i++){
        if(objects[i].ssn == ssn){
            return i;
        }
    }
    return - 1;
}

void ModifyLargeArray(){
    if(elements == (iCounter - dCounter)){
        elements = elements * 2;
        Info* newObjects = new Info[elements];
        for(int i = 0; i < Indx; i++){
            newObjects[i] = objects[i];
        }
        delete[] objects;
        objects = newObjects;
    }
}
 
void ModifySmallArray(){
    if((iCounter - dCounter) < (elements * 0.25)){
        elements = (elements / 2);
        Info* newObjects2 = new Info[elements];
        for(int i = 0; i < Indx; i++){
                newObjects2[i] = objects[i];
        }
        delete[] objects;
        objects = newObjects2;
    }
}

void insertion(string ssn){
    int x = search(ssn);
    if(x == -1){
            ModifyLargeArray();
            objects[Indx].ssn = ssn;
            Indx++;
            iCounter++;
    }
}

void deletion(string ssn){
    int x = search(ssn);
    if(x != -1){
            for(int i = x; i < elements; i++){
                objects[i] = objects[i+1];
            }
            dCounter++;
            Indx--;
            ModifySmallArray();
        }
        
    }

void retrieval(string ssn){
    int x = search(ssn);
    if(x != -1){
        rCounter++;
    }
}

void readCommand(char command , string ssn){
    if(command == 'i'){
        insertion(ssn);
        
        }
        else if(command == 'r'){
            retrieval(ssn);
        
        }
        else if(command == 'd'){
            deletion(ssn);
            
        }
    }

void readFile(string filename){
    fstream input;
    input.open(filename);
    string line;
    while(!input.eof()){
        getline(input , line);
        if(line.length() > 0){
            char command;
            command = line[0];
            long ssnPos = line.find_first_of(digits);
            string ssn = line.substr(ssnPos , 9);
            long firstPartOfName = line.find_first_of(letters);
            long lastPartOfName = line.find_last_of(letters);
            string name = line.substr(firstPartOfName , lastPartOfName);
            readCommand(command , ssn);
            
        }
    }
    input.close();
}
int main() {
cout << "Enter file name";
string filename;
cin >> filename;
clock_t start, end;
start = clock();
readFile(filename);
int numbOfElements = iCounter - dCounter;
double duration;
end = clock();
duration = ( end - start ) / (double) CLOCKS_PER_SEC;
cout << "The Number of Valid Insertation : " << iCounter << endl;
cout << "The Number of Valid Deletion : " << dCounter << endl;
cout << "The Number of Valid Retrieval : " << rCounter << endl;
cout << "Item numbers in the array : " << numbOfElements << endl;
cout << "Array Size is : " << elements << endl;
cout << "Time elapsed : " << duration << endl;
}

