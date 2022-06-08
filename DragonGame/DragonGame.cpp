#include <iostream>
#include <windows.h>

using namespace std;

void showDragonOne() {
    cout << R"(                  ____====-_  _-====____                  )" << "\n";
    cout << R"(            _--^^^      //      \\      ^^^--_            )" << "\n";
    cout << R"(          _-^          // (    ) \\          ^-_          )" << "\n";
    cout << R"(        _-            //  |\^^/|  \\            -_        )" << "\n";
    cout << R"(      _-             //   (0::0)   \\             -_      )" << "\n";
    cout << R"(     _-             ((     \\//     ))             -_     )" << "\n";
    cout << R"(    _-               \\    (oo)    //               -_    )" << "\n";
    cout << R"(   _-                 \\  / \/ \  //                 -_   )" << "\n";
    cout << R"(  _-                   \\/      \//                   -_  )" << "\n";
    cout << R"( / /|           /\      (        )      /\           |\ \ )" << "\n";
    cout << R"(| / | /\_/\_/\_/  \_/\  (   /\   )  /\_/  \_/\_/\_/\ | \ |)" << "\n";
    cout << R"( '  |/                \_(| |  | |)_/  v    '  v  v  \|  ' )" << "\n";
    cout << R"(    '                  / | |  | | \           '  '   '    )" << "\n";
    cout << R"(                     <(  | |  | |  )>                     )" << "\n";
    cout << R"(                    <__\_| |  | |_/__>                    )" << "\n";
    cout << R"(                    ^^^^ ^^^  ^^^ ^^^^                    )" << "\n";
}

void showDragonTwo() {
    cout << R"(                  ____====-_  _-====____                  )" << "\n";
    cout << R"(            _--^^^      //      \\      ^^^--_            )" << "\n";
    cout << R"(          _-^          //        \\          ^-_          )" << "\n";
    cout << R"(        _-            //  (    )  \\            -_        )" << "\n";
    cout << R"(      _-             //   |\^^/|   \\             -_      )" << "\n";
    cout << R"(     _-             ((    (0::0)    ))             -_     )" << "\n";
    cout << R"(    _-               \\    \\//    //               -_    )" << "\n";
    cout << R"(   _-                 \\  /(oo)\  //                 -_   )" << "\n";
    cout << R"(  _-                   \\/  \/  \//                   -_  )" << "\n";
    cout << R"( / /|           /\      (        )      /\           |\ \ )" << "\n";
    cout << R"(| / | /\_/\_/\_/  \_/\  (   /\   )  /\_/  \_/\_/\_/\ | \ |)" << "\n";
    cout << R"( '  |/                \_(| |  | |)_/  v    '  v  v  \|  ' )" << "\n";
    cout << R"(    '                  / | |  | | \           '  '   '    )" << "\n";
    cout << R"(                     <(  | |  | |  )>                     )" << "\n";
    cout << R"(                    <__\_| |  | |_/__>                    )" << "\n";
    cout << R"(                    ^^^^ ^^^  ^^^ ^^^^                    )" << "\n";
}

int main()
{
    int dragonHealth;
    int spearmanHealth;

    int dragonDamage;
    int spearmanDamage;

    int spearmanNumber;
    int spearmanAllDamage;
    int spearmanAllHealth;
    int spearmanInjured = 0;
    int dragonLeftDamage;

    bool end = false;

    cout << "\t\t\tWelcome to the Dragon Game.\n";
    cout << "This program can calculate the number of spearmen needed to kill a dragon.\n\n";

    do
    {
        cout << "Enter Health of a Dragon: ";
        cin >> dragonHealth;

        cout << "Enter Damage of a Dragon: ";
        cin >> dragonDamage;

        cout << "Enter Health of a Spearman: ";
        cin >> spearmanHealth;

        cout << "Enter Damage of a Spearman: ";
        cin >> spearmanDamage;

        cout << "Enter Number of a Spearman: ";
        cin >> spearmanNumber;
    } while (dragonHealth < 1 && spearmanHealth < 1 && dragonDamage < 1 && spearmanDamage < 1);
    
    spearmanAllDamage = spearmanDamage * spearmanNumber;
    spearmanAllHealth = spearmanHealth * spearmanNumber;
    
    /*
    Копейщики атакуют (урон 200) – у дракона осталось 300 очков здоровья.
    Дракон атакует (урон 55) – осталось 15 копейщиков, один из которых ранен (осталось 5 очков здоровья).
    Копейщики атакуют (урон 150) – у дракона осталось 150 очков здоровья.
    Дракон атакует (урон 55) – осталось 9 копейщиков.
    Копейщики атакуют (урон 90) – у дракона осталось 60 очков здоровья.
    Дракон атакует (урон 55) – осталось 4 копейщика, один из которых ранен (осталось 5 жизней).
    Копейщики атакуют (урон 40) – у дракона осталось 20 очков здоровья.
    Дракон атакует  и побеждает.
    */
    
    while (true)
    {
        system("cls");
        showDragonOne();
        if (dragonHealth > 0 || spearmanNumber > 0)
        {
            // spearman attack
            
            spearmanAllDamage = spearmanDamage * spearmanNumber;
            
            dragonHealth -= spearmanAllDamage;

            if (dragonHealth < 1)
            {
                cout << "Spearmans attack and win Dragon.\n";
                break;
            }
            else
            {
                cout << "Spearmans attack Dragon: " << spearmanAllDamage
                    << " damage, Dragon health: " << dragonHealth << "\n";
            }
        }

        Sleep(2000);
        system("cls");
        showDragonTwo();
        if (dragonHealth > 0 || spearmanNumber > 0)
        {
            // dragon attack

            dragonLeftDamage = (spearmanAllHealth - dragonDamage) % spearmanHealth;

            if (dragonLeftDamage == 0)
            {
                spearmanNumber = (spearmanAllHealth - dragonDamage) / spearmanHealth;
                spearmanAllHealth = spearmanNumber * spearmanHealth;

                if (spearmanNumber < 1)
                {
                    cout << "Dragon attack and win Spearmans\n";
                    break;
                }
                else
                {
                    cout << "Dragon attack: " << dragonDamage << " damage, Spearmans left: " << spearmanNumber << "\n";
                }
            }
            else
            {
                spearmanInjured = spearmanHealth - dragonLeftDamage;
                spearmanNumber = (spearmanAllHealth - dragonDamage - spearmanInjured) / spearmanHealth + 1;
                spearmanAllHealth = spearmanNumber * spearmanHealth - spearmanInjured;

                if (spearmanNumber < 1)
                {
                    cout << "Dragon attack and win Spearmans\n";
                    break;
                }
                else
                {
                    cout << "Dragon attack: " << dragonDamage << " damage, Spearmans left: " << spearmanNumber << ", 1 with " << spearmanInjured << " health\n";
                }
            }
        }
        Sleep(2000);
    }
}