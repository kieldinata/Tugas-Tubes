#include "Decoration.h"
void color(string c){
    if (c == "red") {cout << "\033[31m";}
    else if (c == "green") {cout << "\033[32m";}
    else if (c == "yellow") {cout << "\033[33m";}
    else if (c == "blue") {cout << "\033[34m";}
    else if (c == "magenta") {cout << "\033[35m";}
    else if (c == "cyan") {cout << "\033[36m";}
    else if (c == "clear") {cout << "\033[0m";}
}

void printLogo(){
    cout << endl;
    cout << AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA << endl;
    cout << endl;
}
void pause(){
    cout << endl <<"Press Enter to continue...";
    cin.ignore();
    cin.get();
}
