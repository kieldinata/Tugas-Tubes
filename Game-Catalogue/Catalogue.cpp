#include "Catalogue.h"

//[GAME]==========================================================================
void createListGame(ListGame &G){
    G.first = nullptr;
    G.last = nullptr;
}
bool isEmptyGame(ListGame G){
    return G.first == nullptr && G.last == nullptr;
}
adrGame createElementGame(Game gameInfo){
    adrGame p = new elemenGame;
    p->info = gameInfo;
    p->info.jumlahKarakter = 0;
    p->firstChar = nullptr;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}
void addGame(ListGame &G, adrGame game){
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
    adrGame p;
    p = G.first;
    while (p != nullptr && p->info.nama != gameName){
        p = p->next;
    }
    return p;
}
void deleteGame(ListGame &G, adrGame C){
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
    return C->firstChar == nullptr;
}
adrCharacter createElementCharacter(Character newChar){
    adrCharacter chara;
    chara = new elemenCharacter;
    chara->info = newChar;
    chara->next = nullptr;
    return chara;
}
void addCharacter(adrGame &C, adrCharacter chara){
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
    return (c.strength + c.hp) * c.agility * c.battleIQ + c.experience;
}
void sortCharacterRank(Character charArray[], int counter){
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
    if (chara == nullptr){
        return 0;
    }
    return 1 + countCharacterInGame(chara->next);
}


//======================================================================================
void byebyedata(adrGame &C){
    if (C != nullptr){
        adrGame nextGame = C->next;
        deleteAllCharacter(C, C->firstChar);
        delete C;
        C = nullptr;
        byebyedata(nextGame);
    }
}

