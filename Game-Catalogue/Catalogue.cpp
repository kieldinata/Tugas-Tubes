#include "Catalogue.h"

//[GAME]
void createListGame(ListGame &G){
    G.first = nullptr;
    G.last = nullptr;
}
bool isEmptyGame(ListGame G){
    return G.first == nullptr && G.last == nullptr;
}
adrGame createElementGame(Game gameInfo){
    adrGame p;
    p = elemenGame;
    p->info = newGame;
    p->firstChar = nullptr;
    p->next = nullptr;
    p->prev = nullptr;

}
void addGame(ListGame &G, adrGame game){
    adrGame p = G.first;

    //jika kosong insert biasa, kalau tidak berurutan berdasarkan nama game
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
adrGame searchGame(ListGame G, string gameName){
    adrGame p;
    p = G.first;
    while (p != nullptr && p->info.nama != gameName){
        p = p->next;
    }
    return p;
}
adrGame searchGameWithCharacter(ListGame G, string charaName){
    adrGame p;
    adrCharacter q;
    p = G.first;
    while (p != nullptr){
        q = p->firstChar;
        while (q != nullptr){
            if (q->info.nama == charaName){
                return p;
            }
            q = q->next;
        }
        p = p->next;
    }
    return nullptr;
}
void deleteGame(ListGame &G, string gameName){
    adrGame game;
    game = searchGame(G, gameName);
    if (game != nullptr){
        deleteAllCharacter(game, game->firstChar);
        game->firstChar = nullptr;
        if (game->prev == nullptr && game->next == nullptr){
            G.first = nullptr;
            G.last = nullptr;
        } else if (game->prev == nullptr && game->next != nullptr){
            game->next->prev = nullptr;
            G.first = game->next;
        } else if (game->prev != nullptr && game->next != nullptr){
            game->prev->next = game->next;
            game->next->prev = game->prev;
        } else {
            game->prev->next = nullptr;
            G.last = game->prev;
        }
        delete game;
    }
}
adrGame GameWithMostCharacter(ListGame G){
    adrGame p, most;
    adrCharacter q;
    most = nullptr;
    int biggest = 0;
    int charCount = 0;
    p = G.first;
    while (p != nullptr){
        charCount = countCharacterInGame(p->firstChar);
        if (charCount > biggest){
            biggest = charCount;
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

//[CHARACTER]
bool isEmptyCharacter(adrGame C){
    retun C.firstChar == nullptr;
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
    if (C.firstChar == nullptr){
        C.firstChar = chara;
    } else {
        p = C.firstChar;
        while (p->next != nullptr){
            p = p->next;
        }
        p->next = chara;
    }
}
adrCharacter searchCharacter(ListGame G, string charaName){
    adrGame p;
    adrCharacter q;
    p = G.first;
    while (p != nullptr){
        q = p->firstChar;
        while (q != nullptr && q->info.nama != charaName){
            q = q->next;
        }

        if (q != nullptr){
            return q;
        }

        p = p->next;
    }

    return nullptr;
}
void deleteCharacter(ListGame G, string charaName){
    adrCharacter chara, prec;
    adrGame p;

    chara = searchCharacter(G, charaName);
    p = searchGameWithCharacter(G, charaName);

    if (chara != nullptr && p != nullptr){
        if (p->firstChar == chara){
            p->firstChar = chara->next;
        } else {
            prec = p->firstChar;
            while (prec->next != chara){
                prec = prec->next;
            }
            prec->next = chara->next;
        }
        chara->next = nullptr;
        delete chara;
    }
}
void deleteAllCharacter(adrGame &C, adrCharacter &chara){
    if (chara != nullptr){
        deleteAllCharacter(C, chara->next);
        delete chara;
    }
}
                                      //poin i

//[FIGHT SIMULATOR]
void chooseCharacter(ListGame &G, vector<Character> &chosenChar, string charaName, bool &valid){
    adrCharacter found = searchCharacter(G, charaName);

    if (found != nullptr){
        valid = true;
        chosenChar.push_back(found->info);
    } else {
        valid = false;
    }
}
Character simulateFight(vector<Character> &chosenChar){
    if (chosenChar.size() == 1){
            return chosenChar[0];
    }

    while (chosenChar.size() > 1){
        Character p1 = chosenChar.back();
        chosenChar.pop_back();

        Character p2 = chosenChar.back();
        chosenChar.pop_back();

        Character winner = duel(p1, p2);
        chosenChar.push_back(winner);
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



//[POWER RANK]
void initCharVector(ListGame G, vector<Character> &charVector){
    adrGame p;
    adrCharacter q;
    int counter = 0;
    charVector.clear();
    p = G.first;
    while (p != nullptr){
        q = p->firstChar;
        while (q != nullptr){
            charVector.push_back(q->info);
            counter++;
            q = q->next;
        }
        p = p->next;
    }
}
int calcPower(Character c){
    return (c.strength + c.hp) * c.agility * c.battleIQ + c.experience;
}
void sortCharacterRank(vector<Character> &charVector){
    int n = charVector.size();
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (calcPower(charVector[j]) < calcPower(charVector[j + 1])){
                Character temp = charVector[j];
                charVector[j] = charVector[j + 1];
                charVector[j + 1] = temp;
            }
        }
    }
}

