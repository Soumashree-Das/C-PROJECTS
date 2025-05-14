/*
i have created a vector of pairs having numbers mapping to 0,1,2 . now i will generate random numbers from the computer pov and the user will enter certain strings which will map to the numbers assigned . this way based on the logic user will see win or lose.
*/

#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <utility>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<string> choices = {"rock","paper","scissors"};
/** 
 * @brief Determines the outcome of a Rock-Paper-Scissors game round.
 *
 * This function implements the standard Rock-Paper-Scissors logic using modular arithmetic
 * to handle the cyclical relationship between choices:
 * - Each choice is represented as an integer index: 0 for Rock, 1 for Paper, 2 for Scissors.
 * - The user and computer each select one of these choices.
 * - The outcome is determined as follows:
 *   - If both choices are the same, the result is a draw.
 *   - Each choice i loses to (i+1) % 3 (e.g., Rock loses to Paper).
 *   - Each choice i wins against (i-1+3) % 3 (e.g., Rock beats Scissors).
 *
 * The function prints the computer's choice and the result ("You win", "You lost", or "Draw!").
 *
 * @param userchoice The user's choice as a 1-based integer (1=Rock, 2=Paper, 3=Scissors).
 *                   The function internally converts this to a 0-based index.
 */

void rock_paper_scissors(int userchoice)
{
    int computerChoice = rand() % choices.size();
    userchoice=userchoice-1;
    cout<<"computer chose:"<<choices[computerChoice];
        if(computerChoice==(userchoice+1)%choices.size())
        {
            cout<<"you lost.";
            // break;
        }
        else if(computerChoice==(userchoice-1+3)%3)
        {
            cout<<"you win.";
            // break;
        }
        else
        {
            cout<<"draw!";
            // break;
        }
}



int main() {
    srand(time(0));
    int userInput;
    cout << "Enter your choice : \n1.ROCK:\n2.PAPER:\n3.SCISSORS: ";
    cin >> userInput;
    cout<<"You chose "<<choices[userInput-1]<<endl;
    rock_paper_scissors(userInput);

    return 0;
}
