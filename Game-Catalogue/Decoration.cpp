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
    system("cls");
    color("cyan");
    cout << "\n"
    << "   ____    _    __  __ _____ " << "\n"
    << "  / ___|  / \\  |  \\/  | ____|" << "\n"
    << " | |  _  / _ \\ | |\\/| |  _|  " << "\n"
    << " | |_| |/ ___ \\| |  | | |___ " << "\n"
    << "  \\____/_/   \\_\\_|  |_|_____|" << "\n\n"
    << "        GAME CATALOGUE SYSTEM" << "\n\n";
    printLine();
    color("clear");
}



void printLine(){
    cout << "=========================================" << endl;
}

void pause(){
    color("yellow");
    cout << "\nTekan ENTER untuk melanjutkan...";
    color("clear");
    cin.get();

}

void invalidMessage(bool parameter, string salahApa){
    if (!parameter){
        cout << "\n" << salahApa
        << " invalid! Silahkan input ulang "
        << salahApa << "\n";
        pause();
    }
}

