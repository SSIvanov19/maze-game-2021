#include <iostream>
using namespace std;
int main() {
    system("chcp 437");
    //This error generally occurs when a file contains characters that can only be saved by applying a Unicode code page.
    //Click Cancel, and then choose Save As on the File menu. From the Save drop-down list, choose Save with Encoding.
    //In the Advanced Save Options dialog choose, the encoding appropriate for your file.
    // US-ASCII- Codepage 20127
    char i = 1;
    int num = 1;
    while (num < 256) {
        num++;
        cout << num << " = " << i << endl;
        i++;
    }

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    char uSword = 179;
    char dSword = 216;
    char key = 12;
    char health = 3;
    char armor = 233;
    char wizard = 30;
    char money = 36;
    char firstMonster = 254;
    char secondMonster = 4;
    char fPartThirdMonster = 203;
    char sPartThirdMonster = 176;
    char fPartFourthMonster = 209;
    char sPartFourthMonster = 177;
    char bossFPart = 206;
    char bossSPart = 178;
    char bossTPart = 201;
    char bossFoPart = 184;
    char chest = 127;

    cout << chest << " = Chest = 127 (ASCII number)" << endl;
    cout << money << " = Money = 36 (ASCII number)" << endl;
    cout << uSword << " = up part sword = 179 (ASCII number)" << endl;
    cout << dSword << " = down part sword = 216 (ASCII number)" << endl;
    cout << key << " = Key = 12 (ASCII number)" << endl;
    cout << health << " = Health = 3 (ASCII number)" << endl;
    cout << armor << " = Armor = 233 (ASCII number)" << endl;
    cout << firstMonster << " = First monster = 254 (ASCII number)" << endl;
    cout << secondMonster << " = Second monster = 4 (ASCII number)" << endl;
    cout << fPartThirdMonster << " = First part third monster = 203 (ASCII number)" << endl;
    cout << sPartThirdMonster << " = Second part third monster = 176 (ASCII number)" << endl;
    cout << fPartFourthMonster << " = First part fourth monster = 209 (ASCII number)" << endl;
    cout << sPartFourthMonster << " = Second part fourth monster = 177 (ASCII number)" << endl;
    cout << bossFPart << " = First part fourth boss = 206 (ASCII number)" << endl;
    cout << bossSPart << " = Second part fourth boss = 178 (ASCII number)" << endl;
    cout << bossTPart << " = Third part fourth boss = 201 (ASCII number)" << endl;
    cout << bossFoPart << " = Fourth part fourth boss = 184 (ASCII number)" << endl;
    cout << endl;
    cout << " " << bossFPart << endl;
    cout << bossTPart << bossSPart << bossFoPart << " ~BOSS " << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    char healthMoney1 = 50;
    char healthMoney2 = 48;
    char armorMoney = 49;
    char swordMoney = 53;


    int rowRoom = 11;
    int colRoom = 41;
    for (int i = 0; i < rowRoom; i++) {
        for (int j = 0; j < colRoom; j++) {
            if (i > 0 && j > 0 && i < rowRoom - 1 && j < colRoom - 1)
            {
                if (i == 2 && j == 20) {
                    cout << wizard;
                }
                else if (i == 4 && j == 13) {
                    cout << healthMoney1;
                }
                else if (i == 4 && j == 14) {
                    cout << healthMoney2;
                }
                else if (i == 4 && j == 15) {
                    cout << money;
                }
                else if (i == 5 && j == 14) {
                    cout << health;
                }
                else if (i == 4 && j == 19) {
                    cout << armorMoney;
                }
                else if (i == 4 && j == 20) {
                    cout << healthMoney2;
                }
                else if (i == 4 && j == 21) {
                    cout << money;
                }
                else if (i == 5 && j == 20) {
                    cout << armor;
                }
                else if (i == 4 && j == 26) {
                    cout << swordMoney;
                }
                else if (i == 4 && j == 27) {
                    cout << money;
                }
                else if (i == 5 && j == 26) {
                    cout << uSword;
                }
                else if (i == 6 && j == 26) {
                    cout << dSword;
                }
                else {
                    cout << " ";
                }
            }
            else {
                cout << "#";
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;


    char bush = 157;
    char rock = 240;
    char holegl = 201;
    char holegd = 187;
    char holedl = 200;
    char holedd = 188;
    char holesr1 = 205;
    char holesr2 = 186;

    for (int i = 0; i < rowRoom; i++) {
        for (int j = 0; j < colRoom; j++) {
            if (i > 0 && j > 0 && i < rowRoom - 1 && j < colRoom - 1)
            {
                if (i == 4 && j == 3) {
                    cout << bush;
                }
                else if (i == 4 && j == 4) {
                    cout << bush;
                }
                else if (i == 4 && j == 5) {
                    cout << bush;
                }
                else if (i == 3 && j == 14) {
                    cout << rock;
                }
                else if (i == 5 && j == 15) {
                    cout << holegl;
                }
                else if (i == 5 && j == 16) {
                    cout << holesr1;
                }
                else if (i == 5 && j == 17) {
                    cout << holegd;
                }
                else if (i == 6 && j == 15) {
                    cout << holesr2;
                }
                else if (i == 6 && j == 17) {
                    cout << holesr2;
                }
                else if (i == 7 && j == 15) {
                    cout << holedl;
                }
                else if (i == 7 && j == 16) {
                    cout << holesr1;
                }
                else if (i == 7 && j == 17) {
                    cout << holedd;
                }
                else {
                    cout << " ";
                }
            }
            else {
                cout << "#";
            }
        }
        cout << endl;
    }
}