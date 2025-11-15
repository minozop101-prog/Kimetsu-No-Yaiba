#include <iostream>
#include <iomanip>

using namespace std;
int main() {
    int slayerLevel, hp, hasTalisman, demonPresence, demonRank, allyCount, bossHP, totalDamage, specialMoveReady;
    double breathingMastery, swordSharpness, adv, finalHP, power;
    char timeOfDay;
    cin >> slayerLevel >>  hp >> breathingMastery >> hasTalisman >> timeOfDay >> demonPresence >> demonRank >>
swordSharpness >> allyCount >> bossHP >> totalDamage >> specialMoveReady;
    cout << fixed << setprecision(1);
//Scene 1 :
    power = slayerLevel * 10 + hp / 10 + breathingMastery * 50;
    if(power >= 120) {
        cout << "[Scene 1] Rank: Hashira (power = " << power << ")\n";
    }
    else if(power < 120 && power >= 80) {
        cout << "[Scene 1] Rank: Elite (power = " << power << ")\n";
    }
    else {
        cout << "[Scene 1] Rank: Novice (power = " << power << ")\n";
    }
//Scene 2 :
    if(hasTalisman == 0){
        cout << "[Scene 2] Denied: No talisman.\n";
    }
    else if(timeOfDay != 'D' && timeOfDay != 'N'){
        cout << "[Scene 2] Warning: invalid timeOfDay.\n";
    }
    else if(timeOfDay == 'N' && demonPresence == 1){
        cout << "[Scene 2] Open silently.\n";
    }
    else{
        cout << "[Scene 2] Open cautiously.\n";
    }
//Scene 3 :
    adv = (101 - demonRank * 15) + swordSharpness * 0.4 + allyCount * 5;
    if(adv >= 100){
        cout << "[Scene 3] Engage head-on (adv = " << adv << ")\n";
    }
    else if(adv < 100 && adv >= 60){
        cout << "[Scene 3] Harass and probe (adv = " << adv << ")\n";
    }
    else if(adv < 60){
        cout << "[Scene 3] Retreat and regroup (adv = " << adv << ")\n";
    }

//Scene 4 :
cout << fixed << setprecision(0);
    finalHP = bossHP - totalDamage;
    if(finalHP <= 0){
        cout << "[Scene 4] Boss defeated! (finalHP = 0)\n";
    }
    else if(finalHP > 0 && specialMoveReady == 1 && finalHP <= 50){
        cout << "[Scene 4] Use special move to finish! (finalHP = " << (int)finalHP << ")\n";
    }
    else{
        cout << "[Scene 4] Withdraw to heal. (finalHP = " << (int)finalHP << ")\n";
    }
    return 0;
}