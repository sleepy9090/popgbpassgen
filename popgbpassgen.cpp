/**
 ************************************************************************************************************************
 *
 *  @file                   popgbpasgen.cpp
 *  @brief                  Prince of Persia password generator
 *                          for GameBoy version
 *  @copyright              2019 Shawn M. Crawford
 *  @date                   January 15th, 2019
 *
 *  @remark Author:         Shawn M. Crawford
 *
 *  @note                   N/A
 *
 ************************************************************************************************************************
 */

/* Includes */
#include <iostream>
#include <sstream>

using namespace std;

/**
 ************************************************************************************************************************
 *
 * @brief   Encodes password
 *
 * @param   num The number to match to the cypher
 *
 * @return  The number matched in the cyper or 0 if not found
 *
 * @note 
 * Cypher
 * 0 = 5
 * 1 = 4
 * 2 = 7
 * 3 = 6
 * 4 = 1
 * 5 = 0
 * 6 = 3
 * 7 = 2
 * 8 = 9
 * 9 = 8
 *
 ************************************************************************************************************************
 */
int encodePassword(int num)
{
    int result = 0;

    switch (num)
    {
        case 0:
            result = 5;
            break;
        case 1:
            result = 4;
            break;
        case 2:
            result = 7;
            break;
        case 3:
            result = 6;
            break;
        case 4:
            result = 1;
            break;
        case 5:
            result = 0;
            break;
        case 6:
            result = 3;
            break;
        case 7:
            result = 2;
            break;
        case 8:
            result = 9;
            break;
        case 9:
            result = 8;
            break;
        default:
            result = 0;
    }
    return result;
}

/**
 ************************************************************************************************************************
 *
 * @brief   Runs the program
 *
 * @param   N/A
 *
 * @return  N/A
 *
 * @note    N/A
 *
 ************************************************************************************************************************
 */
int main (int argc, char *argv[])
{
    int level = 0;
    int lives = 0;
    int time = 0;
    int digit1 = 0;
    int digit2 = 0;
    int digit3 = 0;
    int digit4 = 0;
    int digit5 = 0;
    int digit6 = 0;
    int digit7 = 0;
    int digit8 = 0;
    string input = "";

    cout << "Prince of Persia (GameBoy) password generator v 1.0" << endl;
    cout << "Coded by: sleepy" << endl;
    cout << "======================================" << endl;
    cout << endl;

    while (true) {
        cout << "Enter level number (0..99): ";
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> level)
        {
            if (level >= 0 && level <= 99)
            {
                break;
            }
        }
        
        cout << "Invalid number, please try again." << endl;
    }

    while (true) {
        cout << "Enter number of lives (0..9): ";
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> lives)
        {
            if (lives >= 0 && lives <= 9)
            {
                break;
            }
        }
        
        cout << "Invalid number, please try again." << endl;
    }

    while (true) {
        cout << "Enter time left (0..99): ";
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> time)
        {
            if (time >= 0 && time <= 99)
            {
                break;
            }
        }
        
        cout << "Invalid number, please try again." << endl;
    }

    digit1 = (level % 10 + level / 10 + lives) % 10;
    digit2 = (time % 10 + (time / 10)) % 10;
    digit3 = (level % 10 + (level / 10)) % 10;
    digit4 = lives % 10;
    digit5 = time % 10;
    digit6 = time / 10;
    digit7 = level % 10;
    digit8 = level / 10;

    // cout << "Generated password before cipher: " << digit1 << digit2 << digit3 << digit4 << digit5 << digit6 << digit7 << digit8 << endl;

    digit1 = encodePassword(digit1);
    digit2 = encodePassword(digit2);
    digit3 = encodePassword(digit3);
    digit4 = encodePassword(digit4);
    digit5 = encodePassword(digit5);
    digit6 = encodePassword(digit6);
    digit7 = encodePassword(digit7);
    digit8 = encodePassword(digit8);

    // level 99, 9 lives, 99 minutes
    // 29988888
    cout << "Generated password: " << digit1 << digit2 << digit3 << digit4 << digit5 << digit6 << digit7 << digit8 << endl;
    return(0);
}

