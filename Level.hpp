#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

#include "Player.hpp"

using namespace std;

static int R = 255;
static int G = 255;
static int B = 255;

#define FadeWhite  CLITERAL(Color){R,G,B, 255 }



typedef struct MapData{
    int Height;
    int Width;
    wstring Data;
    wstring TransitionConfig;
    char LevelName[100];
    int TransitionId1;
    int TransitionId2;
    int TransitionId3;
    int TransitionId4;
    wchar_t TransitionTile;
    Music LevelMusic;

    Texture2D Background;
    Texture2D Object1;
    Texture2D Object2;
    Texture2D Object3;
    Texture2D Object4;
    Texture2D Object5;
    Texture2D Object6;
    Texture2D Object7;
    Texture2D Object8;
    Texture2D Object9;

    wstring ChatBubbleData1;
    wstring ChatBubbleData2;
    wstring ChatBubbleData3;
    wstring ChatBubbleData4;
    wstring ChatBubbleData5;
    wstring ChatBubbleData6;

    bool ChatBubbleTriggerId;

    int ChatBubbleCounter; 

    int ChatBubbleCounterNext; 

    int TextEffectCounter;



}MapData;

static MapData LostMap;

typedef struct CoreData{
    bool Running;
    wstring LevelConfig;
    float WindowScale;
    int AnimationTicker;
    bool Debug;
    Texture2D ChatBox;
    Texture2D ChatBoxArrow;
    Music PlayerVoice;
    bool VoiceTrigger;
    int FadeValue;
    int FadeMode;

}CoreData;

static CoreData LostEngine;

typedef struct EditorData{
    wchar_t SelectedTile;
}EditorData;

static EditorData LostEditor;

wstring LoadFile(const char *Path){
    wstring Data;
    wifstream OutFile;
    OutFile.open(Path);
    OutFile >> Data;
    return Data;
}

static void UpdateFade(){

    if (LostEngine.FadeMode == 2){
        LostEngine.FadeValue += 5;
        R = LostEngine.FadeValue;
        G = LostEngine.FadeValue;
        B = LostEngine.FadeValue;
        if (LostEngine.FadeValue == 255){
            LostEngine.FadeMode = 0;
        }
    }
    
}

wstring WriteFile(const char *Path , wstring Data){
    wofstream outfile;
    outfile.open(Path);
    outfile << Data ;
}

auto ReadTile(int X , int Y){
    return LostMap.Data[Y * LostMap.Width + X];
}

auto WriteTile(int X , int Y , wchar_t Tile){
    LostMap.Data[Y * LostMap.Width + X] = Tile;
}

auto WchartToChar(wchar_t Character){
    switch (Character){
        case L'A':
            return "A";
            break;
        case L'B':
            return "B";
            break;
        case L'C':
            return "C";
            break;
        case L'D':
            return "D";
            break;
        case L'E':
            return "E";
            break;
        case L'F':
            return "F";
            break;
        case L'G':
            return "G";
            break;
        case L'H':
            return "H";
            break;
        case L'I':
            return "I";
            break;
        case L'J':
            return "J";
            break;
        case L'K':
            return "K";
            break;
        case L'L':
            return "L";
            break;
        case L'M':
            return "M";
            break;
        case L'N':
            return "N";
            break;
        case L'O':
            return "O";
            break;
        case L'P':
            return "P";
            break;
        case L'Q':
            return "Q";
            break;
        case L'R':
            return "R";
            break;
        case L'S':
            return "S";
            break;
        case L'T':
            return "T";
            break;
        case L'U':
            return "U";
            break;
        case L'V':
            return "V";
            break;
        case L'W':
            return "W";
            break;
        case L'X':
            return "X";
            break;
        case L'Y':
            return "Y";
            break;
        case L'Z':
            return "Z";
            break;

        case L'0':
            return "0";
            break;
        case L'1':
            return "1";
            break;
        case L'2':
            return "2";
            break;
        case L'3':
            return "3";
            break;
        case L'4':
            return "4";
            break;
        case L'5':
            return "5";
            break;
        case L'6':
            return "6";
            break;
        case L'7':
            return "7";
            break;
        case L'8':
            return "8";
            break;
        case L'9':
            return "9";
            break;

        case L'a':
            return "a";
            break;
        case L'b':
            return "b";
            break;
        case L'c':
            return "c";
            break;
        case L'd':
            return "d";
            break;
        case L'e':
            return "e";
            break;
        case L'f':
            return "f";
            break;
        case L'g':
            return "g";
            break;
        case L'h':
            return "h";
            break;
        case L'i':
            return "i";
            break;
        case L'j':
            return "j";
            break;
        case L'k':
            return "k";
            break;
        case L'l':
            return "l";
            break;
        case L'm':
            return "m";
            break;
        case L'n':
            return "n";
            break;
        case L'o':
            return "o";
            break;
        case L'p':
            return "p";
            break;
        case L'q':
            return "q";
            break;
        case L'r':
            return "r";
            break;
        case L's':
            return "s";
            break;
        case L't':
            return "t";
            break;
        case L'u':
            return "u";
            break;
        case L'v':
            return "v";
            break;
        case L'w':
            return "w";
            break;
        case L'x':
            return "x";
            break;
        case L'y':
            return "y";
            break;
        case L'z':
            return "z";
            break;
            
        case L'!':
            return "!";
            break;
        case L'$':
            return "$";
            break;
        case L'?':
            return "?";
            break;
        case L'(':
            return "(";
            break;
        case L')':
            return ")";
            break;
        case L'{':
            return "{";
            break;
        case L'}':
            return "}";
            break;
        case L'&':
            return "&";
            break;
        case L'.':
            return ".";
            break;
        case L',':
            return ",";
            break;
        case L';':
            return ";";
            break;
        case L':':
            return ":";
            break;

        default:
            return " ";
            break;
    }
}

auto WchartToInt(wchar_t Character){
    switch (Character){
        case L'0':
            return 0;
            break;
        case L'1':
            return 1;
            break;
        case L'2':
            return 2;
            break;
        case L'3':
            return 3;
            break;
        case L'4':
            return 4;
            break;
        case L'5':
            return 5;
            break;
        case L'6':
            return 6;
            break;
        case L'7':
            return 7;
            break;
        case L'8':
            return 8;
            break;
        case L'9':
            return 9;
            break;
    }
}
void LoadLevel(int Id){
    LostEngine.FadeValue = 0;
    LostEngine.FadeMode = 2;
    char LevelName[100];

    LevelName[0] = '\0';

    int Counter = 0;

    for (int i = Id*7 ; i <= LostEngine.LevelConfig.size() ; i ++){
        if (LostEngine.LevelConfig[i] == L'|'){
            strcat(LevelName , WchartToChar(LostEngine.LevelConfig[i+1]));
            strcat(LevelName , WchartToChar(LostEngine.LevelConfig[i+2]));
            strcat(LevelName , WchartToChar(LostEngine.LevelConfig[i+3]));
            strcat(LevelName , WchartToChar(LostEngine.LevelConfig[i+4]));
            strcat(LevelName , WchartToChar(LostEngine.LevelConfig[i+5]));
            strcat(LevelName , WchartToChar(LostEngine.LevelConfig[i+6]));
            cout << LevelName << "\n";
            i = LostEngine.LevelConfig.size();
        }

    }
    LostMap.Data = LoadFile(FormatText("GameData/Levels/%s/LevelData.lpak" ,LevelName));
    LostMap.Background = LoadTexture(FormatText("GameData/Levels/%s/Background/Background.png" , LevelName));
    LostMap.Height = 500 / 20;
    LostMap.Width = LostMap.Height;

    LostMap.Object1 = LoadTexture(FormatText("GameData/Levels/%s/Objects/Object1.png" ,LevelName));
    LostMap.Object2 = LoadTexture(FormatText("GameData/Levels/%s/Objects/Object2.png" ,LevelName));
    LostMap.Object3 = LoadTexture(FormatText("GameData/Levels/%s/Objects/Object3.png" ,LevelName));
    LostMap.Object4 = LoadTexture(FormatText("GameData/Levels/%s/Objects/Object4.png" ,LevelName));
    LostMap.Object5 = LoadTexture(FormatText("GameData/Levels/%s/Objects/Object5.png" ,LevelName));
    LostMap.Object6 = LoadTexture(FormatText("GameData/Levels/%s/Objects/Object6.png" ,LevelName));
    LostMap.Object7 = LoadTexture(FormatText("GameData/Levels/%s/Objects/Object7.png" ,LevelName));
    LostMap.Object8 = LoadTexture(FormatText("GameData/Levels/%s/Objects/Object8.png" ,LevelName));
    LostMap.Object9 = LoadTexture(FormatText("GameData/Levels/%s/Objects/Object9.png" ,LevelName));
    StopMusicStream(LostMap.LevelMusic);
    LostMap.LevelMusic = LoadMusicStream(FormatText("GameData/Levels/%s/Music/Music.mp3" ,LevelName));
    PlayMusicStream(LostMap.LevelMusic);
    LostMap.Data = LoadFile(FormatText("GameData/Levels/%s/LevelData.lpak" ,LevelName));

    LostMap.TransitionConfig = LoadFile(FormatText("GameData/Levels/%s/TransitionConfig.leconf" ,LevelName));

    LostMap.TransitionId1 = 0;
    LostMap.TransitionId2 = 0;
    LostMap.TransitionId3 = 0;
    LostMap.TransitionId4 = 0;

    int Store = false;
    int IdCounter = 1;

    LostMap.TransitionId1 += WchartToInt(LostMap.TransitionConfig[1])*100;
    LostMap.TransitionId1 += WchartToInt(LostMap.TransitionConfig[2])*10;
    LostMap.TransitionId1 += WchartToInt(LostMap.TransitionConfig[3])*1;

    LostMap.TransitionId2 += WchartToInt(LostMap.TransitionConfig[5])*100;
    LostMap.TransitionId2 += WchartToInt(LostMap.TransitionConfig[6])*10;
    LostMap.TransitionId2 += WchartToInt(LostMap.TransitionConfig[7])*1;

    LostMap.TransitionId3 += WchartToInt(LostMap.TransitionConfig[9])*100;
    LostMap.TransitionId3 += WchartToInt(LostMap.TransitionConfig[10])*10;
    LostMap.TransitionId3 += WchartToInt(LostMap.TransitionConfig[11])*1;

    LostMap.TransitionId4 += WchartToInt(LostMap.TransitionConfig[13])*100;
    LostMap.TransitionId4 += WchartToInt(LostMap.TransitionConfig[14])*10;
    LostMap.TransitionId4 += WchartToInt(LostMap.TransitionConfig[15])*1;

    cout << "Level Name: " << LevelName << "\n";

    cout << "Transition ID 1: " << LostMap.TransitionId1 << "\n";
    cout << "Transition ID 2: " << LostMap.TransitionId2 << "\n";
    cout << "Transition ID 3: " << LostMap.TransitionId3 << "\n";
    cout << "Transition ID 4: " << LostMap.TransitionId4 << "\n";
    LostMap.LevelName[0] = '\0';
    strcat(LostMap.LevelName , LevelName);
    LostMap.ChatBubbleData1[0] = L'\0';
    LostMap.ChatBubbleData2[0] = L'\0';
    LostMap.ChatBubbleData1 = LoadFile(FormatText("GameData/Levels/%s/Text/CB1.lcb" ,LevelName));
    LostMap.ChatBubbleData2 = LoadFile(FormatText("GameData/Levels/%s/Text/CB1.lcb" ,LevelName));

}

static void DrawLevel(){
    DrawTextureEx(LostMap.Background , {0,0} , 0, LostEngine.WindowScale, FadeWhite);
    for (int x = 0 ; x <= LostMap.Width ; x++){
        for (int y = 0 ; y <= LostMap.Height ; y++){
            switch (LostMap.Data[y*(LostMap.Width)+x]){
                case L'Z':
                    if (LostEngine.Debug)DrawRectangleLines(x * LostEngine.WindowScale* 20  , y* LostEngine.WindowScale*20 , 20* LostEngine.WindowScale , 20* LostEngine.WindowScale , RED);
                    break;
               case L'%':
                    if (LostEngine.Debug)DrawRectangleLines(x * LostEngine.WindowScale* 20  , y* LostEngine.WindowScale*20 , 20* LostEngine.WindowScale , 20* LostEngine.WindowScale , YELLOW);
                    break;
               case L'^':
                    if (LostEngine.Debug)DrawRectangleLines(x * LostEngine.WindowScale* 20  , y* LostEngine.WindowScale*20 , 20* LostEngine.WindowScale , 20* LostEngine.WindowScale , PURPLE);
                    break;
               case L'&':
                    if (LostEngine.Debug)DrawRectangleLines(x * LostEngine.WindowScale* 20  , y* LostEngine.WindowScale*20 , 20* LostEngine.WindowScale , 20* LostEngine.WindowScale , GREEN);
                    break;
               case L'*':
                    if (LostEngine.Debug)DrawRectangleLines(x * LostEngine.WindowScale* 20  , y* LostEngine.WindowScale*20 , 20* LostEngine.WindowScale , 20* LostEngine.WindowScale , PINK);
                    break;
                case L'0':
                    break;
                case L'1':
                    DrawTextureEx(LostMap.Object1 , {(x*20)*LostEngine.WindowScale,(y*20)*LostEngine.WindowScale} , 0, LostEngine.WindowScale, FadeWhite);
                    break;
                case L'2':
                    DrawTextureEx(LostMap.Object2 , {(x*20)*LostEngine.WindowScale,(y*20)*LostEngine.WindowScale} , 0, LostEngine.WindowScale, FadeWhite);
                    break;
                case L'3':
                    DrawTextureEx(LostMap.Object3 , {(x*20)*LostEngine.WindowScale,(y*20)*LostEngine.WindowScale} , 0, LostEngine.WindowScale, FadeWhite);
                    break;
                case L'4':
                    DrawTextureEx(LostMap.Object4 , {(x*20)*LostEngine.WindowScale,(y*20)*LostEngine.WindowScale} , 0, LostEngine.WindowScale, FadeWhite);
                    break;
                case L'5':
                    DrawTextureEx(LostMap.Object5 , {(x*20)*LostEngine.WindowScale,(y*20)*LostEngine.WindowScale} , 0, LostEngine.WindowScale, FadeWhite);
                    break;
                case L'6':
                    DrawTextureEx(LostMap.Object6 , {(x*20)*LostEngine.WindowScale,(y*20)*LostEngine.WindowScale} , 0, LostEngine.WindowScale, FadeWhite);
                    break;   
                case L'7':
                    DrawTextureEx(LostMap.Object7 , {(x*20)*LostEngine.WindowScale,(y*20)*LostEngine.WindowScale} , 0, LostEngine.WindowScale, FadeWhite);
                    break;
                case L'8':
                    DrawTextureEx(LostMap.Object8 , {(x*20)*LostEngine.WindowScale,(y*20)*LostEngine.WindowScale} , 0, LostEngine.WindowScale, FadeWhite);
                    break;
                case L'9':
                    DrawTextureEx(LostMap.Object9 , {(x*20)*LostEngine.WindowScale,(y*20)*LostEngine.WindowScale} , 0, LostEngine.WindowScale, FadeWhite);
                    break;
                default:
                    if (LostEngine.Debug)DrawRectangle(x * LostEngine.WindowScale* 20  , y* LostEngine.WindowScale*20 , 20* LostEngine.WindowScale , 20* LostEngine.WindowScale , PURPLE);
                    if (LostEngine.Debug)DrawRectangleLines(x * LostEngine.WindowScale* 20  , y* LostEngine.WindowScale*20 , 20* LostEngine.WindowScale , 20* LostEngine.WindowScale , WHITE);
                    break;
            }
        }
    }
}

void DrawPlayer(){
    UpdateFade();

    if (LostMap.ChatBubbleTriggerId == 0){
        LostPlayer.OldX = LostPlayer.X;
        LostPlayer.OldY = LostPlayer.Y;
        if (IsKeyDown(KEY_UP) && !IsKeyDown(KEY_DOWN) && !IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT)){
            LostPlayer.Y -= 4 ; 
            LostPlayer.Direction = 1;
            LostMap.TransitionTile = L'%';
        }
        if (IsKeyDown(KEY_DOWN) && !IsKeyDown(KEY_UP) && !IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT)){
            LostPlayer.Y += 4 ; 
            LostPlayer.Direction = 3;
            LostMap.TransitionTile = L'&';
        }
        if (IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_DOWN) && !IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_UP)){
            LostPlayer.X += 4 ; 
            LostPlayer.Direction = 2;
            LostMap.TransitionTile = L'^';
        }
        if (IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_DOWN) && !IsKeyDown(KEY_UP) && !IsKeyDown(KEY_RIGHT)){
            LostPlayer.X -= 4 ; 
            LostPlayer.Direction = 4;
            LostMap.TransitionTile = L'*';
        }

        if (!IsKeyDown(KEY_UP) && !IsKeyDown(KEY_DOWN) && !IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT)){
            LostPlayer.Moving = false;
        }
        else {
            LostPlayer.Moving = true;
        }
    
 
        for (int x = 0 ; x <= 3; x++){
            for (int y = 0 ; y <= 2; y++){
                switch(ReadTile((LostPlayer.X + x * 20) / 20, (LostPlayer.Y + y * 20) / 20)){
                    case L'~':
                        LostMap.ChatBubbleTriggerId = 1;
                        LostMap.ChatBubbleCounter = 0;
                        for (int i = 0 ; i <= LostMap.ChatBubbleData1.size() ; i ++){
                            if (LostMap.ChatBubbleData1[i] == L'|'){
                                LostMap.ChatBubbleCounterNext = i;
                                break;
                            }
                        }
                        LostPlayer.Moving = false;
                        LostMap.TextEffectCounter = LostMap.ChatBubbleData1.size();
                        LostPlayer.X = LostPlayer.OldX;
                        LostPlayer.Y = LostPlayer.OldY;
                        break;
                    case L'`':
                        LostMap.ChatBubbleTriggerId = 2;
                        LostPlayer.Moving = false;
                        LostMap.TextEffectCounter = LostMap.ChatBubbleData2.size();
                        break;
                }
            }
        }

        for (int i = 1 ; i <= 2; i++){
            if (ReadTile((LostPlayer.X + i * 20) / 20, LostPlayer.Y / 20) != L'0' && ReadTile((LostPlayer.X + i * 20) / 20, LostPlayer.Y / 20) != LostMap.TransitionTile){
                switch (LostPlayer.Direction){
                    case 1:
                        LostPlayer.Y += 4 * LostEngine.WindowScale;
                        break;
                }
            }
        }

        for (int i = 1 ; i <= 2; i++){
            if (ReadTile((LostPlayer.X + i * 20) / 20, (LostPlayer.Y + 110) / 20) != L'0' && ReadTile((LostPlayer.X + i * 20) / 20, (LostPlayer.Y + 110) / 20) != LostMap.TransitionTile){
                if (LostPlayer.Direction == 3){
                    LostPlayer.Y -= 4 * LostEngine.WindowScale;
                }
            }
        }

        for (int i = 1 ; i <= 3; i++){
            if (ReadTile((LostPlayer.X + 100) / 20, (LostPlayer.Y + i * 20) / 20) != L'0' && ReadTile((LostPlayer.X + 100) / 20, (LostPlayer.Y + i * 20) / 20) != LostMap.TransitionTile){
                if (LostPlayer.Direction == 2){
                    LostPlayer.X -= 4 * LostEngine.WindowScale;
                }
            }
        }

        for (int i = 1 ; i <= 3; i++){
            if (ReadTile((LostPlayer.X) / 20, (LostPlayer.Y + i * 20) / 20) != L'0' && ReadTile((LostPlayer.X) / 20, (LostPlayer.Y + i * 20) / 20) != LostMap.TransitionTile ){
                if (LostPlayer.Direction == 4){
                    LostPlayer.X += 4 * LostEngine.WindowScale;
                }
            }
        }

        if (LostPlayer.Direction == 2){
            if (ReadTile((LostPlayer.X + LostPlayer.Width) / 20, (LostPlayer.Y) / 20) == L'%'){
                LoadLevel(LostMap.TransitionId1);
                LostPlayer.Y = 459;
            }

            if (ReadTile((LostPlayer.X + LostPlayer.Width) / 20, (LostPlayer.Y) / 20) == L'^'){
                LoadLevel(LostMap.TransitionId2);
                LostPlayer.X = 60;
            }

            if (ReadTile((LostPlayer.X + LostPlayer.Width) / 20, (LostPlayer.Y) / 20) == L'&'){
                LoadLevel(LostMap.TransitionId3);
                LostPlayer.Y = 60;
            }

            if (ReadTile((LostPlayer.X + LostPlayer.Width) / 20, (LostPlayer.Y) / 20) == L'*'){
                LoadLevel(LostMap.TransitionId4);
                LostPlayer.X = 450;
            }
        }
        if (LostPlayer.Direction != 2 && LostPlayer.Direction != 3){

            if (ReadTile((LostPlayer.X) / 20, (LostPlayer.Y) / 20) == L'%'){
                LoadLevel(LostMap.TransitionId1);
                LostPlayer.Y = 459;
            }

            if (ReadTile((LostPlayer.X) / 20, (LostPlayer.Y) / 20) == L'^'){
                LoadLevel(LostMap.TransitionId2);
                LostPlayer.X = 60;
            }

            if (ReadTile((LostPlayer.X) / 20, (LostPlayer.Y) / 20) == L'&'){
                LoadLevel(LostMap.TransitionId3);
                LostPlayer.Y = 60;
            }

            if (ReadTile((LostPlayer.X) / 20, (LostPlayer.Y) / 20) == L'*'){
                LoadLevel(LostMap.TransitionId4);
                LostPlayer.X = 450;
            }
        }
        if (LostPlayer.Direction == 3){

            if (ReadTile((LostPlayer.X) / 20, (LostPlayer.Y + LostPlayer.Height) / 20) == L'%'){
                LoadLevel(LostMap.TransitionId1);
                LostPlayer.Y = 459;
            }

            if (ReadTile((LostPlayer.X) / 20, (LostPlayer.Y + LostPlayer.Height) / 20) == L'^'){
                LoadLevel(LostMap.TransitionId2);
                LostPlayer.X = 60;
            }

            if (ReadTile((LostPlayer.X) / 20, (LostPlayer.Y + LostPlayer.Height) / 20) == L'&'){
                LoadLevel(LostMap.TransitionId3);
                LostPlayer.Y = 60;
            }

            if (ReadTile((LostPlayer.X) / 20, (LostPlayer.Y + LostPlayer.Height) / 20) == L'*'){
                LoadLevel(LostMap.TransitionId4);
                LostPlayer.X = 450;
            }
        }
    }


    if (LostPlayer.DrawingEnabled){
        UpdateMusicStream(LostEngine.PlayerVoice);
        switch (LostPlayer.Direction){
            case 1:
                if (LostPlayer.Moving){ 
                    if (LostEngine.AnimationTicker >= 0 && LostEngine.AnimationTicker <= 33)DrawTextureEx(LostPlayer.BackFrame1, {LostPlayer.X * LostEngine.WindowScale, LostPlayer.Y * LostEngine.WindowScale} , 0 , LostEngine.WindowScale , FadeWhite);
                    if (LostEngine.AnimationTicker >= 33 && LostEngine.AnimationTicker <= 66)DrawTextureEx(LostPlayer.BackFrame2, {LostPlayer.X * LostEngine.WindowScale, LostPlayer.Y * LostEngine.WindowScale} , 0 , LostEngine.WindowScale , FadeWhite);
                    if (LostEngine.AnimationTicker >= 66 && LostEngine.AnimationTicker <= 100)DrawTextureEx(LostPlayer.BackFrame3, {LostPlayer.X * LostEngine.WindowScale, LostPlayer.Y * LostEngine.WindowScale} , 0 , LostEngine.WindowScale , FadeWhite);
                }
                else {
                    DrawTextureEx(LostPlayer.BackFrame1, {LostPlayer.X * LostEngine.WindowScale, LostPlayer.Y * LostEngine.WindowScale} , 0 , LostEngine.WindowScale , FadeWhite);
                }
                break;
            case 2:
                if (LostPlayer.Moving){ 
                    if (LostEngine.AnimationTicker >= 0 && LostEngine.AnimationTicker <= 33)DrawTextureEx(LostPlayer.RightFrame1, {LostPlayer.X * LostEngine.WindowScale, LostPlayer.Y * LostEngine.WindowScale} , 0 , LostEngine.WindowScale , FadeWhite);
                    if (LostEngine.AnimationTicker >= 33 && LostEngine.AnimationTicker <= 66)DrawTextureEx(LostPlayer.RightFrame2, {LostPlayer.X * LostEngine.WindowScale, LostPlayer.Y * LostEngine.WindowScale} , 0 , LostEngine.WindowScale , FadeWhite);
                    if (LostEngine.AnimationTicker >= 66 && LostEngine.AnimationTicker <= 100)DrawTextureEx(LostPlayer.RightFrame3, {LostPlayer.X * LostEngine.WindowScale, LostPlayer.Y * LostEngine.WindowScale} , 0 , LostEngine.WindowScale , FadeWhite);
                }
                else {
                    DrawTextureEx(LostPlayer.RightFrame1, {LostPlayer.X * LostEngine.WindowScale, LostPlayer.Y * LostEngine.WindowScale} , 0 , LostEngine.WindowScale ,FadeWhite);
                }
                break;
            case 3:
                if (LostPlayer.Moving){ 
                    if (LostEngine.AnimationTicker >= 0 && LostEngine.AnimationTicker <= 33)DrawTextureEx(LostPlayer.FacingFrame1, {LostPlayer.X * LostEngine.WindowScale, LostPlayer.Y * LostEngine.WindowScale} , 0 , LostEngine.WindowScale , FadeWhite);
                    if (LostEngine.AnimationTicker >= 33 && LostEngine.AnimationTicker <= 66)DrawTextureEx(LostPlayer.FacingFrame2, {LostPlayer.X * LostEngine.WindowScale, LostPlayer.Y * LostEngine.WindowScale} , 0 , LostEngine.WindowScale , FadeWhite);
                    if (LostEngine.AnimationTicker >= 66 && LostEngine.AnimationTicker <= 100)DrawTextureEx(LostPlayer.FacingFrame3, {LostPlayer.X * LostEngine.WindowScale, LostPlayer.Y * LostEngine.WindowScale} , 0 , LostEngine.WindowScale , FadeWhite);
                }
                else {
                    DrawTextureEx(LostPlayer.FacingFrame1, {LostPlayer.X * LostEngine.WindowScale, LostPlayer.Y * LostEngine.WindowScale} , 0 , LostEngine.WindowScale , FadeWhite);
                }
                break;
            case 4:
                if (LostPlayer.Moving){ 
                    if (LostEngine.AnimationTicker >= 0 && LostEngine.AnimationTicker <= 33)DrawTextureEx(LostPlayer.LeftFrame1, {LostPlayer.X * LostEngine.WindowScale, LostPlayer.Y * LostEngine.WindowScale} , 0 , LostEngine.WindowScale , FadeWhite);
                    if (LostEngine.AnimationTicker >= 33 && LostEngine.AnimationTicker <= 66)DrawTextureEx(LostPlayer.LeftFrame2, {LostPlayer.X * LostEngine.WindowScale, LostPlayer.Y * LostEngine.WindowScale} , 0 , LostEngine.WindowScale , FadeWhite);
                    if (LostEngine.AnimationTicker >= 66 && LostEngine.AnimationTicker <= 100)DrawTextureEx(LostPlayer.LeftFrame3, {LostPlayer.X * LostEngine.WindowScale, LostPlayer.Y * LostEngine.WindowScale} , 0 , LostEngine.WindowScale , FadeWhite);
                }
                else {
                    DrawTextureEx(LostPlayer.LeftFrame1, {LostPlayer.X * LostEngine.WindowScale, LostPlayer.Y * LostEngine.WindowScale} , 0 , LostEngine.WindowScale , FadeWhite);
                }
                break;
        }
        
    }
    if (LostMap.ChatBubbleTriggerId != 0){
        DrawTextureEx(LostEngine.ChatBox ,{0,400*LostEngine.WindowScale} ,0 ,LostEngine.WindowScale ,FadeWhite);
        if (LostEngine.AnimationTicker >= 50)DrawTextureEx(LostEngine.ChatBoxArrow ,{460*LostEngine.WindowScale,460*LostEngine.WindowScale} ,0 ,LostEngine.WindowScale ,FadeWhite);
        switch (LostMap.ChatBubbleTriggerId){
            case 1:
                for (int i = LostMap.ChatBubbleCounter ; i <= (LostMap.ChatBubbleCounterNext - LostMap.TextEffectCounter) ; i ++){
                    
                    DrawText(FormatText("%s",WchartToChar(LostMap.ChatBubbleData1[i])),((20 + i * 15) - LostMap.ChatBubbleCounter * 15) *LostEngine.WindowScale,420*LostEngine.WindowScale, 20 * LostEngine.WindowScale,BLACK );
                }
                break;

        }
        if (LostMap.TextEffectCounter !=0)
        {
            LostMap.TextEffectCounter--;
            if (LostMap.TextEffectCounter % 2 == 0){
                LostEngine.VoiceTrigger = true;
            }

            if (LostEngine.VoiceTrigger){
                PlayMusicStream(LostEngine.PlayerVoice);
                if (LostMap.TextEffectCounter % 5 == 0){
                    StopMusicStream(LostEngine.PlayerVoice);
                    LostEngine.VoiceTrigger = false;
                }
            }
        }
        else 
        {
            StopMusicStream(LostEngine.PlayerVoice);
        }

        if (IsKeyPressed(KEY_A)){
            switch (LostMap.ChatBubbleTriggerId){
                case 1:
                    for (int i = LostMap.ChatBubbleCounter + 1 ; i <= LostMap.ChatBubbleData1.size() ; i ++){
                        if (LostMap.ChatBubbleData1[i] == L'*'){
                            LostMap.ChatBubbleTriggerId = 0;
                            break;
                        }
                        if (LostMap.ChatBubbleData1[i] == L'|'){
                            
                            LostMap.ChatBubbleCounter = i;

                            for ( int z = LostMap.ChatBubbleCounter + 2; z <= LostMap.ChatBubbleData1.size() ; z++){
                                if (LostMap.ChatBubbleData1[z] == L'*'){
                                    LostMap.ChatBubbleTriggerId = 0;
                                    break;
                                }
                                if (LostMap.ChatBubbleData1[z] == L'|'){
                                    LostMap.ChatBubbleCounterNext = z;
                                    z = LostMap.ChatBubbleData1.size();
                                }
                            }

                            break;
                        }
                    }
                    break;
            }
        }
    }
}

void UpdateEditor(){
    if (LostEngine.Debug){
        if (IsKeyPressed(KEY_KP_0)){LostEditor.SelectedTile = L'0';}
        if (IsKeyPressed(KEY_KP_1)){LostEditor.SelectedTile = L'1';}
        if (IsKeyPressed(KEY_KP_2)){LostEditor.SelectedTile = L'2';}
        if (IsKeyPressed(KEY_KP_3)){LostEditor.SelectedTile = L'3';}
        if (IsKeyPressed(KEY_KP_4)){LostEditor.SelectedTile = L'4';}
        if (IsKeyPressed(KEY_KP_5)){LostEditor.SelectedTile = L'5';}
        if (IsKeyPressed(KEY_KP_6)){LostEditor.SelectedTile = L'6';}
        if (IsKeyPressed(KEY_KP_7)){LostEditor.SelectedTile = L'7';}
        if (IsKeyPressed(KEY_KP_8)){LostEditor.SelectedTile = L'8';}
        if (IsKeyPressed(KEY_KP_9)){LostEditor.SelectedTile = L'9';}

        if (IsKeyPressed(KEY_Z)){LostEditor.SelectedTile = L'Z';}

        if (IsKeyPressed(KEY_Q)){LostEditor.SelectedTile = L'%';}
        if (IsKeyPressed(KEY_W)){LostEditor.SelectedTile = L'^';}
        if (IsKeyPressed(KEY_E)){LostEditor.SelectedTile = L'&';}
        if (IsKeyPressed(KEY_R)){LostEditor.SelectedTile = L'*';}
        if (IsKeyPressed(KEY_L)){LostEditor.SelectedTile = L'`';}
        if (IsKeyPressed(KEY_K)){LostEditor.SelectedTile = L'~';}
        

        if (IsMouseButtonDown(0)){
            WriteTile((GetMouseX()/20) ,(GetMouseY()/20), LostEditor.SelectedTile);
        }

        if (IsKeyDown(KEY_S)){
            WriteFile(FormatText("GameData/Levels/%s/LevelData.lpak" ,LostMap.LevelName) , LostMap.Data);
        }
    }
}