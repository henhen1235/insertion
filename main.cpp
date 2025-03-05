#include <iostream>
#include "dNode.h"

using namespace std;

void addfunc(dNode *& treehead);

int main(){
    dNode* treehead = NULL;
    while(true){
         char i2n[50];// ask user for what they want to do
        char add[50] = "add";
        char remove[50] = "remove";
        char display[50] = "display";
        cout << endl << "What would you like to do?: ";
        cin >> i2n;
        if(strcmp(i2n, add) == 0){
            addfunc(treehead);
        }
        else if(strcmp(i2n, remove) == 0){
        }
        else if(strcmp(i2n, display) == 0){
        }
        else{
            cout << "Invalid input options are: add, remove, and display" << endl;
        }
    }
    return 0;
}

void addfunc(dNode *& treehead){
    char in[50];
    char con[50] = "console";
    char fil[50] = "file";
    cout << endl << "Would you rather read in from console or file?: ";
    cin >> in;
    if(strcmp(in, con) == 0){
        char num[50];
        cout << "Enter the series of numbers you would like to add: ";
        cin >> num;
        int pos = 0;
        int tempnumpos = 0;
        int numarr[50];
        int numarrpos = 0;
        while(true){
            char tempnum[4];
            if(num[pos] != ' '){
                tempnum[tempnumpos] = num[pos];
                tempnumpos++;
                pos++;
            }
            else if(num[pos] == ' '){
                tempnum[tempnumpos] = '\0';
                tempnumpos = 0;
                int finnum = (int)tempnum - 48;
                numarr[numarrpos] = finnum;
                numarrpos++;
                pos++;
                cout << tempnum << endl;
            }
            else{
                break;
            }
        }
        for(int i = 0; i < numarrpos; i++){
            cout << numarr[i] << endl;
        }
    }
    else if(strcmp(in, fil) == 0){

    }
    else{
        cout << "Invalid input options are: console, and file" << endl;
    }

}