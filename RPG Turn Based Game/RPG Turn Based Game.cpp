#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Character.h";
using namespace std;

int choice;
bool gameOver;
Player Gamer("Player", 50, 0, 1);

//Battle process between player and enemies
void Battle(Enemy enemy)
{
    do
    {
        cout << "\nChoose an option to attack" << endl;
        cout << "1. Fire" << endl;
        cout << "2. Ice" << endl;
        cout << "3. Water" << endl;
        cout << "4. Heal" << endl;
        cout << "5. Mega Heal" << endl;
        cin >> choice;
        
        system("cls");

        switch (choice)
        {
        case 1:
            enemy.TakeDamage(5);
            enemy.GetInfo();
            if (enemy.HealthHP() > 0)
            {
                Gamer.TakeDamage(5);
                Gamer.GetInfo();
            }
            break;

        case 2:
            enemy.TakeDamage(10);
            enemy.GetInfo();
            if (enemy.HealthHP() > 0)
            {
                Gamer.TakeDamage(10);
                Gamer.GetInfo();
            }
            break;

        case 3:
            enemy.TakeDamage(15);
            enemy.GetInfo();
            if (enemy.HealthHP() > 0)
            {
                Gamer.TakeDamage(15);
                Gamer.GetInfo();
            }
            break;

        case 4: 
            Gamer.Heal(20);
            break;

        case 5:
            Gamer.Heal(50);
            break;
        default:
            cout << "Invalid Input" << endl;
            break;
        }

        //Check if player is win or lose battle
        if (Gamer.HealthHP() > 0 && enemy.HealthHP() <= 0)
        {
            cout << "Gamer Wins!\n" << endl;
            Gamer.GainExperience(10);
            Gamer.LevelUp();
        }
        else if(Gamer.HealthHP() <= 0 && enemy.HealthHP() > 0 || Gamer.HealthHP() <= 0 && enemy.HealthHP() <= 0)
        {
            cout << "You Lose. Let's try again.\n" << endl;
        }
    }while (enemy.HealthHP() > 0 && Gamer.HealthHP() > 0|| !(choice > 0 && choice < 6));
    system("pause");
    gameOver = true;
    Gamer.Restore(50, 0, 1);    //Restart if player lose
}

//Random enemy that faced by player
void RandomEnemy()
{
    int random;
    srand((unsigned)time(0));
    for (int i = 0; i < 1; i++)
    {
        random = (rand() % 3) + 1;
    }
    
    if (random == 1)
    {
        Enemy Mushroom("Mushroom", 10, 0, 1);
        Mushroom.GetInfo();
        Battle(Mushroom);
    }
    else if (random == 2)
    {
        Enemy Spider("Spider", 20, 0, 2);
        Spider.GetInfo();
        Battle(Spider);
    }
    else
    {
        Enemy BubbleFish("BubbleFish", 30, 0, 3);
        BubbleFish.GetInfo();
        Battle(BubbleFish);
    }
}

void Intro()
{
    char ok;
    cout << "\nHi Warrior, ready to start the game?(y/n)" << endl;
    cin >> ok;
    if (ok == 'Y' || ok == 'y')
    {
        system("cls");
        cout << "Battle start!\n" << endl;
        Gamer.GetInfo();
        RandomEnemy();
    }
}

//Show game menu
void ShowMenu()
{
    gameOver = false;
    cout << "*****Fake Dragon Nest*****" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Quit" << endl;

    cin >> choice;
    if (choice == 1)
        Intro();
}

int main()
{
    do
    {
        system("cls");
        ShowMenu();
    }
    while (gameOver == true || !(choice >0 && choice < 3));
    return 0;
    system("pause > 0");
}

