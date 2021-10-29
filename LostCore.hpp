#include "Level.hpp"



void LostInit(){

    InitWindow(500 , 500 , "LostEngine");
    SetTargetFPS(60);
    InitAudioDevice();

    LostEngine.LevelConfig = LoadFile("GameData/Levels/LevelConfig.leconf");
    LostEngine.Running = true;
    LostEngine.WindowScale = 1.0f;
    LostEngine.AnimationTicker = 0;
    LostPlayer.DrawingEnabled = true;
    LostPlayer.X = 200;
    LostPlayer.Y = 200;
    LostPlayer.Height = 100;
    LostPlayer.Width = 800;
    LostPlayer.Direction = 3;
    LostPlayer.Moving = false;

    LostPlayer.FacingFrame1 = LoadTexture("GameData/Assets/Player/Front/Frame1.png");
    LostPlayer.FacingFrame2 = LoadTexture("GameData/Assets/Player/Front/Frame2.png");
    LostPlayer.FacingFrame3 = LoadTexture("GameData/Assets/Player/Front/Frame3.png");

    LostPlayer.BackFrame1 = LoadTexture("GameData/Assets/Player/Back/Frame1.png");
    LostPlayer.BackFrame2 = LoadTexture("GameData/Assets/Player/Back/Frame2.png");
    LostPlayer.BackFrame3 = LoadTexture("GameData/Assets/Player/Back/Frame3.png");

    LostPlayer.RightFrame1 = LoadTexture("GameData/Assets/Player/Right/Frame1.png");
    LostPlayer.RightFrame2 = LoadTexture("GameData/Assets/Player/Right/Frame2.png");
    LostPlayer.RightFrame3 = LoadTexture("GameData/Assets/Player/Right/Frame3.png");

    LostPlayer.LeftFrame1 = LoadTexture("GameData/Assets/Player/Left/Frame1.png");
    LostPlayer.LeftFrame2 = LoadTexture("GameData/Assets/Player/Left/Frame2.png");
    LostPlayer.LeftFrame3 = LoadTexture("GameData/Assets/Player/Left/Frame3.png");

    LostEngine.ChatBox = LoadTexture("GameData/Assets/Etc/ChatBox.png");
    LostEngine.ChatBoxArrow = LoadTexture("GameData/Assets/Etc/ChatBoxArrow.png");
    LostEngine.PlayerVoice = LoadMusicStream("GameData/Assets/Etc/Voices/Player/Voice.mp3");
    LostEngine.VoiceTrigger = false;

    LoadLevel(0);

}

void LostMainLoop(){
    BeginDrawing();
    ClearBackground(BLACK);
    UpdateMusicStream(LostMap.LevelMusic);
    DrawLevel();
    DrawPlayer();
    UpdateEditor();

    if (WindowShouldClose()){LostEngine.Running = false;}

    if (LostEngine.AnimationTicker <= 99){LostEngine.AnimationTicker += 4;}
    else {LostEngine.AnimationTicker = 0;}

    if (IsKeyPressed(KEY_F2)){LostEngine.WindowScale += .5f;SetWindowSize(500 * LostEngine.WindowScale, 500 * LostEngine.WindowScale); }
    if (IsKeyPressed(KEY_F1)){LostEngine.WindowScale -= .5f;SetWindowSize(500 * LostEngine.WindowScale, 500 * LostEngine.WindowScale); }
    if (IsKeyPressed(KEY_F11)){
        ToggleFullscreen();
    }
    if (IsKeyPressed(KEY_D)){if (!LostEngine.Debug)LostEngine.Debug = true;else {LostEngine.Debug = false;}}

    EndDrawing();
}

void LostClose(){
    CloseWindow();
}