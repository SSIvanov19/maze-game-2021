#include <iostream>
using namespace std;
int main() {
        
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
        char wizard = 30;
        char money = 36;
        char firstMonster = 253;
        char secondMonster = 248;
        char fPartThirdMonster = 203;
        char sPartThirdMonster = 176;
        char fPartFourthMonster = 209;
        char sPartFourthMonster = 177;
        char bossFPart = 206;
        char bossSPart = 178;
        char bossTPart = 201;
        char bossFoPart = 184;

        cout << money << " = Money = 36 (ASCII number)" << endl;
        cout << uSword << " = up part sword = 179 (ASCII number)" << endl;
        cout << dSword << " = down part sword = 216 (ASCII number)" << endl;
        cout << key << " = Key = 12 (ASCII number)" << endl;
        cout << health << " = Health = 3 (ASCII number)" << endl;
        cout << firstMonster << " = First monster = 253 (ASCII number)" << endl;
        cout << secondMonster << " = Second monster = 248 (ASCII number)" << endl;
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
}