#include "Decoration.h"

void color(string c){
// IS : Parameter warna (c) terdefinisi.
// FS : Warna teks output pada console berubah sesuai nilai c.

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
// IS : Layar console berada pada kondisi apa pun.
// FS : Layar console dibersihkan dan logo aplikasi ditampilkan.

    system("cls");
    color("cyan");
    cout << "\n"
    << "     ____    _    __  __ _____ " << "\n"
    << "    / ___|  / \\  |  \\/  | ____|" << "\n"
    << "   | |  _  / _ \\ | |\\/| |  _|  " << "\n"
    << "   | |_| |/ ___ \\| |  | | |___ " << "\n"
    << "    \\____/_/   \\_\\_|  |_|_____|" << "\n\n"
    << "        GAME CATALOGUE SYSTEM" << "\n";
    color("yellow");
    cout << "Oleh:\n"
    << "Yehezkiel Moreno Herdinata (103012400024)\n"
    << "Ditya Felix Eril Santoso   (103012400049)\n";
    color("cyan");
    printLine();
    color("clear");
}



void printLine(){
// IS : Kondisi output console aktif.
// FS : Garis pembatas ditampilkan pada console.

    cout << "============================================" << endl;
}

void pause(){
// IS : Program sedang berjalan.
// FS : Program berhenti sementara hingga user menekan ENTER.

    color("yellow");
    cout << "\nTekan ENTER untuk melanjutkan...";
    color("clear");
    cin.get();

}

void invalidMessage(bool parameter, string salahApa){
// IS : Parameter dan keterangan kesalahan (salahApa) terdefinisi.
// FS : Pesan kesalahan ditampilkan jika parameter bernilai false.

    if (!parameter){
        color("red");
        cout << "\n" << salahApa
        << " invalid! Silahkan input ulang "
        << salahApa;
        color("clear");
        pause();
    }
}

