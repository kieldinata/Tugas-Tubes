#include <iostream>
#include <vector>
#include "Catalogue.h"
#include "Decoration.h"

using namespace std;

int main() {
    ListGame G;
    createListGame(G);

    int pilihan;
    bool jalan = true;

    do {
        printLogo();

        printLine();
        color("green");
        cout << "              MENU UTAMA" << endl;
        color("clear");
        printLine();

        cout << "1. Tambah Game" << endl;
        cout << "2. Tambah Karakter ke Game" << endl;
        cout << "3. Tampilkan Seluruh Game & Karakter" << endl;
        cout << "4. Game dengan Karakter Terbanyak" << endl;
        cout << "5. Fight Simulator" << endl;
        cout << "6. Power Rank Karakter" << endl;
        cout << "0. Keluar" << endl;
        printLine();

        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        system("cls"); // Jika bermasalah, boleh dihapus

        switch (pilihan) {
        case 1: {
            Game game;
            cout << "Nama Game       : ";
            getline(cin, game.nama);
            cout << "Genre           : ";
            getline(cin, game.genre);
            cout << "Tahun Rilis     : ";
            cin >> game.tahunRilis;
            cout << "Rating          : ";
            cin >> game.rating;
            cin.ignore();

            adrGame g = createElementGame(game);
            addGame(G, g);

            cout << "Game berhasil ditambahkan." << endl;
            pause();
            break;
        }

        case 2: {
            string namaGame;
            cout << "Masukkan nama game: ";
            getline(cin, namaGame);

            adrGame g = searchGame(G, namaGame);
            if (g == nullptr) {
                cout << "Game tidak ditemukan." << endl;
                pause();
                break;
            }

            Character c;
            cout << "Nama Karakter   : ";
            getline(cin, c.nama);
            cout << "Asal Dunia      : ";
            getline(cin, c.asalDunia);
            cout << "Peran          : ";
            getline(cin, c.peran);
            cout << "Ras            : ";
            getline(cin, c.ras);
            cout << "Strength       : ";
            cin >> c.strength;
            cout << "Agility        : ";
            cin >> c.agility;
            cout << "HP              : ";
            cin >> c.hp;
            cout << "Battle IQ       : ";
            cin >> c.battleIQ;
            cout << "Experience      : ";
            cin >> c.experience;
            cin.ignore();

            adrCharacter ch = createElementCharacter(c);
            addCharacter(g, ch);

            cout << "Karakter berhasil ditambahkan." << endl;
            pause();
            break;
        }

        case 3: {
            adrGame g = G.first;
            if (isEmptyGame(G)) {
                cout << "Data game kosong." << endl;
            } else {
                while (g != nullptr) {
                    cout << "\nGame: " << g->info.nama << endl;
                    cout << "----------------------------------" << endl;

                    adrCharacter c = g->firstChar;
                    if (c == nullptr) {
                        cout << "  (Tidak ada karakter)" << endl;
                    }
                    while (c != nullptr) {
                        cout << "  - " << c->info.nama << endl;
                        c = c->next;
                    }
                    g = g->next;
                }
            }
            pause();
            break;
        }

        case 4: {
            adrGame g = GameWithMostCharacter(G);
            if (g != nullptr) {
                cout << "Game dengan karakter terbanyak: "
                     << g->info.nama << endl;
            } else {
                cout << "Belum ada game." << endl;
            }
            pause();
            break;
        }

        case 5: {
            vector<Character> chosen;
            string namaChar;
            bool valid = true;

            cout << "Masukkan nama karakter (ketik 'stop' untuk mulai duel):" << endl;
            while (true) {
                cout << "> ";
                getline(cin, namaChar);
                if (namaChar == "stop") break;

                chooseCharacter(G, chosen, namaChar, valid);
                if (!valid) {
                    cout << "Karakter tidak ditemukan." << endl;
                    valid = true;
                }
            }

            if (chosen.size() < 2) {
                cout << "Minimal 2 karakter untuk duel." << endl;
            } else {
                Character winner = simulateFight(chosen);
                cout << "Pemenang duel: " << winner.nama << endl;
            }

            pause();
            break;
        }

        case 6: {
            vector<Character> chars;
            initCharVector(G, chars);
            sortCharacterRank(chars);

            cout << "POWER RANK KARAKTER" << endl;
            cout << "--------------------" << endl;
            for (int i = 0; i < chars.size(); i++) {
                cout << i + 1 << ". " << chars[i].nama
                     << " (Power: " << calcPower(chars[i]) << ")" << endl;
            }
            pause();
            break;
        }

        case 0:
            jalan = false;
            cout << "Terima kasih telah menggunakan aplikasi." << endl;
            break;

        default:
            cout << "Pilihan tidak valid." << endl;
            pause();
        }

    } while (jalan);

    return 0;
}
