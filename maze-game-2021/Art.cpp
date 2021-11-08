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
    char sPartFourthMonster = 215;
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
    cout << sPartThirdMonster << " = Second part third monster = 215 (ASCII number)" << endl;
    cout << fPartFourthMonster << " = First part fourth monster = 209 (ASCII number)" << endl;
    cout << sPartFourthMonster << " = Second part fourth monster = 215 (ASCII number)" << endl;
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


    int rowRoom = 17;
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
                else if (i == 5 && j == 5) {
                    cout << bush;
                }
                else if (i == 6 && j == 25) {
                    cout << bush;
                }
                else if (i == 7 && j == 25) {
                    cout << bush;
                }
                else if (i == 7 && j == 26) {
                    cout << bush;
                }
                else if (i == 11 && j == 15) {
                    cout << bush;
                }
                else if (i == 12 && j == 15) {
                    cout << bush;
                }
                else if (i == 12 && j == 14) {
                    cout << bush;
                }
                else if (i == 12 && j == 13) {
                    cout << bush;
                }
                else if (i == 1 && j == 14) {
                    cout << rock;
                }
                else if (i == 1 && j == 15) {
                    cout << rock;
                }
                else if (i == 1 && j == 16) {
                    cout << rock;
                }
                else if (i == 2 && j == 16) {
                    cout << rock;
                }
                else if (i == 15 && j == 35) {
                    cout << rock;
                }
                else if (i == 15 && j == 36) {
                    cout << rock;
                }
                else if (i == 15 && j == 37) {
                    cout << rock;
                }
                else if (i == 15 && j == 38) {
                    cout << rock;
                }
                else if (i == 14 && j == 38) {
                    cout << rock;
                }
                else if (i == 13 && j == 1) {
                    cout << rock;
                }
                else if (i == 14 && j == 1) {
                    cout << rock;
                }
                else if (i == 15 && j == 1) {
                    cout << rock;
                }
                else if (i == 14 && j == 2) {
                    cout << rock;
                }
                else if (i == 15 && j == 2) {
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
                else if (i == 2 && j == 28) {
                    cout << holegl;
                }
                else if (i == 2 && j == 29) {
                    cout << holesr1;
                }
                else if (i == 2 && j == 30) {
                    cout << holegd;
                }
                else if (i == 3 && j == 28) {
                    cout << holesr2;
                }
                else if (i == 3 && j == 30) {
                    cout << holesr2;
                }
                else if (i == 4 && j == 28) {
                    cout << holedl;
                }
                else if (i == 4 && j == 29) {
                    cout << holesr1;
                }
                else if (i == 4 && j == 30) {
                    cout << holedd;
                }
                else if (i == 10 && j == 26) {
                    cout << holegl;
                }
                else if (i == 10 && j == 27) {
                    cout << holesr1;
                }
                else if (i == 12 && j == 27) {
                    cout << holesr1;
                }
                else if (i == 10 && j == 28) {
                    cout << holegd;
                }
                else if (i == 11 && j == 28) {
                    cout << holesr2;
                }
                else if (i == 11 && j == 26) {
                    cout << holesr2;
                }
                else if (i == 12 && j == 26) {
                    cout << holedl;
                }
                else if (i == 12 && j == 28) {
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
    /*
    room[3][4] = bush;
        room[4][4] = bush;
        room[5][4] = bush;
        room[25][6] = bush;
        room[25][7] = bush;
        room[26][7] = bush;
        room[15][11] = bush;
        room[15][12] = bush;
        room[14][12] = bush;
        room[13][12] = bush;

        room[14][1] = rock;
        room[15][1] = rock;
        room[16][1] = rock;
        room[16][2] = rock;
        room[35][15] = rock;
        room[36][15] = rock;
        room[37][15] = rock;
        room[38][15] = rock;
        room[38][14] = rock;
        room[1][13] = rock;
        room[1][14] = rock;
        room[1][15] = rock;
        room[2][14] = rock;
        room[2][15] = rock;

        room[15][5] = holegl;
        room[16][5] = holesr1;
        room[17][5] = holegd;
        room[15][6] = holesr2;
        room[17][6] = holesr2;
        room[15][7] = holedl;
        room[16][7] = holesr1;
        room[17][7] = holedd;
        room[28][2] = holegl;
        room[29][2] = holesr1;
        room[30][2] = holegd;
        room[28][3] = holesr2;
        room[30][3] = holesr2;
        room[28][4] = holedl;
        room[29][4] = holesr1;
        room[30][4] = holedd;
        room[26][10] = holegl;
        room[27][10] = holesr1;
        room[27][12] = holesr1;
        room[28][10] = holegd;
        room[28][11] = holesr2;
        room[26][11] = holesr2;
        room[26][12] = holedl;
        room[28][12] = holedd;
    */


    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;


    for (int i = 0; i < rowRoom; i++) {
        for (int j = 0; j < colRoom; j++) {
            if (i > 0 && j > 0 && i < rowRoom - 1 && j < colRoom - 1)
            {
                if (i == 4 && j == 8) {
                    cout << holegl;
                }
                else if (i == 4 && j == 9) {
                    cout << holesr1;
                }
                else if (i == 4 && j == 10) {
                    cout << holesr1;
                }
                else if (i == 4 && j == 11) {
                    cout << holesr1;
                }
                else if (i == 4 && j == 12) {
                    cout << holesr1;
                }
                else if (i == 4 && j == 13) {
                    cout << holesr1;
                }
                else if (i == 4 && j == 14) {
                    cout << holesr1;
                }
                else if (i == 4 && j == 15) {
                    cout << holesr1;
                }
                else if (i == 4 && j == 16) {
                    cout << holesr1;
                }
                else if (i == 4 && j == 17) {
                    cout << holesr1;
                }
                else if (i == 4 && j == 18) {
                    cout << holesr1;
                }
                else if (i == 4 && j == 19) {
                    cout << holesr1;
                }
                else if (i == 4 && j == 20) {
                    cout << holesr1;
                }
                else if (i == 4 && j == 21) {
                    cout << holesr1;
                }
                else if (i == 4 && j == 22) {
                    cout << holesr1;
                }
                else if (i == 4 && j == 23) {
                    cout << holesr1;
                }
                else if (i == 4 && j == 24) {
                    cout << holesr1;
                }
                else if (i == 4 && j == 25) {
                    cout << holesr1;
                }
                else if (i == 4 && j == 26) {
                    cout << holesr1;
                }
                else if (i == 4 && j == 27) {
                    cout << holesr1;
                }
                else if (i == 4 && j == 28) {
                    cout << holesr1;
                }
                else if (i == 4 && j == 29) {
                    cout << holesr1;
                }
                else if (i == 4 && j == 30) {
                    cout << holesr1;
                }
                else if (i == 4 && j == 31) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 9) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 10) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 11) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 12) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 13) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 14) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 15) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 16) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 17) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 18) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 19) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 20) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 21) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 22) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 23) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 24) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 25) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 26) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 27) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 28) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 29) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 30) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 31) {
                    cout << holesr1;
                }
                else if (i == 4 && j == 32) {
                    cout << holegd;
                }
                else if (i == 5 && j == 32) {
                    cout << holesr2;
                }
                else if (i == 6 && j == 32) {
                    cout << holesr2;
                }
                else if (i == 7 && j == 32) {
                    cout << holesr2;
                }
                else if (i == 8 && j == 32) {
                    cout << holesr2;
                }
                else if (i == 9 && j == 32) {
                    cout << holesr2;
                }
                else if (i == 6 && j == 32) {
                    cout << holesr2;
                }
                else if (i == 10 && j == 32) {
                    cout << holesr2;
                }
                else if (i == 5 && j == 8) {
                    cout << holesr2;
                }
                else if (i == 6 && j == 8) {
                    cout << holesr2;
                }
                else if (i == 7 && j == 8) {
                    cout << holesr2;
                }
                else if (i == 8 && j == 8) {
                    cout << holesr2;
                }
                else if (i == 9 && j == 8) {
                    cout << holesr2;
                }
                else if (i == 10 && j == 8) {
                    cout << holesr2;
                }
                else if (i == 11 && j == 8) {
                    cout << holedl;
                }
                else if (i == 11 && j == 32) {
                    cout << holedd;
                }
                else if (i == 2 && j == 1) {
                    cout << bush;
                }
                else if (i == 1 && j == 1) {
                    cout << bush;
                }
                else if (i == 1 && j == 2) {
                    cout << bush;
                }
                else if (i == 5 && j == 35) {
                    cout << bush;
                }
                else if (i == 6 && j == 35) {
                    cout << bush;
                }
                else if (i == 15 && j == 1) {
                    cout << bush;
                }
                else if (i == 15 && j == 2) {
                    cout << bush;
                }
                else if (i == 15 && j == 3) {
                    cout << bush;
                }
                else if (i == 15 && j == 4) {
                    cout << bush;
                }
                else if (i == 14 && j == 1) {
                    cout << bush;
                }
                else if (i == 12 && j == 18) {
                    cout << bush;
                }
                else if (i == 12 && j == 19) {
                    cout << bush;
                }
                else if (i == 12 && j == 20) {
                    cout << bush;
                }
                else if (i == 15 && j == 35) {
                    cout << rock;
                }
                else if (i == 15 && j == 36) {
                    cout << rock;
                }
                else if (i == 15 && j == 37) {
                    cout << rock;
                }
                else if (i == 15 && j == 38) {
                    cout << rock;
                }
                else if (i == 15 && j == 39) {
                    cout << rock;
                }
                else if (i == 14 && j == 39) {
                    cout << rock;
                }
                else if (i == 2 && j == 33) {
                    cout << rock;
                }
                else if (i == 2 && j == 32) {
                    cout << rock;
                }
                else if (i == 2 && j == 31) {
                    cout << rock;
                }
                else if (i == 2 && j == 30) {
                    cout << rock;
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
    /*
    room[8][4] = holegl;
    room[9][4] = holesr1;
    room[10][4] = holesr1;
    room[11][4] = holesr1;
    room[12][4] = holesr1;
    room[13][4] = holesr1;
    room[14][4] = holesr1;
    room[15][4] = holesr1;
    room[16][4] = holesr1;
    room[17][4] = holesr1;
    room[18][4] = holesr1;
    room[19][4] = holesr1;
    room[20][4] = holesr1;
    room[21][4] = holesr1;
    room[22][4] = holesr1;
    room[23][4] = holesr1;
    room[24][4] = holesr1;
    room[25][4] = holesr1;
    room[26][4] = holesr1;
    room[27][4] = holesr1;
    room[28][4] = holesr1;
    room[29][4] = holesr1;
    room[30][4] = holesr1;
    room[31][4] = holesr1;
    room[9][11] = holesr1;
    room[10][11] = holesr1;
    room[11][11] = holesr1;
    room[12][11] = holesr1;
    room[13][11] = holesr1;
    room[14][11] = holesr1;
    room[15][11] = holesr1;
    room[16][11] = holesr1;
    room[17][11] = holesr1;
    room[18][11] = holesr1;
    room[19][11] = holesr1;
    room[20][11] = holesr1;
    room[21][11] = holesr1;
    room[22][11] = holesr1;
    room[23][11] = holesr1;
    room[24][11] = holesr1;
    room[25][11] = holesr1;
    room[26][11] = holesr1;
    room[27][11] = holesr1;
    room[28][11] = holesr1;
    room[29][11] = holesr1;
    room[30][11] = holesr1;
    room[31][11] = holesr1;
    room[32][4] = holegd;
    room[32][5] = holesr2;
    room[32][6] = holesr2;
    room[32][7] = holesr2;
    room[32][8] = holesr2;
    room[32][9] = holesr2;
    room[32][6] = holesr2;
    room[32][10] = holesr2;
    room[8][5] = holesr2;
    room[8][6] = holesr2;
    room[8][7] = holesr2;
    room[8][8] = holesr2;
    room[8][9] = holesr2;
    room[8][10] = holesr2;
    room[8][11] = holedl;
    room[32][11] = holedd;

    room[1][2] = bush;
    room[1][1] = bush;
    room[2][1] = bush;
    room[35][5] = bush;
    room[35][6] = bush;
    room[1][15] = bush;
    room[2][15] = bush;
    room[3][15] = bush;
    room[4][15] = bush;
    room[1][14] = bush;
    room[18][12] = bush;
    room[19][12] = bush;
    room[20][12] = bush;

    room[35][15] = rock;
    room[36][15] = rock;
    room[37][15] = rock;
    room[38][15] = rock;
    room[39][15] = rock;
    room[39][14] = rock;
    room[33][2] = rock;
    room[32][2] = rock;
    room[31][2] = rock;
    room[30][2] = rock;
    */


    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;


    for (int i = 0; i < rowRoom; i++) {
        for (int j = 0; j < colRoom; j++) {
            if (i > 0 && j > 0 && i < rowRoom - 1 && j < colRoom - 1)
            {
                if (i == 3 && j == 5) {
                    cout << holegl;
                }
                else if (i == 3 && j == 6) {
                    cout << holesr1;
                }
                else if (i == 3 && j == 7) {
                    cout << holesr1;
                }
                else if (i == 3 && j == 8) {
                    cout << holesr1;
                }
                else if (i == 6 && j == 6) {
                    cout << holesr1;
                }
                else if (i == 6 && j == 7) {
                    cout << holesr1;
                }
                else if (i == 6 && j == 8) {
                    cout << holesr1;
                }
                else if (i == 3 && j == 9) {
                    cout << holegd;
                }
                else if (i == 4 && j == 5) {
                    cout << holesr2;
                }
                else if (i == 5 && j == 5) {
                    cout << holesr2;
                }
                else if (i == 4 && j == 9) {
                    cout << holesr2;
                }
                else if (i == 5 && j == 9) {
                    cout << holesr2;
                }
                else if (i == 6 && j == 5) {
                    cout << holedl;
                }
                else if (i == 6 && j == 9) {
                    cout << holedd;
                }
                else if (i == 11 && j == 25) {
                    cout << holegl;
                }
                else if (i == 11 && j == 26) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 27) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 28) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 29) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 30) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 31) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 32) {
                    cout << holesr1;
                }
                else if (i == 13 && j == 26) {
                    cout << holesr1;
                }
                else if (i == 13 && j == 27) {
                    cout << holesr1;
                }
                else if (i == 13 && j == 28) {
                    cout << holesr1;
                }
                else if (i == 13 && j == 29) {
                    cout << holesr1;
                }
                else if (i == 13 && j == 30) {
                    cout << holesr1;
                }
                else if (i == 13 && j == 31) {
                    cout << holesr1;
                }
                else if (i == 13 && j == 32) {
                    cout << holesr1;
                }
                else if (i == 11 && j == 33) {
                    cout << holegd;
                }
                else if (i == 12 && j == 25) {
                    cout << holesr2;
                }
                else if (i == 12 && j == 33) {
                    cout << holesr2;
                }
                else if (i == 13 && j == 25) {
                    cout << holedl;
                }
                else if (i == 13 && j == 33) {
                    cout << holedd;
                }
                else if (i == 8 && j == 17) {
                    cout << bush;
                }
                else if (i == 8 && j == 18) {
                    cout << bush;
                }
                else if (i == 8 && j == 19) {
                    cout << bush;
                }
                else if (i == 9 && j == 19) {
                    cout << bush;
                }
                else if (i == 4 && j == 29) {
                    cout << bush;
                }
                else if (i == 4 && j == 30) {
                    cout << bush;
                }
                else if (i == 12 && j == 4) {
                    cout << rock;
                }
                else if (i == 12 && j == 5) {
                    cout << rock;
                }
                else if (i == 13 && j == 4) {
                    cout << rock;
                }
                else if (i == 13 && j == 5) {
                    cout << rock;
                }
                else if (i == 14 && j == 4) {
                    cout << rock;
                }
                else if (i == 3 && j == 28) {
                    cout << rock;
                }
                else if (i == 3 && j == 29) {
                    cout << rock;
                }
                else if (i == 3 && j == 30) {
                    cout << rock;
                }
                else if (i == 3 && j == 31) {
                    cout << rock;
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
    /*	room[5][3] = holegl;
        room[6][3] = holesr1;
        room[7][3] = holesr1;
        room[8][3] = holesr1;
        room[6][6] = holesr1;
        room[7][6] = holesr1;
        room[8][6] = holesr1;
        room[9][3] = holegd;
        room[5][4] = holesr2;
        room[5][5] = holesr2;
        room[9][4] = holesr2;
        room[9][5] = holesr2;
        room[5][6] = holedl;
        room[9][6] = holedd;

        room[25][11] = holegl;
        room[26][11] = holesr1;
        room[27][11] = holesr1;
        room[28][11] = holesr1;
        room[29][11] = holesr1;
        room[30][11] = holesr1;
        room[31][11] = holesr1;
        room[32][11] = holesr1;
        room[26][13] = holesr1;
        room[27][13] = holesr1;
        room[28][13] = holesr1;
        room[29][13] = holesr1;
        room[30][13] = holesr1;
        room[31][13] = holesr1;
        room[32][13] = holesr1;
        room[33][11] = holegd;
        room[25][12] = holesr2;
        room[33][12] = holesr2;
        room[25][13] = holedl;
        room[33][13] = holedd;

        room[17][8] = bush;
        room[18][8] = bush;
        room[19][8] = bush;
        room[19][9] = bush;
        room[29][4] = bush;
        room[30][4] = bush;

        room[4][12] = rock;
        room[5][12] = rock;
        room[4][13] = rock;
        room[5][13] = rock;
        room[4][14] = rock;
        room[28][3] = rock;
        room[29][3] = rock;
        room[30][3] = rock;
        room[31][3] = rock;
    */
}