#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cmath>
#include <fstream>
using namespace std;

void mainmenu();             // display the tank picture
void tankwarfare();          // display the main header writen Tank Warfare
string options_2_InMenu_2(); // display options like "Keys", "Instructions"
string menu2();              // display the menu
string menu3();              // display the menu with "Resume Option"
void Getch();
void keys();         // display keys of game
void instructions(); // display instructions of game
void loading();      // display the loading
void loading2();     // overwrite the loading line
void loadingmark(); // gives the text of loading
void gamestart();    // Function which contains the whole functionalities of START THE GAME

string option;           // options in main menu
string option2;          // option 2 from main menu
string mainmenu_options; // variable used in main (while)
string menu_2_option;    // option 2 in menu

// maze
string maze[31][1];

//-------------------------------

char getCharAtxy(short int x, short int y);
void gotoxy(int x, int y);
void printplayer(int x, int y);        // print player on the screen
void clearplayer(int x, int y);        // erase player on the screen
void generatebullet();                 // Function to generate the player bullet at RIGHT
void generatebulletleft();             // Function to generate the player bullet at LEFT
void movePlayerbullet();               // Function to move the player bullet in RIGHT DIRECTION
void movePlayerbulletL();              // Function to move the player bullet in LEFT DIRECTION
void erasePlayerbullet(int x, int y);  // erase player bullet from the screen
void printPlayerbullet(int x, int y);  // print player bullet right on the screen
void printPlayerbulletL(int x, int y); // print player's bullets left on the screen

// Functions to control player movement
void movePlayerDown();
void movePlayerUp();
void movePlayerLeft();
void movePlayerRight();

void printScore();                     // print score on the screen
void EnemyBulletCollisionwithPlayer(); // Function to detect the enemy bullet collision with player
void gameOver();                       // Displays the GAME OVER Menu on the screen
void level_2();                        // Contains the functionalities of LEVEL 2
void level_3();                        // Contains the functionalities of LEVEL 3

// Functions of Functionalities of all enemies
void E1_functionalities(); // Thunder bolt 1
void E2_functionalities(); // Thunder bolt 2
void E5_functionalities(); // Thunder bolt 3
void E3_functionalities(); // Iron Fury 1
void E6_functionalities(); // Iron Fury 2
void E4_functionalities(); // Steel Jaguar (Commander)

void collisiondetection();
void refreshvalues();  // It refresh all the values and coordinates
void playermovement(); // It consists the funciton of player's up, down, right, left funcitons

// Enemy 1 / Thunder bolt 1
void printenemy_1_2_5(int x, int y);        // it prints enemy 1,2,5 on the screen in level 2
void eraseEnemy_1_2_5(int x, int y);        // it erase enemy 1,2,5 on the screen in level 2
void bulletCollisionwithEnemy1();           // it detects the bullet collision with enemy 1
void printEnemy1_Health();                  // Print enemy 1 health
void moveEnemy1();                          // It moves enemy 1 horizontally
void generateEnemyBullet1();                // It generates the bullets of enemy 1
void movebullet_enemy1();                   // It moves the bullet of enemy 1
void erasebullet_enemy_1_2_5(int x, int y); // It erase the bullets of enemy 1,2,5
void printbullet_enemy_1_2_5(int x, int y); // It prints the bullets of enemy 1,2,5

// Enemy 2 / Thunder bolt 2

void bulletCollisionwithEnemy2(); // it detects the bullet collision with enemy 1
void printEnemy2_Health();
void moveEnemy2();
void generateEnemyBullet2();
void movebullet_enemy2();

// Enemy 5 / Thunder bolt 3
void bulletCollisionwithEnemy5(); // it detects the bullet collision with enemy 1
void printEnemy5_Health();
void moveEnemy5();
void generateEnemyBullet5();
void movebullet_enemy5();

// Enemy 3 / Iron Fury 1
void printenemy_3_4_6(int x, int y);
void eraseEnemy_3_4_6(int x, int y);
void bulletCollisionwithEnemy3();      // it detects the bullet collision with enemy 3
void printEnemy3_Health();             // It prints enemy 3 health
void moveEnemy3();                     // It moves enemy 3 vertically
void generateEnemyBullet3();           // generate the bullets of enemy 3
void movebullet_enemy3();              // move the bullets of enemy 3
void erasebullet_enemy3(int x, int y); // erase the bullets of enemy 3
void printbullet_enemy3(int x, int y); // print the bullets off 3

// Enemy 6 / Iron Fury 2
void bulletCollisionwithEnemy6();      // it detects the bullet collision with enemy 6
void printEnemy6_Health();             // print enemy 6 health
void moveEnemy6();                     // move enemy 6 vertically
void generateEnemyBullet6();           // generate the bullet of enemy 6
void movebullet_enemy6();              // move bullet of enemy 6
void erasebullet_enemy6(int x, int y); // erase the bullets of enemy 6
void printbullet_enemy6(int x, int y); // print the bullets of enemy 6

// Enemy 4 / Steel Jaguar (commander)

void bulletCollisionwithEnemy4();      // it detects the bullet collision with enemy 4 from right
void bulletCollisionwithEnemy4Left();  // it detects the bullet collision with enemy 4 from left
void printEnemy4_Health();             // It prints the enemy 4 health
void chaseplayer();                    // Enemy 4 chase the player
void generateEnemyBullet4();           // generate the bullet of enemy 4
void movebullet_enemy4();              // move bullets of enemy 4
void erasebullet_enemy4(int x, int y); // erase bullets of enemy 4
void printbullet_enemy4(int x, int y); // print the bullets of enemy 4
void Won();

//  player tank / Steel Levithan
char line = 219;
char player[4][15] = {{'|', ' ', ' ', ' ', '/', line, line, line, line, line, ']', '=', '=', '=', '>'},
                      {' ', ' ', ' ', ' ', ' ', ' ', line, line, ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                      {' ', line, line, line, line, line, line, line, line, line, line, line, ']', ' ', ' '},
                      {' ', '\\', '_', '@', '_', '@', '_', '@', '_', '@', '_', '/', ' ', ' ', ' '}};

// enemy tank 1 & enemy tank 2 & enemy tank 5
char enemy_1[3][10] = {{'<', '=', '=', '=', '(', '~', '~', ')', '*', '*'},
                       {' ', ' ', ' ', '/', '_', '_', '_', '_', '_', '\\'},
                       {' ', ' ', ' ', '\\', '_', '@', '_', '@', '_', '/'}};
int enemy1_health = 100;
int enemy2_health = 100;
int enemy5_health = 100;

// enemy tank 3 & enemy tank 4 & enemy tank 6
char enemy_3[4][16] = {{' ', ' ', ' ', ' ', '<', '=', '=', '(', '8', '8', ')', '~', '~'},
                       {' ', '<', '=', '=', '=', '=', '=', '(', '$', '$', '$', '$', '$', ')', '*', '*'},
                       {' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', '_', '_', '_', '_', '_', '\\'},
                       {' ', ' ', ' ', ' ', ' ', ' ', '\\', '_', '@', '_', '@', '_', '@', '_', '/'}};
int enemy3_health = 100;
int enemy4_health = 100;
int enemy6_health = 100;

// player bullets right side
int bulletcount = 0;
int bulletX[1000];
int bulletY[1000];
bool isbulletactive[1000];

// player bullets left side
int bulletcountL = 0;
int bulletXL[1000];
int bulletYL[1000];
bool isbulletactiveL[1000];

void printmaze();
int score = 0;
int playerhealth = 100;

// enemy 1 bulets
int enemy1_bulletcount = 0;
int enemy1_bulletX[1000];
int enemy1_bulletY[1000];
bool enemy1_isbulletactive[1000];

// enemy 2 bulets
int enemy2_bulletcount = 0;
int enemy2_bulletX[1000];
int enemy2_bulletY[1000];
bool enemy2_isbulletactive[1000];

// enemy 5 bulets
int enemy5_bulletcount = 0;
int enemy5_bulletX[1000];
int enemy5_bulletY[1000];
bool enemy5_isbulletactive[1000];

// enemy 3 bullets
int enemy3_bulletcount = 0;
int enemy3_bulletX[1000];
int enemy3_bulletY[1000];
bool enemy3_isbulletactive[1000];

// enemy 6 bullets
int enemy6_bulletcount = 0;
int enemy6_bulletX[1000];
int enemy6_bulletY[1000];
bool enemy6_isbulletactive[1000];

// enemy 4 bullets
int enemy4_bulletcount = 0;
int enemy4_bulletX[1000];
int enemy4_bulletY[1000];
bool enemy4_isbulletactive[1000];

void printPlayerHealth();
int timer = 0;
string direction1 = "Up"; // use in enemy 3 to move up down
string direction6 = "Up"; // use int enemy 6 to move up down

// Use in enemy 1,2,5 to move left right
string direction_enemy1 = "left";
string direction_enemy2 = "left";
string direction_enemy5 = "left";

// File Hadling
void storecoordinates(); // store all the game coordinates
void readcordinates();   // read all the coordinates from file
void readbulletcount();  // it read right and left side bulletcount
void storebulletcount(); // it store right and left side bulletcount
void storemis();         // it stores all healths, score.
void readmis();          // It read all healths, score from file
void readmaze();         // It read maze from file and prints on screen

bool gamerun = true;

// Player coordinates
int px = 5;
int py = 10;

// Enemy 1/ Thunder bolt 1 coordinates
int Ex1 = 85;
int Ey1 = 5;

// Enemy 2 / Thunder bolt 2 coordinates
int Ex2 = 65;
int Ey2 = 15;

// Enemy 5 / Thunder bolt 3 coordinates
int Ex5 = 75;
int Ey5 = 25;

// Enemy 3 / Iron Fury 1 coordinates
int Ex3 = 110;
int Ey3 = 10;

// Enemy 6 Iron Fury 2 coordinates
int Ex6 = 110;
int Ey6 = 2;

// Enemy 4 / Steel Jaguar(commander) coordinates
float Ex4 = 110;
float Ey4 = 5;

int lives = 5;
main()
{
    readmaze();                     // print maze from file
    mainmenu();                     // print tank picture
    while (mainmenu_options != "4") // Exit
    {
        system("cls");
        readbulletcount(); // read bulletcount from file
        if (bulletcount > 0 || bulletcountL > 0)
        {
            mainmenu_options = menu3();
            if (mainmenu_options == "1")
            {
                readcordinates(); // read coordinates from file
                readmis();        // read health, score from file
                gamestart();      // Function to start the game
                Getch();
            }
            if (mainmenu_options == "2")
            {
                refreshvalues(); // Function to refresh all the values
                gamestart();     // Function to start the game
                Getch();
            }
            if (mainmenu_options == "3")
            {
                while (menu_2_option != "3")
                {
                    menu_2_option = options_2_InMenu_2();
                    if (menu_2_option == "1") // keys menu
                    {
                        keys(); // Show keys of the game
                    }
                    if (menu_2_option == "2") // instructions menu
                    {
                        instructions(); // show the instructions of games
                    }
                }
                Getch();
            }
        }
        else
        {

            mainmenu_options = menu2();
            if (mainmenu_options == "1") // gamestart
            {
                refreshvalues(); // function to refresh all the values
                gamestart();
                Getch();
            }
            if (mainmenu_options == "2") // options
            {
                while (menu_2_option != "3")
                {
                    menu_2_option = options_2_InMenu_2();
                    if (menu_2_option == "1") // keys menu
                    {
                        keys();
                    }
                    if (menu_2_option == "2") // instruction menu
                    {
                        instructions();
                    }
                    Getch();
                }
            }
            if (mainmenu_options == "3")
            {
                return 0;
            }
        }
    }
}
// ************** File Handling *****************

void storecoordinates() // store all the coordinates of game players and enemy's
{
    fstream file;
    file.open("coordinates.txt", ios::out);
    {
        file << px << endl;
        file << py << endl;

        file << Ex1 << endl;
        file << Ey1 << endl;

        file << Ex2 << endl;
        file << Ey2 << endl;

        file << Ex5 << endl;
        file << Ey5 << endl;

        file << Ex3 << endl;
        file << Ey3 << endl;

        file << Ex6 << endl;
        file << Ey6 << endl;

        file << Ex4 << endl;
        file << Ey4 << endl;
    }
    file.close();
}
void readcordinates() // read coordinates from file
{
    fstream file;
    file.open("coordinates.txt", ios::in);
    {
        file >> px;
        file >> py;

        file >> Ex1;
        file >> Ey1;

        file >> Ex2;
        file >> Ey2;

        file >> Ex5;
        file >> Ey5;

        file >> Ex3;
        file >> Ey3;

        file >> Ex6;
        file >> Ey6;

        file >> Ex4;
        file >> Ey4;
    }
    file.close();
}

void storebulletcount() // store left and right bullet count of player
{
    fstream file;
    file.open("bulletcount.txt", ios::out);
    {
        file << bulletcount << endl;
        file << bulletcountL;
    }
    file.close();
}

void readbulletcount() // read left and right bullet count of player
{
    fstream file;
    file.open("bulletcount.txt", ios::in);
    {
        file >> bulletcount;
        file >> bulletcountL;
        // bulletcount++;
    }
    file.close();
}

void storemis() // store health and score values in file
{
    fstream file;
    file.open("healths.txt", ios::out);
    {
        file << score << endl;
        file << lives << endl;
        file << playerhealth << endl;
        file << enemy1_health << endl;
        file << enemy2_health << endl;
        file << enemy5_health << endl;
        file << enemy3_health << endl;
        file << enemy6_health << endl;
        file << enemy4_health << endl;
    }
    file.close();
}

void readmis() // read health and score values from file
{
    fstream file;
    file.open("healths.txt", ios::in);
    {
        file >> score;
        file >> lives;
        file >> playerhealth;
        file >> enemy1_health;
        file >> enemy2_health;
        file >> enemy5_health;
        file >> enemy3_health;
        file >> enemy6_health;
        file >> enemy4_health;
    }
    file.close();
}

void readmaze() // read maze that is stored in file
{
    int lines = 0;
    fstream file;
    file.open("maze.txt", ios::in);
    while (!file.eof())
    {
        string line;
        getline(file, line);
        if (line == "")
            break;
        maze[lines][1] = line;
        lines++;
    }
    file.close();
}

// ********************* Menus ******************
string options_2_InMenu_2()
{
    system("cls");
    tankwarfare();
    cout << endl;
    cout << endl;
    cout << " 1.  Keys" << endl;
    cout << " 2.  Instructions" << endl;
    cout << " 3.  Back" << endl;
    cout << "-----------------------------" << endl;
    cin >> option2;
    return option2;
    Getch();
}

string menu2()
{
    system("cls");
    tankwarfare();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k = 10;
    SetConsoleTextAttribute(hConsole, k);
    cout << endl;
    cout << "---------------------------" << endl;
    cout << " 1.  Start" << endl;
    cout << " 2.  Option" << endl;
    cout << " 3.  Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Select your option..." << endl;
    cin >> option;
    return option;
}

string menu3()
{
    system("cls");
    tankwarfare();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k = 10;
    SetConsoleTextAttribute(hConsole, k);
    cout << endl;
    cout << "---------------------------" << endl;
    cout << " 1.  Resume" << endl;
    cout << " 2.  New Game" << endl;
    cout << " 3.  Option" << endl;
    cout << " 4.  Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Select your option..." << endl;
    cin >> option;
    return option;
}

void instructions()
{
    cout << "Instructions:" << endl;
    cout << "Kill all the enemys to win the battle" << endl;
    cout << "Steel Jaguar is the Commander of this game, be carefull from it" << endl;
}
void keys()
{
    cout << "Keys" << endl;
    cout << "--------------------------------------------" << endl;
    cout << " 1. Up               Go up" << endl;
    cout << " 2. Down             Go down" << endl;
    cout << " 3. Left             Go left" << endl;
    cout << " 4. Right            Go right" << endl;
    cout << " 5. Space            Right Fire" << endl;
    cout << " 6. Tab              Left Fire" << endl;
    Getch();
}

void Getch()
{
    cout << "Press any key to continue..." << endl;
    getch();
}

// *********************** Player Functionalities *************************

void refreshvalues() // functions to refresh all the values
{
    px = 5;
    py = 10;
    Ex1 = 85;
    Ey1 = 5;
    Ex2 = 65;
    Ey2 = 15;
    Ex5 = 75;
    Ey5 = 25;
    Ex3 = 110;
    Ey3 = 10;
    Ex6 = 110;
    Ey6 = 2;
    Ex4 = 110;
    Ey4 = 5;
    score = 0;
    playerhealth = 100;
    bulletcount = 0;
    bulletcountL = 0;
    lives = 5;
    enemy1_health = 100;
    enemy2_health = 100;
    enemy5_health = 100;
    enemy3_health = 100;
    enemy6_health = 100;
    enemy4_health = 100;
}

void gamestart() // Complete game functionalities
{
    system("cls");       // clear screen
    printmaze();         // print maze
    printplayer(px, py); // print player
    printenemy_1_2_5(Ex1, Ey1);
    printenemy_1_2_5(Ex2, Ey2);
    printenemy_1_2_5(Ex5, Ey5);
    printPlayerHealth();
    printEnemy1_Health();
    printEnemy2_Health();
    printEnemy5_Health();
    gotoxy(150, 5);
    cout << "Level 1" << endl;
    gamerun = true;
    while (gamerun)
    {

        playermovement();    // player movement up, down, right, left
        movePlayerbullet();  // player bullets right
        movePlayerbulletL(); // player bullets left
        // Enemy's 1 functionalities
        E1_functionalities(); // Thunderbolt_1
        E2_functionalities(); // Thunderbolt_2
        E5_functionalities(); // Thunderbolt_3

        if (enemy1_health <= 0 && enemy2_health <= 0 && enemy5_health <= 0)
        {
            gotoxy(135, 21);
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            int k = 2;
            SetConsoleTextAttribute(hConsole, k);

            level_2(); // start of level 2
        }
        if (enemy3_health <= 0 && enemy6_health <= 0)
        {
            gotoxy(135, 21);
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            int k = 2;
            SetConsoleTextAttribute(hConsole, k);

            level_3(); // start of level 3
        }
        if (timer <= 0) // generates bullets of enemy 1,2,5 with spaces
        {
            timer = 5;
            generateEnemyBullet1();
            generateEnemyBullet2();
            generateEnemyBullet5();
        }
        timer--;
        printScore(); // print score on the screen
        // collisiondetection();
        if (playerhealth <= 0 || lives == 0) // when player health is zero "Game over" Menu is apper on the screen
        {
            system("cls");
            gameOver();
            string opt;
            cout << " 1. Play Again" << endl;
            cout << " 2. Go Back" << endl;
            cout << "----------------------------" << endl;
            cout << "Select your option..";
            cin >> opt;
            if (opt == "1")
            {
                refreshvalues();
                storebulletcount();
                storemis();
                break;
            }
            else if (opt == "2")
            {
                break;
            }
        }
        else if (enemy4_health <= 0) // when Steel Jaguar health's is zero "You won" is appeard on the screen
        {
            system("cls");
            Won();
            refreshvalues();
            storemis();
            storebulletcount();
            string opt;
            cout << "Press C to continue..";
            cin >> opt;
            if (opt == "C" || opt == "c")
            {
                break;
            }
        }
        Sleep(10);
        if (GetAsyncKeyState(VK_ESCAPE)) // when escape is pressed all the coordinates and healths is stored in files
        {
            system("cls");
            storecoordinates();
            storemis();
            break;
        }
    }
}

void playermovement() // control player movement
{
    if (GetAsyncKeyState(VK_RIGHT))
    {
        movePlayerRight();
        gotoxy(40, 40);
    }

    if (GetAsyncKeyState(VK_LEFT))
    {
        movePlayerLeft();
        gotoxy(40, 40);
    }

    if (GetAsyncKeyState(VK_UP))
    {
        movePlayerUp();
        gotoxy(40, 40);
    }

    if (GetAsyncKeyState(VK_DOWN))
    {
        movePlayerDown();
        gotoxy(40, 40);
    }

    if (GetAsyncKeyState(VK_SPACE))
    {
        generatebullet();
    }
    if (GetAsyncKeyState(VK_TAB))
    {
        generatebulletleft();
    }
}

void movePlayerRight() // move player to right  direction
{
    char nextlocation = getCharAtxy(px + 15, py);
    if (nextlocation == ' ')
    {
        clearplayer(px, py);
        px = px + 1;
        printplayer(px, py);
    }
}

void movePlayerLeft() // move player to left  direction
{
    char nextlocation = getCharAtxy(px - 1, py);
    if (nextlocation == ' ')
    {
        clearplayer(px, py);
        px = px - 1;
        printplayer(px, py);
    }
}

void movePlayerUp() // move player to up direction
{

    char nextlocation = getCharAtxy(px, py - 1);
    if (nextlocation == ' ')
    {
        clearplayer(px, py);
        py = py - 1;
        printplayer(px, py);
    }
}

void movePlayerDown() // move player to down  direction
{
    char nextlocation = getCharAtxy(px, py + 4);
    if (nextlocation == ' ')
    {
        clearplayer(px, py);
        py = py + 1;
        printplayer(px, py);
    }
}

void printmaze() // print maze on the screen with grey color
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k = 8;
    SetConsoleTextAttribute(hConsole, k);
    for (int i = 0; i < 31; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            cout << maze[i][j];
        }
        cout << endl;
    }
}

void printplayer(int x, int y) // print player on screen with green color
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k = 10;
    SetConsoleTextAttribute(hConsole, k);
    for (int i = 0; i < 4; i++)
    {
        gotoxy(px, py + i);
        for (int j = 0; j < 15; j++)
        {
            cout << player[i][j];
        }
    }
}

void generatebullet() // generate right bullets of player
{
    char nextlocation = getCharAtxy(px + 15, py);
    if (nextlocation != '#')
    {
        bulletX[bulletcount] = px + 15;
        bulletY[bulletcount] = py;
        isbulletactive[bulletcount] = true;
        gotoxy(px + 15, py);
        char playerbullet = 16;
        cout << playerbullet;
        bulletcount++;
        storebulletcount();
    }
}

void generatebulletleft() // generate left bullets of player
{
    char nextlocation = getCharAtxy(px - 1, py);
    if (nextlocation != '#')
    {
        bulletXL[bulletcountL] = px - 1;
        bulletYL[bulletcountL] = py;
        isbulletactiveL[bulletcountL] = true;
        gotoxy(px - 1, py);
        char playerbulletL = 17;
        cout << playerbulletL;
        bulletcountL++;
        storebulletcount();
    }
}
void printScore() // print score on the screen
{
    gotoxy(135, 5);
    cout << "Score: " << score;
}
void printPlayerHealth() // print player health with green color
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k = 2;
    SetConsoleTextAttribute(hConsole, k);
    gotoxy(135, 7);
    cout << "Steel Levithan Health: " << playerhealth << " ";
}

void movePlayerbullet() // move player right bullet
{
    for (int i = 0; i < bulletcount; i++)
    {
        if (isbulletactive[i] == true)
        {
            char nextlocation = getCharAtxy(bulletX[i] + 1, bulletY[i]);
            if (nextlocation == ' ')
            {
                erasePlayerbullet(bulletX[i], bulletY[i]);
                gotoxy(40, 40);
                bulletX[i] = bulletX[i] + 1;
                printPlayerbullet(bulletX[i], bulletY[i]);
                gotoxy(40, 40);
            }
            else
            {

                erasePlayerbullet(bulletX[i], bulletY[i]);
                isbulletactive[i] = false;
            }
        }
    }
}

void movePlayerbulletL() // move player's left bullet
{
    for (int i = 0; i < bulletcountL; i++)
    {
        if (isbulletactiveL[i] == true)
        {
            char nextlocation = getCharAtxy(bulletXL[i] - 1, bulletYL[i]);
            if (nextlocation == ' ')
            {
                erasePlayerbullet(bulletXL[i], bulletYL[i]);
                gotoxy(40, 40);
                bulletXL[i] = bulletXL[i] - 1;
                printPlayerbulletL(bulletXL[i], bulletYL[i]);
                gotoxy(40, 40);
            }
            else
            {

                erasePlayerbullet(bulletXL[i], bulletYL[i]);
                isbulletactiveL[i] = false;
            }
        }
    }
}

void collisiondetection()
{
    if ((px + 15 == Ex1) || (px + 15 == Ey1 + 1) || (px + 15 == Ey1 + 2) || (px + 15 == Ex2) || (px + 15 == Ey2 + 1) || (px + 15 == Ey2 + 2) || (px + 15 == Ex3) || (px + 15 == Ey3 + 1) || (px + 15 == Ey3 + 2) || (px + 15 == Ex4) || (px + 15 == Ey4 + 1) || (px + 15 == Ey4 + 2) || (px + 15 == Ey4 + 3))
    {
        playerhealth -= 10;
        clearplayer(px, py);
        px = 5, py = 10;
        printplayer(px, py);
        lives--;
        gotoxy(150, 5);
        cout << "Lives: " << lives;
    }
}

void printPlayerbullet(int x, int y) // print player's bullets right
{
    char playerbullet = 16;
    gotoxy(x, y);
    cout << playerbullet;
}

void printPlayerbulletL(int x, int y) // print player's bullets left
{
    char playerbullet = 17;
    gotoxy(x, y);
    cout << playerbullet;
}
void erasePlayerbullet(int x, int y) // erase plalyer's bullet
{
    gotoxy(x, y);
    cout << " ";
}

void clearplayer(int x, int y) // erase player on the screeen
{
    gotoxy(x, y);
    cout << "               " << endl; // 15 space
    gotoxy(x, y + 1);
    cout << "               " << endl; // 15 space
    gotoxy(x, y + 2);
    cout << "               " << endl; // 15 space
    gotoxy(x, y + 3);
    cout << "               " << endl; // 15 space
}

// ************************* Enemy 1/ Thunder bolt 1 ************************

void printenemy_1_2_5(int x, int y) // print enemy 1,2,5 on the screen
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k = 14;
    SetConsoleTextAttribute(hConsole, k);
    for (int i = 0; i < 3; i++)
    {
        gotoxy(x, y + i);
        for (int j = 0; j < 10; j++)
        {
            cout << enemy_1[i][j];
        }
    }
}

void eraseEnemy_1_2_5(int x, int y) // erase enemy 1,2,5 on the screen
{
    gotoxy(x, y);
    cout << "          " << endl;
    gotoxy(x, y + 1);
    cout << "          " << endl;
    gotoxy(x, y + 2);
    cout << "          " << endl;
}

void printEnemy1_Health() // print enemy 1 health with yellow color
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k = 14;
    SetConsoleTextAttribute(hConsole, k);
    gotoxy(135, 9);
    cout << "Thunderbolt_1 health: " << enemy1_health << " ";
}

void bulletCollisionwithEnemy1() // detect bullet collision of player with enemy
{
    for (int i = 0; i < bulletcount; i++)
    {
        if (isbulletactive[i] == true)
        {
            if (bulletX[i] + 1 == Ex1 && (bulletY[i] + 1 == Ey1 || bulletY[i] + 1 == Ey1 + 2 || bulletY[i] + 1 == Ey1 + 3))
            {
                score = score + 1;
                enemy1_health = enemy1_health - 5;
            }
            if (Ex1 - 1 == bulletX[i] && Ey1 + 1 == bulletY[i])
            {
                score = score + 1;
                enemy1_health = enemy1_health - 5;
            }
        }
    }
    printEnemy1_Health();
}

void moveEnemy1() // move enemy 1 horizontally
{
    if (direction_enemy1 == "left")
    {
        char nextlocation2 = getCharAtxy(Ex1 - 1, Ey1 + 1);
        char nextlocation3 = getCharAtxy(Ex1 - 1, Ey1 + 2);
        if (nextlocation2 == ' ' && nextlocation3 == ' ')
        {

            char nextlocation = getCharAtxy(Ex1 - 1, Ey1);
            if (Ex1 <= 40 && nextlocation == ' ')
            {
                direction_enemy1 = "right";
            }
            if (nextlocation == ' ')
            {
                eraseEnemy_1_2_5(Ex1, Ey1);
                Ex1 = Ex1 - 1;
                printenemy_1_2_5(Ex1, Ey1);
            }
        }
    }
    if (direction_enemy1 == "right")
    {
        char nextlocation2 = getCharAtxy(Ex1 + 10, Ey1 + 1);
        char nextlocation3 = getCharAtxy(Ex1 + 10, Ey1 + 2);
        char nextlocation = getCharAtxy(Ex1 + 10, Ey1);
        if (nextlocation2 == ' ' && nextlocation3 == ' ' || nextlocation == '#')
        {
            if (nextlocation == '#')
            {
                direction_enemy1 = "left";
            }
            if (nextlocation == ' ')
            {
                eraseEnemy_1_2_5(Ex1, Ey1);
                Ex1 = Ex1 + 1;
                printenemy_1_2_5(Ex1, Ey1);
            }
        }
    }
}

void printbullet_enemy_1_2_5(int x, int y) // print bullets of enemy 1,2,5
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k = 14;
    SetConsoleTextAttribute(hConsole, k);
    gotoxy(x, y);
    cout << "-";
}

void erasebullet_enemy_1_2_5(int x, int y) // erase bullets of enemy 1,2,5
{
    gotoxy(x, y);
    cout << " ";
}

void generateEnemyBullet1() // generate enemy 1 bullets
{
    enemy1_bulletX[enemy1_bulletcount] = Ex1 - 1;
    enemy1_bulletY[enemy1_bulletcount] = Ey1;
    enemy1_isbulletactive[enemy1_bulletcount] = true;
    gotoxy(Ex1 - 1, Ey1);
    cout << "-";
    enemy1_bulletcount++;
}

void movebullet_enemy1() // move bullets of enemy 1
{
    for (int i = 0; i < enemy1_bulletcount; i++)
    {
        if (enemy1_isbulletactive[i] == true)
        {
            char nextlocation = getCharAtxy(enemy1_bulletX[i] - 1, enemy1_bulletY[i]);
            if (nextlocation == ' ')
            {
                erasebullet_enemy_1_2_5(enemy1_bulletX[i], enemy1_bulletY[i]);
                gotoxy(40, 40);
                enemy1_bulletX[i]--;
                printbullet_enemy_1_2_5(enemy1_bulletX[i], enemy1_bulletY[i]);
                gotoxy(40, 40);
            }
            else
            {
                erasebullet_enemy_1_2_5(enemy1_bulletX[i], enemy1_bulletY[i]);
                enemy1_isbulletactive[i] = false;
            }
        }
    }
}

void EnemyBulletCollisionwithPlayer() // detect bullets collsion of enemy's bullet with player
{
    char nextlocation = getCharAtxy(px + 15, py);
    if (nextlocation == '-' || nextlocation == '*')
    {
        playerhealth -= 1;
    }
    char nextlocation1 = getCharAtxy(px + 15, py + 1);
    {
        if (nextlocation1 == '-' || nextlocation1 == '*')
        {
            playerhealth -= 1;
        }
    }
    char nextlocation2 = getCharAtxy(px + 16, py + 2);
    {
        if (nextlocation2 == '-' || nextlocation2 == '*')
        {
            playerhealth -= 1;
        }
    }
    char nextlocation3 = getCharAtxy(px + 15, py + 3);
    {
        if (nextlocation3 == '-' || nextlocation3 == '*')
        {
            playerhealth -= 1;
        }
    }
    printPlayerHealth();
}

// ************************* Enemy 2/ Thunder bolt 2  ***************************

void printEnemy2_Health() // print enemy 2 health
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k = 14;
    SetConsoleTextAttribute(hConsole, k);
    gotoxy(135, 11);
    cout << "Thunderbolt_2 health: " << enemy2_health << " ";
}

void bulletCollisionwithEnemy2() // detect bullet collision of player with enemy
{
    for (int i = 0; i < bulletcount; i++)
    {
        if (isbulletactive[i] == true)
        {
            if (bulletX[i] + 1 == Ex2 && (bulletY[i] == Ey2 || bulletY[i] == Ey2 + 2 || bulletY[i] == Ey2 + 3))
            {
                score = score + 1;
                enemy2_health = enemy2_health - 5;
            }
            if (Ex2 - 1 == bulletX[i] && Ey2 + 1 == bulletY[i])
            {
                score = score + 1;
                enemy2_health = enemy2_health - 5;
            }
        }
    }
    printEnemy2_Health();
}

void moveEnemy2() // move enemy 2 in horizontally
{
    if (direction_enemy2 == "left")
    {
        char nextlocation2 = getCharAtxy(Ex2 - 1, Ey2 + 1);
        char nextlocation3 = getCharAtxy(Ex2 - 1, Ey2 + 2);
        if (nextlocation2 == ' ' && nextlocation3 == ' ')
        {

            char nextlocation = getCharAtxy(Ex2 - 1, Ey2);
            if (Ex2 <= 40 && nextlocation == ' ')
            {
                direction_enemy2 = "right";
            }
            if (nextlocation == ' ')
            {
                eraseEnemy_1_2_5(Ex2, Ey2);
                Ex2 = Ex2 - 1;
                printenemy_1_2_5(Ex2, Ey2);
            }
        }
    }
    if (direction_enemy2 == "right")
    {
        char nextlocation2 = getCharAtxy(Ex2 + 10, Ey2 + 1);
        char nextlocation3 = getCharAtxy(Ex2 + 10, Ey2 + 2);
        char nextlocation = getCharAtxy(Ex2 + 10, Ey2);
        if (nextlocation2 == ' ' && nextlocation3 == ' ' || nextlocation == '#')
        {
            if (nextlocation == '#')
            {
                direction_enemy2 = "left";
            }
            if (nextlocation == ' ')
            {
                eraseEnemy_1_2_5(Ex2, Ey2);
                Ex2 = Ex2 + 1;
                printenemy_1_2_5(Ex2, Ey2);
            }
        }
    }
}

void generateEnemyBullet2() // generate bullet of enemy 2
{
    enemy2_bulletX[enemy2_bulletcount] = Ex2 - 1;
    enemy2_bulletY[enemy2_bulletcount] = Ey2;
    enemy2_isbulletactive[enemy2_bulletcount] = true;
    gotoxy(Ex2 - 1, Ey2);
    cout << "-";
    enemy2_bulletcount++;
}

void movebullet_enemy2() // move bullet of enemy 2
{
    for (int i = 0; i < enemy2_bulletcount; i++)
    {
        if (enemy2_isbulletactive[i] == true)
        {
            char nextlocation = getCharAtxy(enemy2_bulletX[i] - 1, enemy2_bulletY[i]);
            if (nextlocation == ' ')
            {
                erasebullet_enemy_1_2_5(enemy2_bulletX[i], enemy2_bulletY[i]);
                gotoxy(40, 40);
                enemy2_bulletX[i]--;
                printbullet_enemy_1_2_5(enemy2_bulletX[i], enemy2_bulletY[i]);
                gotoxy(40, 40);
            }
            else
            {
                erasebullet_enemy_1_2_5(enemy2_bulletX[i], enemy2_bulletY[i]);
                enemy2_isbulletactive[i] = false;
            }
        }
    }
}

//  ************************ Enemy 5/ Thunder bolt 3 **********************

void printEnemy5_Health() // print enemy 5 health
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k = 14;
    SetConsoleTextAttribute(hConsole, k);
    gotoxy(135, 13);
    cout << "Thunderbolt_3 health: " << enemy5_health << " ";
}

void bulletCollisionwithEnemy5() // detect bullet collision of player with enemy 5
{
    for (int i = 0; i < bulletcount; i++)
    {
        if (isbulletactive[i] == true)
        {
            if (bulletX[i] + 1 == Ex5 && (bulletY[i] == Ey5 || bulletY[i] == Ey5 + 2 || bulletY[i] == Ey5 + 3))
            {
                score = score + 1;
                enemy5_health = enemy5_health - 5;
            }
            if (Ex5 - 1 == bulletX[i] && Ey5 + 1 == bulletY[i])
            {
                score = score + 1;
                enemy5_health = enemy5_health - 5;
            }
        }
    }
    printEnemy5_Health();
}

void moveEnemy5() // move enemy 5 horizontally
{
    if (direction_enemy5 == "left")
    {
        char nextlocation2 = getCharAtxy(Ex5 - 1, Ey5 + 1);
        char nextlocation3 = getCharAtxy(Ex5 - 1, Ey5 + 2);
        if (nextlocation2 == ' ' && nextlocation3 == ' ')
        {

            char nextlocation = getCharAtxy(Ex5 - 1, Ey5);
            if (Ex5 <= 40 && nextlocation == ' ')
            {
                direction_enemy5 = "right";
            }
            if (nextlocation == ' ')
            {
                eraseEnemy_1_2_5(Ex5, Ey5);
                Ex5 = Ex5 - 1;
                printenemy_1_2_5(Ex5, Ey5);
            }
        }
    }
    if (direction_enemy5 == "right")
    {
        char nextlocation2 = getCharAtxy(Ex5 + 10, Ey5 + 1);
        char nextlocation3 = getCharAtxy(Ex5 + 10, Ey5 + 2);
        char nextlocation = getCharAtxy(Ex5 + 10, Ey5);
        if (nextlocation2 == ' ' && nextlocation3 == ' ' || nextlocation == '#')
        {
            if (nextlocation == '#')
            {
                direction_enemy5 = "left";
            }
            if (nextlocation == ' ')
            {
                eraseEnemy_1_2_5(Ex5, Ey5);
                Ex5 = Ex5 + 1;
                printenemy_1_2_5(Ex5, Ey5);
            }
        }
    }
}

void generateEnemyBullet5() // generate bullets
{
    enemy5_bulletX[enemy5_bulletcount] = Ex5 - 1;
    enemy5_bulletY[enemy5_bulletcount] = Ey5;
    enemy5_isbulletactive[enemy5_bulletcount] = true;
    gotoxy(Ex5 - 1, Ey5);
    cout << "-";
    enemy5_bulletcount++;
}

void movebullet_enemy5() // move enemy's bullet
{
    for (int i = 0; i < enemy5_bulletcount; i++)
    {
        if (enemy5_isbulletactive[i] == true)
        {
            char nextlocation = getCharAtxy(enemy5_bulletX[i] - 1, enemy5_bulletY[i]);
            if (nextlocation == ' ')
            {
                erasebullet_enemy_1_2_5(enemy5_bulletX[i], enemy5_bulletY[i]);
                gotoxy(40, 40);
                enemy5_bulletX[i]--;
                printbullet_enemy_1_2_5(enemy5_bulletX[i], enemy5_bulletY[i]);
                gotoxy(40, 40);
            }
            else
            {
                erasebullet_enemy_1_2_5(enemy5_bulletX[i], enemy5_bulletY[i]);
                enemy5_isbulletactive[i] = false;
            }
        }
    }
}

// ************************** Enemy 3/ Iron Fury 1 **********************

void printenemy_3_4_6(int x, int y) // print enemy 3,4,6
{

    for (int i = 0; i < 4; i++)
    {
        gotoxy(x, y + i);
        for (int j = 0; j < 16; j++)
        {
            cout << enemy_3[i][j];
        }
    }
}

void eraseEnemy_3_4_6(int x, int y) // erase enemy 3,4,6
{
    gotoxy(x, y);
    cout << "                 " << endl;
    gotoxy(x, y + 1);
    cout << "                 " << endl;
    gotoxy(x, y + 2);
    cout << "                 " << endl;
    gotoxy(x, y + 3);
    cout << "                 " << endl;
}

void printEnemy3_Health() // print enemy 3 health
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k = 14;
    SetConsoleTextAttribute(hConsole, k);
    gotoxy(135, 9);
    cout << "Iron Fury health: " << enemy3_health << " ";
}

void bulletCollisionwithEnemy3() // detect bullet collision of player with enemy
{
    for (int i = 0; i < bulletcount; i++)
    {
        if (isbulletactive[i] == true)
        {
            if (bulletX[i] + 1 == Ex3 && (bulletY[i] == Ey3 || bulletY[i] == Ey3 + 1 || bulletY[i] == Ey3 + 2 || bulletY[i] == Ey3 + 3))
            {
                score = score + 1;
                enemy3_health = enemy3_health - 5;
            }
            if (Ex3 - 1 == bulletX[i] && Ey3 + 1 == bulletY[i])
            {
                score = score + 1;
                enemy3_health = enemy3_health - 5;
            }
        }
    }
    printEnemy3_Health();
}

void moveEnemy3() // move enemy vertically
{

    if (direction1 == "Up")
    {
        char playerbullet = 16;
        cout << playerbullet;
        char nextlocation = getCharAtxy(Ex3, Ey3 - 1);
        if (Ey3 <= 15)
        {
            direction1 = "Down";
        }
        if (nextlocation == ' ' || nextlocation == playerbullet)
        {
            eraseEnemy_3_4_6(Ex3, Ey3);
            Ey3 = Ey3 - 1;
            printenemy_3_4_6(Ex3, Ey3);
            gotoxy(40, 40);
        }
    }
    if (direction1 == "Down")
    {
        char playerbullet = 16;
        cout << playerbullet;
        char nextlocation = getCharAtxy(Ex3, Ey3 + 4);
        if (nextlocation == '#')
        {
            direction1 = "Up";
        }
        if (nextlocation == ' ' || nextlocation == playerbullet)
        {
            eraseEnemy_3_4_6(Ex3, Ey3);
            Ey3 = Ey3 + 1;
            printenemy_3_4_6(Ex3, Ey3);
            gotoxy(40, 40);
        }
    }
}

void printbullet_enemy3(int x, int y) // print bullet of enemy 3
{
    gotoxy(x, y);
    cout << "-";
}

void erasebullet_enemy3(int x, int y) // erase bullets of enemy 3
{
    gotoxy(x, y);
    cout << " ";
}

void generateEnemyBullet3() // generate bullets of enemy 3
{
    enemy3_bulletX[enemy3_bulletcount] = Ex3 - 1;
    enemy3_bulletY[enemy3_bulletcount] = Ey3;
    enemy3_isbulletactive[enemy3_bulletcount] = true;
    gotoxy(Ex3 - 1, Ey3);
    cout << "-";
    enemy3_bulletcount++;
}

void movebullet_enemy3() // move bullets of enemy 3
{
    for (int i = 0; i < enemy3_bulletcount; i++)
    {
        if (enemy3_isbulletactive[i] == true)
        {
            char nextlocation = getCharAtxy(enemy3_bulletX[i] - 1, enemy3_bulletY[i]);
            if (nextlocation == ' ')
            {
                erasebullet_enemy3(enemy3_bulletX[i], enemy3_bulletY[i]);
                gotoxy(40, 40);
                enemy3_bulletX[i]--;
                printbullet_enemy3(enemy3_bulletX[i], enemy3_bulletY[i]);
                gotoxy(40, 40);
            }
            else if (nextlocation == '>' || nextlocation == ']' || nextlocation == '/' || nextlocation == '#')
            {
                erasebullet_enemy3(enemy3_bulletX[i], enemy3_bulletY[i]);
                enemy3_isbulletactive[i] = false;
            }
        }
    }
}

// *************************** Enemy 6/ Iron Fury 2 *********************

void printEnemy6_Health() // print enemy 6 health
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k = 14;
    SetConsoleTextAttribute(hConsole, k);
    gotoxy(135, 11);
    cout << "Iron Fury health_1: " << enemy6_health << " ";
}

void bulletCollisionwithEnemy6() // bullet collision of player with enemy 6
{
    for (int i = 0; i < bulletcount; i++)
    {
        if (isbulletactive[i] == true)
        {
            if (bulletX[i] + 1 == Ex6 && (bulletY[i] == Ey6 || bulletY[i] == Ey6 + 1 || bulletY[i] == Ey6 + 2 || bulletY[i] == Ey6 + 3))
            {
                score = score + 1;
                enemy6_health = enemy6_health - 5;
            }
            if (Ex6 - 1 == bulletX[i] && Ey6 + 1 == bulletY[i])
            {
                score = score + 1;
                enemy6_health = enemy6_health - 5;
            }
        }
    }
    printEnemy6_Health();
}

void moveEnemy6() // move enemy 6 vertically
{

    if (direction6 == "Up")
    {
        char playerbullet = 16;
        cout << playerbullet;
        char nextlocation = getCharAtxy(Ex6, Ey6 - 1);
        if (Ey6 <= 2)
        {
            direction6 = "Down";
        }
        if (nextlocation == ' ' || nextlocation == playerbullet)
        {
            eraseEnemy_3_4_6(Ex6, Ey6);
            Ey6 = Ey6 - 1;
            printenemy_3_4_6(Ex6, Ey6);
            gotoxy(40, 40);
        }
    }
    if (direction6 == "Down")
    {
        char playerbullet = 16;
        cout << playerbullet;
        char nextlocation = getCharAtxy(Ex6, Ey6 + 4);
        if (Ey6 > 10)
        {
            direction6 = "Up";
        }
        if (nextlocation == ' ' || nextlocation == playerbullet)
        {
            eraseEnemy_3_4_6(Ex6, Ey6);
            Ey6 = Ey6 + 1;
            printenemy_3_4_6(Ex6, Ey6);
            gotoxy(40, 40);
        }
    }
}

void printbullet_enemy6(int x, int y) // print bullet of enemy 6
{
    gotoxy(x, y);
    cout << "-";
}

void erasebullet_enemy6(int x, int y) // erase bullets of enemy 6
{
    gotoxy(x, y);
    cout << " ";
}

void generateEnemyBullet6() // generate bullets of enemy 6
{
    enemy6_bulletX[enemy6_bulletcount] = Ex6 - 1;
    enemy6_bulletY[enemy6_bulletcount] = Ey6;
    enemy6_isbulletactive[enemy6_bulletcount] = true;
    gotoxy(Ex6 - 1, Ey6);
    cout << "  -  ";
    enemy6_bulletcount++;
}

void movebullet_enemy6() // move bullets of enemy 6
{
    for (int i = 0; i < enemy6_bulletcount; i++)
    {
        if (enemy6_isbulletactive[i] == true)
        {
            char nextlocation = getCharAtxy(enemy6_bulletX[i] - 1, enemy6_bulletY[i]);
            if (nextlocation == ' ')
            {
                erasebullet_enemy6(enemy6_bulletX[i], enemy6_bulletY[i]);
                gotoxy(40, 40);
                enemy6_bulletX[i]--;
                printbullet_enemy6(enemy6_bulletX[i], enemy6_bulletY[i]);
                gotoxy(40, 40);
            }
            else if (nextlocation == '>' || nextlocation == ']' || nextlocation == '/' || nextlocation == '#')
            {
                erasebullet_enemy6(enemy6_bulletX[i], enemy6_bulletY[i]);
                enemy6_isbulletactive[i] = false;
            }
        }
    }
}

// ************************* Enemy 4/ Steel Jaguar ***********************

void printEnemy4_Health() // print enemy 4 health
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k = 12;
    SetConsoleTextAttribute(hConsole, k);
    gotoxy(135, 9);
    cout << "Steel Jaguar health: " << enemy4_health << " ";
}

void bulletCollisionwithEnemy4() // bullet collision of player with enemy 4 from right
{
    for (int i = 0; i < bulletcount; i++)
    {
        if (isbulletactive[i] == true)
        {
            if (bulletX[i] + 1 == Ex4 && (bulletY[i] == Ey4 || bulletY[i] == Ey4 + 1 || bulletY[i] == Ey4 + 2 || bulletY[i] == Ey4 + 3))
            {
                score = score + 1;
                enemy4_health = enemy4_health - 5;
            }
            if (Ex4 - 1 == bulletX[i] && Ey4 + 1 == bulletY[i])
            {
                score = score + 1;
                enemy4_health = enemy4_health - 5;
            }
        }
    }
    printEnemy4_Health();
}

void bulletCollisionwithEnemy4Left() // bullet collision of player with enemy 4 from left
{
    for (int i = 0; i < bulletcountL; i++)
    {
        if (isbulletactiveL[i] == true)
        {
            if (bulletXL[i] - 1 == Ex4 && (bulletYL[i] == Ey4 || bulletYL[i] == Ey4 + 1 || bulletYL[i] == Ey4 + 2 || bulletYL[i] == Ey4 + 3))
            {
                score = score + 1;
                enemy4_health = enemy4_health - 5;
            }
            if (Ex4 - 1 == bulletXL[i] && Ey4 + 1 == bulletYL[i])
            {
                score = score + 1;
                enemy4_health = enemy4_health - 5;
            }
        }
    }
    printEnemy4_Health();
}

void chaseplayer() // chase the player
{

    if (Ex4 < px)
    {
        char nextlocation = getCharAtxy(Ex4 + 15, Ey4);
        if (nextlocation == ' ')
        {
            eraseEnemy_3_4_6(Ex4, Ey4);
            Ex4 += 0.5;
            printenemy_3_4_6(Ex4, Ey4);
        }
    }

    if (Ex4 > px)
    {
        char nextlocation = getCharAtxy(Ex4 - 1, Ey4);
        if (nextlocation == ' ')
        {
            eraseEnemy_3_4_6(Ex4, Ey4);
            Ex4 -= 0.5;
            printenemy_3_4_6(Ex4, Ey4);
        }
    }

    if (Ey4 < py)
    {
        char nextlocation = getCharAtxy(Ex4, Ey4 + 4);
        if (nextlocation == ' ')
        {
            eraseEnemy_3_4_6(Ex4, Ey4);
            Ey4 += 0.5;
            printenemy_3_4_6(Ex4, Ey4);
        }
    }

    if (Ey4 > py)
    {
        char nextlocation = getCharAtxy(Ex4, Ey4 - 1);
        if (nextlocation == ' ')
        {
            eraseEnemy_3_4_6(Ex4, Ey4);
            Ey4 -= 0.5;
            printenemy_3_4_6(Ex4, Ey4);
        }
    }
}

void printbullet_enemy4(int x, int y) // print bullets of enemy 4
{
    gotoxy(x, y);
    cout << "*";
}

void erasebullet_enemy4(int x, int y) // erase bullets of enemy 4
{
    gotoxy(x, y);
    cout << " ";
}

void generateEnemyBullet4() // generate bullets of enemy 4
{
    enemy4_bulletX[enemy4_bulletcount] = Ex4 - 1;
    enemy4_bulletY[enemy4_bulletcount] = Ey4;
    enemy4_isbulletactive[enemy4_bulletcount] = true;
    gotoxy(Ex4 - 1, Ey4);
    cout << "*";
    enemy4_bulletcount++;
}

void movebullet_enemy4() // move bullets of enemy 4
{
    for (int i = 0; i < enemy4_bulletcount; i++)
    {
        if (enemy4_isbulletactive[i] == true)
        {
            char nextlocation = getCharAtxy(enemy4_bulletX[i] - 1, enemy4_bulletY[i]);
            if (nextlocation == ' ' || nextlocation == '.')
            {
                erasebullet_enemy4(enemy4_bulletX[i], enemy4_bulletY[i]);
                gotoxy(40, 40);
                enemy4_bulletX[i]--;
                printbullet_enemy4(enemy4_bulletX[i], enemy4_bulletY[i]);
                gotoxy(40, 40);
            }
            else if (nextlocation == '>' || nextlocation == ']' || nextlocation == '/' || nextlocation == '#')
            {
                erasebullet_enemy4(enemy4_bulletX[i], enemy4_bulletY[i]);
                enemy4_isbulletactive[i] = false;
            }
            else
            {
                erasebullet_enemy4(enemy4_bulletX[i], enemy4_bulletY[i]);
                enemy4_isbulletactive[i] = false;
            }
        }
    }
}

// ********************** Enemy 1 Functionalities/ Thunder bolt 1 ********************
void E1_functionalities()
{
    if (enemy1_health > 0)
    {
        moveEnemy1();                     // move enemy
        movebullet_enemy1();              // move bullets
        bulletCollisionwithEnemy1();      // detect bullet collision
        EnemyBulletCollisionwithPlayer(); // detect bullet collision of enemy's bullet
    }
    else
    {
        eraseEnemy_1_2_5(Ex1, Ey1); // erase enemy 1
        for (int i = 0; i < enemy1_bulletcount; i++)
        {
            erasebullet_enemy_1_2_5(enemy1_bulletX[i], enemy1_bulletY[i]); // erase enemy 1 bullets
        }
        enemy1_health = 0;
    }
}

// ********************** Enemy 2 Functionalities/ Thunder bolt 2 ********************
void E2_functionalities()
{
    if (enemy2_health > 0)
    {
        moveEnemy2();                     // move enemy
        movebullet_enemy2();              // move bullets
        bulletCollisionwithEnemy2();      // detect bullet collision
        EnemyBulletCollisionwithPlayer(); // detect bullet collision of enemy's bullet
    }
    else
    {
        eraseEnemy_1_2_5(Ex2, Ey2); // erase enemy 2
        for (int i = 0; i < enemy2_bulletcount; i++)
        {
            erasebullet_enemy_1_2_5(enemy2_bulletX[i], enemy2_bulletY[i]); // erase enemy 2 bullets
        }
        enemy2_health = 0;
    }
}

// ********************** Enemy 5 Functionalities/ Thunder bolt 3 ********************

void E5_functionalities()
{
    if (enemy5_health > 0)
    {
        moveEnemy5();                     // move enemy
        movebullet_enemy5();              // move bullets
        bulletCollisionwithEnemy5();      // detect bullet collision
        EnemyBulletCollisionwithPlayer(); // detect bullet collision of enemy's bullet
    }
    else
    {
        eraseEnemy_1_2_5(Ex5, Ey5); // erase enemy 5
        for (int i = 0; i < enemy5_bulletcount; i++)
        {
            erasebullet_enemy_1_2_5(enemy5_bulletX[i], enemy5_bulletY[i]); // erase enemy 2 bullets
        }
        enemy5_health = 0;
    }
}
// ************************** level 2 ************************

void level_2() // level 2 functions
{
    system("cls");
    printmaze();
    printplayer(px, py);

    printEnemy3_Health();
    printEnemy6_Health();
    gotoxy(150, 5);
    cout << "Level 2" << endl;
    while (true)
    {
        playermovement();

        Sleep(20);
        movePlayerbullet();
        movePlayerbulletL();
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        int k = 14;
        SetConsoleTextAttribute(hConsole, k);
        E3_functionalities(); // contain the functionalities of enemy 3
        E6_functionalities(); // contain the functionalities of enemy 6
        printScore();
        if (enemy3_health == 0 && enemy6_health == 0)
        {
            break;
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            system("cls");
            storecoordinates();
            gamerun = false;
            storemis();
            break;
        }
        if (playerhealth <= 0)
            break;
    }
}

// ********************** Enemy 3 Functionalities/ Iron Fury 1 ********************

void E3_functionalities()
{
    printEnemy3_Health();
    if (enemy3_health > 0)
    {
        printenemy_3_4_6(Ex3, Ey3);
        moveEnemy3();
        if (timer <= 0)
        {
            timer = 7;
            generateEnemyBullet3();
        }
        timer--;

        movebullet_enemy3();
        bulletCollisionwithEnemy3();
        EnemyBulletCollisionwithPlayer();
    }
    else
    {
        eraseEnemy_3_4_6(Ex3, Ey3);
        for (int i = 0; i < enemy3_bulletcount; i++)
        {
            erasebullet_enemy3(enemy3_bulletX[i], enemy3_bulletY[i]);
        }
        enemy3_health = 0;
    }
}

// ********************** Enemy 6 Functionalities/ Iron fury 2 ********************

void E6_functionalities()
{
    printEnemy6_Health();
    if (enemy6_health > 0)
    {
        printenemy_3_4_6(Ex6, Ey6);
        moveEnemy6();
        if (timer <= 0)
        {
            timer = 7;
            generateEnemyBullet6();
        }
        timer--;

        movebullet_enemy6();
        bulletCollisionwithEnemy6();
        EnemyBulletCollisionwithPlayer();
    }
    else
    {
        eraseEnemy_3_4_6(Ex6, Ey6);
        for (int i = 0; i < enemy6_bulletcount; i++)
        {
            erasebullet_enemy6(enemy6_bulletX[i], enemy6_bulletY[i]);
        }
        enemy6_health = 0;
    }
}

// ************************* Level 3 *********************

void level_3() // level 3 functionalities
{
    system("cls");
    printmaze();

    printplayer(px, py);
    printEnemy4_Health();
    gotoxy(150, 5);
    cout << "Final Level" << endl;
    while (true)
    {
        playermovement();

        movePlayerbullet();
        movePlayerbulletL();
        E4_functionalities(); // Enemy 4/ steel jaguar functionalities
        printScore();

        Sleep(20);
        if (enemy4_health <= 0)
        {
            break;
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            system("cls");
            gamerun = false;
            storecoordinates();
            storemis();
            break;
        }
        if (playerhealth <= 0)
            break;
    }
}

// ********************** Enemy 4 Functionalities/ Steel Jaguar ********************

void E4_functionalities()
{
    printEnemy4_Health();
    if (enemy4_health > 0)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        int k = 12;
        SetConsoleTextAttribute(hConsole, k);
        printenemy_3_4_6(Ex4, Ey4);
        eraseEnemy_3_4_6(Ex4, Ey4);
        if (timer <= 0)
        {
            timer = 10;
            generateEnemyBullet4();
        }
        timer--;
        bulletCollisionwithEnemy4();
        chaseplayer();
        movebullet_enemy4();
        bulletCollisionwithEnemy4Left();
        EnemyBulletCollisionwithPlayer();
    }
    else
    {
        eraseEnemy_3_4_6(Ex4, Ey4);
        for (int i = 0; i < enemy4_bulletcount; i++)
        {
            erasebullet_enemy4(enemy4_bulletX[i], enemy4_bulletY[i]);
        }
        enemy4_health = 0;
    }
}

// ************************* Others ************************

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coorsBufSize;
    coorsBufSize.X = x;
    coorsBufSize.Y = y;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coorsBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void gameOver()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k = 4;
    SetConsoleTextAttribute(hConsole, k);
    cout << "  /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$        /$$$$$$  /$$    /$$ /$$$$$$$$ /$$$$$$$    " << endl;
    cout << " /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/       /$$__  $$| $$   | $$| $$_____/| $$__  $$" << endl;
    cout << "| $$  \\__/| $$  \\ $$| $$$$  /$$$$| $$            | $$  \\ $$| $$   | $$| $$      | $$  \\ $$" << endl;
    cout << "| $$ /$$$$| $$$$$$$$| $$ $$/$$ $$| $$$$$         | $$  | $$|  $$ / $$/| $$$$$   | $$$$$$$/" << endl;
    cout << "| $$|_  $$| $$__  $$| $$  $$$| $$| $$__/         | $$  | $$ \\  $$ $$/ | $$__/   | $$__  $$" << endl;
    cout << "| $$  \\ $$| $$  | $$| $$\\  $ | $$| $$            | $$  | $$  \\  $$$/  | $$      | $$  \\ $$" << endl;
    cout << "|  $$$$$$/| $$  | $$| $$ \\/  | $$| $$$$$$$$      |  $$$$$$/   \\  $/   | $$$$$$$$| $$  | $$" << endl;
    cout << " \\______/ |__/  |__/|__/     |__/|________/       \\______/     \\_/    |________/|__/  |__/" << endl;
}

void Won()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k = 10;
    SetConsoleTextAttribute(hConsole, k);
    cout << "/$$     /$$                        /$$      /$$                    " << endl;
    cout << "|  $$   /$$/                       | $$  /$ | $$                    " << endl;
    cout << " \\  $$ /$$//$$$$$$  /$$   /$$      | $$ /$$$| $$  /$$$$$$  /$$$$$$$ " << endl;
    cout << "  \\  $$$$//$$__  $$| $$  | $$      | $$/$$ $$ $$ /$$__  $$| $$__  $$" << endl;
    cout << "   \\  $$/| $$  \\ $$| $$  | $$      | $$$$_  $$$$| $$  \\ $$| $$  \\ $$" << endl;
    cout << "    | $$ | $$  | $$| $$  | $$      | $$$/ \\  $$$| $$  | $$| $$  | $$" << endl;
    cout << "    | $$ |  $$$$$$/|  $$$$$$/      | $$/   \\  $$|  $$$$$$/| $$  | $$" << endl;
    cout << "    |__/  \\______/  \\______/       |__/     \\__/ \\______/ |__/  |__/" << endl;
}

void loading()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k = 8;
    SetConsoleTextAttribute(hConsole, k);
    char line = 219;

    char line1[15] = {line, line, line, line, line, line, line, line, line, line, line, line, line, line, line};

    for (int i = 0; i < 15; i++)
    {

        cout << line1[i];
        Sleep(150);
    }
}

void loading2()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k = 8;
    SetConsoleTextAttribute(hConsole, k);
    char dim = 205;
    char line2[15] = {dim, dim, dim, dim, dim, dim, dim, dim, dim, dim, dim, dim, dim, dim, dim};

    for (int i = 0; i < 15; i++)
    {
        cout << line2[i];
    }
}

void mainmenu()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k = 6;
    SetConsoleTextAttribute(hConsole, k);
    system("cls");
    cout << "                                      .                              " << endl;
    cout << "                                     *@+                                     " << endl;
    cout << "                                     *##*                    ..                      " << endl;
    cout << "                                     +###-                   ..                       " << endl;
    cout << "                                     .###*                   ..                       " << endl;
    cout << "                                      ####=                  .:                       " << endl;
    cout << "                                      -####                  ..                       " << endl;
    cout << "                                      :=###=                  .                       " << endl;
    cout << "                                      -.####                 .:                       " << endl;
    cout << "                                      - =###=                .:                       " << endl;
    cout << "                                      :  *###-                :                       " << endl;
    cout << "                                      -  +###*-              .:                       " << endl;
    cout << "                                      -  :#####          .--=-:                       " << endl;
    cout << "                                 =++#++*#+#####:......   .##*+-                       " << endl;
    cout << "                         .--=: ..***%**#+++####++%*****++==++*+*****+-                " << endl;
    cout << "                          =*+++++++++++****#####*%++++++++++++++*@%#*                 " << endl;
    cout << "                          -+++++++++++++####%#####++++++++++++++++%#*                 " << endl;
    cout << "                        :++++++++++++++#@@@@@@@@@%*++++++++++++++++#*                 " << endl;
    cout << "                       =*****+++++++*##%@@@@@@@@@@@##*++++++++++++++*--:::--:::::.    " << endl;
    cout << "                       .-+*#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%*+++++++++++*    " << endl;
    cout << "      .....:::::::----=---===+******++**########*********+++*#%%@@@*++++++*++++++=:   " << endl;
    cout << ".--==+++*#***+*#****+++++++++++++***#****+++++++++++++++******++++++++++++++++++++-   " << endl;
    cout << "**+++++*@%####**************+++*+*+****@@*++++++++++++***+++++++++++++++++++++++@=    " << endl;
    cout << "++++++++%##############################@#++++++++++*%*+++++++++++++++++++++++++*@+    " << endl;
    cout << "..+%#%@#%@@##############################****+++++++#@%+++++++++++++++++#+++***#@@:    " << endl;
    cout << "  *##@##%@@#############################%@@%#######@@@#++++##+++++++***#%#%%#@%@*     " << endl;
    cout << "  .*#%@##@@@%##%%%%%%####################%@%#########@%*+++***#%*#@%#@%#@#@%#@%@.     " << endl;
    cout << "    -+#%%%%@@%@@@@%@%%%%%%%%%%%%%%%%%%####@@#######%%@@@@%@@#%%@#%@@*@@#@%%%@#%+      " << endl;
    cout << "       :-*%%%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%######%%%@@%@@#%%@#%@%%%#@%%%*=-:       " << endl;
    cout << "           .=#@@@@@@@@@@@@@@@@@@@@@@%#*+=--:..-#######%%@%@@#@#@#@%%@%%*-:            " << endl;
    cout << "              .-****###%%%#*+==-:.              -##%###%##%%%@@%%%*+-:                " << endl;
    cout << "                                                  -###%%%%@%@%#=-.                    " << endl;
    cout << "                                                           .:                         " << endl;
    cout << endl
         << endl;

    loadingmark();
    gotoxy(40, 35);
    loading2();
    gotoxy(40, 35);
    loading();
}

//---------------------------------------
void loadingmark()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k = 7;
    SetConsoleTextAttribute(hConsole, k);
    gotoxy(43, 36);
    cout << "LOADING...";
}
void tankwarfare()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k = 3;
    SetConsoleTextAttribute(hConsole, k);
    cout << "/$$$$$$$$ /$$$$$$  /$$   /$$ /$$   /$$/      /$$      /$$  /$$$$$$  /$$$$$$$  /$$$$$$$$ /$$$$$$  /$$$$$$$  /$$$$$$$$  " << endl;
    cout << "|__  $$__//$$__  $$| $$$ | $$| $$  /$$/      | $$  /$ | $$ /$$__  $$| $$__  $$| $$_____//$$__  $$| $$__  $$| $$_____/" << endl;
    cout << "   | $$  | $$  \\ $$| $$$$| $$| $$ /$$/       | $$ /$$$| $$| $$  \\ $$| $$  \\ $$| $$     | $$  \\ $$| $$  \\ $$| $$      " << endl;
    cout << "   | $$  | $$$$$$$$| $$ $$ $$| $$$$$/        | $$/$$ $$ $$| $$$$$$$$| $$$$$$$/| $$$$$  | $$$$$$$$| $$$$$$$/| $$$$$   " << endl;
    cout << "   | $$  | $$__  $$| $$  $$$$| $$  $$/       | $$$$_  $$$$| $$__  $$| $$__  $$| $$__/  | $$__  $$| $$__  $$| $$__/   " << endl;
    cout << "   | $$  | $$  | $$| $$\\  $$$| $$\\  $$       | $$$/ \\  $$$| $$  | $$| $$  \\ $$| $$     | $$  | $$| $$  \\ $$| $$      " << endl;
    cout << "   | $$  | $$  | $$| $$ \\  $$| $$ \\  $$      | $$/   \\  $$| $$  | $$| $$  | $$| $$     | $$  | $$| $$  | $$| $$$$$$$$" << endl;
    cout << "   |__/  |__/  |__/|__/  \\__/|__/  \\__/      |__/     \\__/|__/  |__/|__/  |__/|__/     |__/  |__/|__/  |__/|________/" << endl;
}
