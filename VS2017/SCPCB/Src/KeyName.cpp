#include "KeyName.h"
#include "include.h"

namespace CBN {

// Globals.
String KeyName[211];

// Functions.
void InitializeKeyName() {
    KeyName[1] = "Esc";
    int i;
    for (i = 2; i <= 10; i++) {
        KeyName[i] = Str(i-1);
    }
    KeyName[11] = "0";
    KeyName[12] = "-";
    KeyName[13] = "=";
    KeyName[14] = "Backspace";
    KeyName[15] = "TAB";
    KeyName[16] = "Q";
    KeyName[17] = "W";
    KeyName[18] = "E";
    KeyName[19] = "R";
    KeyName[20] = "T";
    KeyName[21] = "Y";
    KeyName[22] = "U";
    KeyName[23] = "I";
    KeyName[24] = "O";
    KeyName[25] = "P";
    KeyName[26] = "[";
    KeyName[27] = "]";
    KeyName[28] = "Enter";
    KeyName[29] = "bbLeft Ctrl";
    KeyName[30] = "A";
    KeyName[31] = "S";
    KeyName[32] = "D";
    KeyName[33] = "F";
    KeyName[34] = "G";
    KeyName[35] = "H";
    KeyName[36] = "J";
    KeyName[37] = "K";
    KeyName[38] = "L";
    KeyName[39] = ";";
    KeyName[40] = "'";
    KeyName[42] = "bbLeft Shift";
    KeyName[43] = "\\";
    KeyName[44] = "Z";
    KeyName[45] = "X";
    KeyName[46] = "C";
    KeyName[47] = "V";
    KeyName[48] = "B";
    KeyName[49] = "N";
    KeyName[50] = "M";
    KeyName[51] = ",";
    KeyName[52] = ".";
    KeyName[54] = "bbRight Shift";
    KeyName[56] = "bbLeft Alt";
    KeyName[57] = "Space";
    KeyName[58] = "Caps Lock";
    KeyName[59] = "F1";
    KeyName[60] = "F2";
    KeyName[61] = "F3";
    KeyName[62] = "F4";
    KeyName[63] = "F5";
    KeyName[64] = "F6";
    KeyName[65] = "F7";
    KeyName[66] = "F8";
    KeyName[67] = "F9";
    KeyName[68] = "F10";
    KeyName[157] = "bbRight Control";
    KeyName[184] = "bbRight Alt";
    KeyName[200] = "Up";
    KeyName[203] = "bbLeft";
    KeyName[205] = "bbRight";
    KeyName[208] = "Down";
}

}
