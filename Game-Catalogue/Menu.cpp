#include "Menu.h"
#include "Catalogue.h"
#include "Decoration.h"
void mainMenu(ListGame &G){
    int pilihan = -1;
    while (pilihan != 0){
        printLogo();
        cout << "====== MENU UTAMA ======\n"
             << "1. Menu Input\n"
             << "2. Menu Search\n"
             << "3. Menu Delete\n"
             << "4. Menu View\n"
             << "5. Fight Simulator\n"
             << "0. Keluar\n"
             << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1){
            inputMenu(G);
        } else if (pilihan == 2){
            searchMenu(G);
        } else if (pilihan == 3){
            deleteMenu(G);
        } else if (pilihan == 4){
            viewMenu(G);
        } else if (pilihan == 5){
            fightMenu(G);
        } else if (pilihan == 0){
            cout << "Keluar dari program...\n";
        }
    }
}

//INPUT===============================================================================
void inputMenu(ListGame &G){
    int pilihan = -1;
    while (pilihan != 0){
        printLogo();
        cout << "--- MENU INPUT ---\n"
             << "1. Input Game\n"
             << "2. Input Karakter\n"
             << "0. Kembali\n"
             << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1){
            inputGameMenu(G);
        } else if (pilihan == 2){
            inputCharaMenu(G);
        }
    }
}
void inputGameMenu(ListGame &G){
    Game input;
    bool valid = false;
    while (!valid){
        printLogo();
        cout << "Masukkan data game!" << "\n";
        cout << "Nama\t\t:";
        getline(cin, input.nama);
        cout << "Genre\t\t:";
        getline(cin, input.genre);
        cout << "Rating (?/10)\t:";
        cin >> input.rating;
        cout << "Tahun Rilis\t:";
        cin >> input.tahunRilis;
        cin.ignore();
        valid = isValidGameToAdd(G, input);
    }
    addGame(G, createElementGame(input));
}
void inputCharaMenu(ListGame &G){
    Character input;
    string gameName;
    adrGame fromGame;
    bool validGame = false;
    bool validChara = false;
    printLogo();
    while (!validGame){
        printLogo();
        cout << "Masukkan nama game yang ingin ditambahkan karakternya!" << "\n";
        getline(cin, gameName);
        fromGame = findGame(G, gameName);
        validGame = fromGame != nullptr;
        invalidMessage(validGame, "Game");
    }
    while (!validChara){
        printLogo();
        cout << "Masukkan data character!" << "\n";
        cout << "Nama\t\t:";
        getline(cin, input.nama);
        cout << "Asal Dunia\t:";
        getline(cin, input.asalDunia);
        cout << "Peran\t\t:";
        getline(cin, input.peran);
        cout << "Ras\t\t:";
        getline(cin, input.ras);
        cout << "Strength\t:";
        cin >> input.strength;
        cout << "Agility\t\t:";
        cin >> input.agility;
        cout << "HP\t\t:";
        cin >> input.hp;
        cout << "Battle IQ\t:";
        cin >> input.battleIQ;
        cout << "Experience\t:";
        cin >> input.experience;
        cin.ignore();
        validChara = isValidCharacter(fromGame, input.nama);
        invalidMessage(validChara, "Karakter");
    }
    addCharacter(fromGame, createElementCharacter(input));

}


//SEARCH===============================================================================
void searchMenu(ListGame G){
    int pilihan = -1;
    while (pilihan != 0){
        printLogo();
        cout << "--- MENU SEARCH ---\n"
             << "1. Cari Game\n"
             << "2. Cari Karakter\n"
             << "0. Kembali\n"
             << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1){
            searchGameMenu(G);
        } else if (pilihan == 2){
            searchCharaMenu(G);
        }
    }
}
void searchCharaMenu(ListGame G){
    string charaName;
    vector<adrCharacter> result;
    printLogo();
    cout << "Masukkan nama karakter yang ingin dicari!\n ";
    getline(cin, charaName);
    result = findCharacter(G, charaName);
    printLogo();
    if (!result.empty()){
        cout << "Ditemukan " << result.size() << " karakter dengan nama '"
             << charaName << "'!\n\n";

        for (int i = 0; i < result.size(); i++){
            Character c = result[i]->info;
            cout << i+1
            << "   Nama        : " << c.nama << "\n"
            << "   Asal Dunia : " << c.asalDunia << "\n"
            << "   Peran      : " << c.peran << "\n"
            << "   Ras        : " << c.ras << "\n"
            << "   Strength   : " << c.strength << "\n"
            << "   Agility    : " << c.agility << "\n"
            << "   HP         : " << c.hp << "\n"
            << "   Battle IQ  : " << c.battleIQ << "\n"
            << "   Experience : " << c.experience << "\n\n";
        }
    } else {
        cout << "Karakter dengan nama \"" << charaName << "\" tidak ditemukan.\n";
    }
    pause();
}
void searchGameMenu(ListGame G){
    string gameName;
    adrGame result;
    adrCharacter p;
    printLogo();
    cout << "Masukkan nama game yang ingin dicari!\n";
    getline(cin, gameName);
    result = findGame(G, gameName);
    printLogo();
    if (result != nullptr){
        cout << "Game ditemukan!\n"
        << "   Nama       : " << result->info.nama << "\n"
        << "   Genre      : " << result->info.genre << "\n"
        << "   Tahun Rilis: " << result->info.tahunRilis << "\n"
        << "   Rating     : " << result->info.rating << "\n\n"
        << "Dengan karakter:\n";
        p = result->firstChar;
        while (p != nullptr){
            cout << "   " << p->info.nama << "\n";
            p = p->next;
        }
    } else {
        cout << "Game \"" << gameName << "\" tidak ditemukan.\n";
    }
    pause();
}

//DELETE===============================================================================
void deleteMenu(ListGame &G){
    int pilihan = -1;
    while (pilihan != 0){
        printLogo();
        cout << "--- MENU DELETE ---\n"
             << "1. Delete Game\n"
             << "2. Delete Karakter\n"
             << "3. Delete ALL.\n"
             << "0. Kembali\n"
             << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1){
            deleteGameMenu(G);
        } else if (pilihan == 2){
            deleteCharMenu(G);
        } else if (pilihan == 3){
            iForgor(G);
        }
    }
}
void deleteGameMenu(ListGame &G){
    string gameName;
    adrGame C;
    printLogo();
    cout << "Masukkan nama game yang ingin dihapus!\n";
    getline(cin, gameName);
    C = findGame(G, gameName);
    deleteGame(G, C);
    if (C != nullptr){
        cout << "Game \"" << gameName << "\" berhasil dihapus!\n";
    } else {
        cout << "Game \"" << gameName << "\" tidak ditemukan.\n";
    }

}
void deleteCharMenu(ListGame &G){
    string gameName, charaName;
    adrGame C;
    printLogo();
    cout << "Masukkan nama game asal karakter yang ingin dihapus!\n";
    getline(cin, gameName);
    cout << "Masukkan nama karakter yang ingin dihapus!\n";
    getline(cin, charaName);
    C = findGame(G, gameName);
    if (C != nullptr){
        deleteCharacterFromGame(C, charaName);
        cout << "Karakter dengan nama \"" << charaName << "\" "
        << "berhasil dihapus dari game \""
        << gameName << "\".\n";
    } else {
        cout << "Input nama game salah.\n";
    }
    pause();
}
void iForgor(ListGame &G){
    string confirm;
    printLogo();
    cout << "Yakin mau hapus semua data?\n"
         << "Kalau ya tulis \"IYADEHMAU\", Kesalahan dalam penulisan otomatis batal.\n";
    cin >> confirm;

    if (confirm == "IYADEHMAU"){
        byebyedata(G.first);
        G.first = nullptr;
        G.last = nullptr;
        printLogo();
        cout << "Katalog melupakan semua game beserta datanya...\n";
        pause();
    } else {
        cout << "Penghapusan dibatalkan.\n";
        pause();
    }
}


//VIEW===============================================================================
void viewMenu(ListGame G) {
    int pilihan = -1;
    while (pilihan != 0){
        printLogo();
        cout << "--- MENU VIEW ---\n"
             << "1. Seluruh Katalog\n"
             << "2. Game Karakter Terbanyak\n"
             << "3. Game A-Z\n"
             << "4. Game From Highest Rate\n"
             << "5. Game From Oldest\n"
             << "6. Rank Karakter Power\n"
             << "0. Kembali\n"
             << "Pilih: ";
        cin >> pilihan;
        cin.ignore();
        if (pilihan == 1){
            viewAllCatalog(G);
        } else if (pilihan == 2){
            viewGameMostCharacter(G);
        } else if (pilihan == 3){
            viewGameAZ(G);
        } else if (pilihan == 4){
            viewGameHighestRating(G);
        } else if (pilihan == 5){
            viewGameOldest(G);
        } else if (pilihan == 6){
            viewCharacterRankPower(G);
        }
    }
}
void viewAllCatalog(ListGame G){
    adrGame p = G.first;
    printLogo();
    if (p == nullptr){
        cout << "Katalog kosong.\n";
    } else {
        while (p != nullptr){
            cout << "========================\n";
            cout << "Nama       : " << p->info.nama << "\n";
            cout << "Genre      : " << p->info.genre << "\n";
            cout << "Tahun Rilis: " << p->info.tahunRilis << "\n";
            cout << "Rating     : " << p->info.rating << "\n";
            cout << "Karakter:\n";
            adrCharacter q = p->firstChar;
            if (q == nullptr) cout << "   - Tidak ada karakter\n";
            while (q != nullptr){
                cout << "   " << q->info.nama << "\n";
                q = q->next;
            }
            cout << "========================\n\n";
            p = p->next;
        }
    }
    pause();
}
void viewGameMostCharacter(ListGame G){
    adrGame most = GameWithMostCharacter(G);
    printLogo();
    if (most != nullptr){
        cout << "Game dengan karakter terbanyak: "
             << most->info.nama << " (" << most->info.jumlahKarakter << " karakter)\n";
    } else {
        cout << "Tidak ada game dalam katalog.\n";
    }
    pause();
}

void viewGameAZ(ListGame G){
    Game arr[100];
    int count = 0;
    printLogo();
    initGameArray(G, arr, count);
    sortGameWithParameter(arr, count, "nama");
    for(int i=0;i<count;i++){
        cout << i+1 << ". " << arr[i].nama << " (" << arr[i].genre << ")\n";
    }
    pause();
}
void viewGameHighestRating(ListGame G){
    Game arr[100];
    int count = 0;
    printLogo();
    initGameArray(G, arr, count);
    sortGameWithParameter(arr, count, "rating");
    for(int i=0;i<count;i++){
        cout << i+1 << ". " << arr[i].nama << " (Rating: " << arr[i].rating << ")\n";
    }
    pause();
}

void viewGameOldest(ListGame G){
    Game arr[100];
    int count = 0;
    printLogo();
    initGameArray(G, arr, count);
    sortGameWithParameter(arr, count, "tahun");
    for(int i=0;i<count;i++){
        cout << i+1 << ". " << arr[i].nama << " (Tahun: " << arr[i].tahunRilis << ")\n";
    }
    pause();
}
void viewCharacterRankPower(ListGame G){;
    Character arr[100];
    int count = 0;
    printLogo();
    initCharaArray(G, arr, count);
    sortCharacterRank(arr, count);
    for(int i=0;i<count;i++){
        cout << i+1 << ". " << arr[i].nama
             << " (Power: " << calcPower(arr[i]) << ")\n";
    }
    pause();
}


//FIGHT===================================================================================
void fightMenu(ListGame G){
    const int MAX_CHAR = 10;
    Character chosenChar[MAX_CHAR];
    int count = 0;
    string gameName, charaName;
    bool valid = false;
    bool inputting = true;
    while(inputting){
        printLogo();
        cout<<"--- FIGHT SIMULATOR ---\n"
        <<"Masukkan karakter yang akan bertarung.\n"
        <<"Ketik 'CANCEL' pada nama game atau karakter untuk memulai pertarungan.\n"
        <<"Nama Game: ";
        getline(cin, gameName);
        if (gameName == "CANCEL"){
            inputting = false;
        } else {
            cout<<"Nama Karakter: ";
            getline(cin, charaName);
            if (charaName == "CANCEL"){
                inputting = false;
            } else {
                chooseCharacterArray(G, chosenChar, count, gameName, charaName, valid);
                if (valid){
                    cout<< charaName <<" dari "<< gameName <<" ditambahkan ke pertarungan!\n";
                    pause();
                } else {
                    cout<<"Game atau karakter tidak ditemukan. Coba lagi.\n";
                    pause();
                }
            }
        }
    }
    if(count == 0){
        cout<<"Tidak ada karakter yang dipilih. Pertarungan dibatalkan.\n";
        pause();
    } else {
        printLogo();
        cout << "Pertarungan dimulai!\n";
        Character winner = simulateFight(chosenChar, count);
        cout<< "========================\n"
        << "Pemenang: "<<winner.nama<<" (HP tersisa: "<<winner.hp<<")\n"
        << "========================\n";
        pause();
    }
}
