#include "Catalogue.h"

//[GAME]==========================================================================
void createListGame(ListGame &G){
// IS : ListGame G belum terinisialisasi.
// FS : ListGame G menjadi list kosong (first dan last bernilai NULL).

    G.first = nullptr;
    G.last = nullptr;
}
bool isEmptyGame(ListGame G){
// IS : ListGame G belum terinisialisasi.
// FS : ListGame G menjadi list kosong (first dan last bernilai NULL).

    return G.first == nullptr && G.last == nullptr;
}
adrGame createElementGame(Game gameInfo){
// IS : Data game (gameInfo) terdefinisi.
// FS : Menghasilkan satu elemen game baru dengan info sesuai gameInfo.

    adrGame p = new elemenGame;
    p->info = gameInfo;
    p->info.jumlahKarakter = 0;
    p->firstChar = nullptr;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}
void addGame(ListGame &G, adrGame game){
// IS : ListGame G terdefinisi, adrGame game terdefinisi.
// FS : Game ditambahkan ke dalam list game G.

    adrGame p = G.first;
    if (isEmptyGame(G)){
        G.first = game;
        G.last  = game;
    }
    else {
        while (p != nullptr && p->info.nama < game->info.nama){
            p = p->next;
        }
        if (p == G.first){
            game->next = G.first;
            G.first->prev = game;
            G.first = game;
        } else if (p == nullptr){
            game->prev = G.last;
            G.last->next = game;
            G.last = game;
        } else {
            game->next = p;
            game->prev = p->prev;
            p->prev->next = game;
            p->prev = game;
        }
    }
}
bool isValidGameToAdd(ListGame G, Game gameInfo){
// IS : ListGame G dan data game (gameInfo) terdefinisi.
// FS : Mengembalikan false jika game dengan nama yang sama sudah ada, dan true jika belum ada dalam ListGame G.

    adrGame p;
    if (isEmptyGame(G)){
        return true;
    }
    p = G.first;
    while (p != nullptr){
        if (p->info.nama == gameInfo.nama){
            return false;
        }
        p = p->next;
    }
    return true;
}
adrGame findGame(ListGame G, string gameName){
// IS : ListGame G dan nama game (gameName) terdefinisi.
// FS : Mengembalikan address game dengan nama gameName jika ditemukan, atau NULL jika tidak ditemukan.

    adrGame p;
    p = G.first;
    while (p != nullptr && p->info.nama != gameName){
        p = p->next;
    }
    return p;
}
void deleteGame(ListGame &G, adrGame C){
// IS : ListGame G terdefinisi, gameName terdefinisi.
// FS : Game dengan nama gameName beserta seluruh karakternya dihapus dari list.

    if (C == nullptr) return;
    deleteAllCharacter(C, C->firstChar);
    if (C->prev == nullptr && C->next == nullptr){
        G.first = nullptr;
        G.last = nullptr;
    } else if (C->prev == nullptr){
        G.first = C->next;
        G.first->prev = nullptr;
    } else if (C->next == nullptr){
        G.last = C->prev;
        G.last->next = nullptr;
    } else {
        C->prev->next = C->next;
        C->next->prev = C->prev;
    }
    delete C;
}



//[CHARACTER]==========================================================================
bool isEmptyCharacter(adrGame C){
// IS : adrGame C terdefinisi.
// FS : Mengembalikan true jika game tidak memiliki karakter.

    return C->firstChar == nullptr;
}
adrCharacter createElementCharacter(Character newChar){
// IS : Data karakter (newChar) terdefinisi.
// FS : Menghasilkan satu elemen karakter baru.

    adrCharacter chara;
    chara = new elemenCharacter;
    chara->info = newChar;
    chara->next = nullptr;
    return chara;
}
void addCharacter(adrGame &C, adrCharacter chara){
// IS : adrGame C dan adrCharacter chara terdefinisi.
// FS : Karakter ditambahkan ke dalam game C.

    adrCharacter p;
    if (isEmptyCharacter(C)){
        C->firstChar = chara;
    } else {
        p = C->firstChar;
        while (p->next != nullptr){
            p = p->next;
        }
        p->next = chara;
    }
    C->info.jumlahKarakter = countCharacterInGame(C->firstChar);
}
bool isValidCharacter(adrGame C, string charaName){
// IS : adrGame C dan nama karakter (charaName) terdefinisi.
// FS : Mengembalikan false jika karakter dengan nama charaName sudah ada, dan true jika belum ada pada game C

    adrCharacter p;
    p = C->firstChar;
    while (p != nullptr){
        if (charaName == p->info.nama){
            return false;
        }
        p = p->next;
    }
    return true;
}
vector<adrCharacter> findCharacter(ListGame G, string charaName){
// IS : ListGame G dan charaName terdefinisi.
// FS : Mengembalikan address karakter dengan nama charaName jika ditemukan.

    vector<adrCharacter> result;
    adrGame p = G.first;
    while (p != nullptr){
        adrCharacter q = p->firstChar;
        while (q != nullptr){
            if (q->info.nama == charaName){
                result.push_back(q);
            }
            q = q->next;
        }
        p = p->next;
    }
    return result;
}
adrCharacter findCharacterFromGame(adrGame C, string charaName){
// IS : adrGame C dan nama karakter (charaName) terdefinisi.
// FS : Mengembalikan address karakter dengan nama charaName jika ditemukan, atau NULL jika tidak ditemukan.

    adrCharacter p;
    p = C->firstChar;
    while (p != nullptr){
        if (p->info.nama == charaName){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}
void deleteCharacterFromGame(adrGame &C, string charaName) {
// IS : adrGame C dan nama karakter (charaName) terdefinisi.
// FS : Seluruh karakter dengan nama charaName dihapus dari game C dan jumlah karakter diperbarui.

    adrCharacter prec, chara, nextChar;
    prec = nullptr;
    chara = C->firstChar;
    nextChar = nullptr;
    while (chara != nullptr) {
        if (chara->info.nama == charaName) {
            nextChar = chara->next;
            if (prec == nullptr) {
                C->firstChar = nextChar;
            } else {
                prec->next = nextChar;
            }
            delete chara;
            chara = nextChar;
        } else {
            prec = chara;
            chara = chara->next;
        }
    }
    C->info.jumlahKarakter = countCharacterInGame(C->firstChar);
}

void deleteAllCharacter(adrGame &C, adrCharacter &chara){
// IS : adrGame C dan adrCharacter chara terdefinisi.
// FS : Seluruh karakter pada game C dihapus.

    if (chara != nullptr){
        deleteAllCharacter(C, chara->next);
        delete chara;
        chara = nullptr;
    }
}


//[FIGHT SIMULATOR]===============================================================================
void chooseCharacterArray(ListGame G, Character chosenChar[], int &count, string gameName, string charaName, bool &valid){
    adrGame C = findGame(G, gameName);
    if (C != nullptr){
        adrCharacter candidate = findCharacterFromGame(C, charaName);
        if (candidate != nullptr && count < MAX_FIGHTER){
            chosenChar[count] = candidate->info;
            count++;
            valid = true;
        } else {
            valid = false;
        }
    } else {
        valid = false;
    }
}
Character simulateFight(Character chosenChar[], int count){
// IS : Vector chosenChar berisi satu atau lebih karakter.
// FS : Mengembalikan karakter pemenang hasil simulasi pertarungan.

    int n = count;
    while (n > 1){
        Character p1 = chosenChar[n-1];
        Character p2 = chosenChar[n-2];
        Character winner = duel(p1, p2);
        chosenChar[n-2] = winner;
        n--;
    }
    return chosenChar[0];
}
int calcDamage(Character attacker, Character defender){
// IS : Karakter attacker dan defender terdefinisi.
// FS : Mengembalikan nilai damage dari attacker ke defender.

    int baseDmg = attacker.strength;
    int expBonus = attacker.experience / 10;
    int bIQBonus = attacker.battleIQ - defender.battleIQ;
    if (bIQBonus < 0){bIQBonus = 0;}
    float hitChance = float(attacker.agility) / (attacker.agility + defender.agility);
    float roll = (float)rand() / RAND_MAX;
    if (roll <= hitChance){
        return  1 * baseDmg + expBonus + bIQBonus;
    }
    return 0;
}
Character duel(Character p1, Character p2){
// IS : Dua karakter p1 dan p2 terdefinisi.
// FS : Mengembalikan karakter pemenang duel.

    bool turn = true;

    while (p1.hp > 0 && p2.hp > 0){
        if (turn){
            int dmg = calcDamage(p1, p2);
            p2.hp -= dmg;
        } else {
            int dmg = calcDamage(p2, p1);
            p1.hp -= dmg;
        }
        turn = !turn;
    }

    if (p1.hp > 0) {
            return p1;
    }
    return p2;
}



//[POWER RANK]===============================================================================
void initCharaArray(ListGame G, Character charArray[], int &counter){
    adrGame p;
    adrCharacter q;
    counter = 0;
    p = G.first;
    while (p != nullptr){
        q = p->firstChar;
        while (q != nullptr){
            charArray[counter] = q->info;
            counter++;
            q = q->next;
        }
        p = p->next;
    }
}
int calcPower(Character c){
// IS : Karakter c terdefinisi.
// FS : Mengembalikan nilai power karakter.

    return (c.strength + c.hp) * c.agility * c.battleIQ + c.experience;
}
void sortCharacterRank(Character charArray[], int counter){
// IS : Vector charVector terdefinisi.
// FS : Vector karakter diurutkan berdasarkan power tertinggi.

    for (int i = 0; i < counter - 1; i++){
        for (int j = 0; j < counter - i - 1; j++){
            if (calcPower(charArray[j]) < calcPower(charArray[j + 1])){
                Character temp = charArray[j];
                charArray[j] = charArray[j + 1];
                charArray[j + 1] = temp;
            }
        }
    }
}


//RANK GAME
void initGameArray(ListGame G, Game gameArray[], int &counter){
// IS : ListGame G terdefinisi dan counter belum berisi jumlah game.
// FS : Seluruh data game pada ListGame G disalin ke gameArray dan counter berisi jumlah game.

    adrGame p;
    counter = 0;
    p = G.first;
    while(p != nullptr){
        gameArray[counter] = p->info;
        counter++;
        p = p->next;
    }
}
void sortGameWithParameter(Game gameArray[], int counter, string parameter){
// IS : gameArray berisi counter data game dan parameter pengurutan terdefinisi.
// FS : gameArray terurut sesuai parameter (nama, rating, atau tahun rilis).

    bool tukar;
    for (int i = 0; i < counter - 1; i++){
        for (int j = 0; j < counter - i - 1; j++){
            tukar = false;
            if (parameter == "nama"){
                if (gameArray[j].nama > gameArray[j + 1].nama) tukar = true;
            } else if (parameter == "rating"){
                if (gameArray[j].rating < gameArray[j + 1].rating) tukar = true;
            } else if (parameter == "tahun"){
                if (gameArray[j].tahunRilis > gameArray[j + 1].tahunRilis) tukar = true;
            }
            if (tukar){
                Game temp = gameArray[j];
                gameArray[j] = gameArray[j + 1];
                gameArray[j + 1] = temp;
            }
        }
    }
}
adrGame GameWithMostCharacter(ListGame G){
// IS : ListGame G terdefinisi.
// FS : Mengembalikan address game yang memiliki jumlah karakter terbanyak.

    adrGame p, most;
    most = nullptr;
    int biggest = 0;
    p = G.first;
    while (p != nullptr){
        if (p->info.jumlahKarakter > biggest){
            biggest = p->info.jumlahKarakter;
            most = p;
        }
        p = p->next;
    }
    return most;
}
int countCharacterInGame(adrCharacter chara){
// IS : adrCharacter chara terdefinisi.
// FS : Mengembalikan jumlah karakter dalam satu game.

    if (chara == nullptr){
        return 0;
    }
    return 1 + countCharacterInGame(chara->next);
}


//======================================================================================
void byebyedata(adrGame &C){
// IS : adrGame C terdefinisi dan dapat menunjuk ke list game.
// FS : Seluruh game beserta seluruh karakter di dalamnya dihapus dari memori.

    if (C != nullptr){
        adrGame nextGame = C->next;
        deleteAllCharacter(C, C->firstChar);
        delete C;
        C = nullptr;
        byebyedata(nextGame);
    }
}

