#include "Decoration.h"
void color(string c){
    if (c == "red") {
        cout << "\033[31m";
    } else if (c == "green") {
        cout << "\033[32m";
    } else if (c == "yellow") {
        cout << "\033[33m";
    } else if (c == "blue") {
        cout << "\033[34m";
    } else if (c == "magenta") {
        cout << "\033[35m";
    } else if (c == "cyan") {
        cout << "\033[36m";
    } else if (c == "clear") {
        cout << "\033[0m";
    }
}

void printLogo(){
    color("cyan");
    cout << endl;
    cout << "   ____    _    __  __ _____ " << endl;
    cout << "  / ___|  / \\  |  \\/  | ____|" << endl;
    cout << " | |  _  / _ \\ | |\\/| |  _|  " << endl;
    cout << " | |_| |/ ___ \\| |  | | |___ " << endl;
    cout << "  \\____/_/   \\_\\_|  |_|_____|" << endl;
    cout << endl;
    cout << "        GAME CATALOGUE SYSTEM" << endl;
    cout << endl;
    color("clear");
}



void printLine(){
    cout << "=========================================" << endl;
}

void pause(){
    cout << endl;
    color("yellow");
    cout << "Tekan ENTER untuk melanjutkan...";
    color("clear");
    cin.ignore();
    cin.get();
}


