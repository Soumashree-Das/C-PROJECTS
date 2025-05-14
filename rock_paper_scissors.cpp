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

void rock_paper_scissors(int userchoice)
{
    int computerChoice = rand() % choices.size();
    int uC=userchoice-1;
    cout<<"computer chose:"<<choices[computerChoice];
    if(computerChoice==uC){
        cout<<"draw!\n";
    }else if((uC-computerChoice+3)%3==1){
        cout<<"You win"<<endl;
    }else{
        cout<<"You lost";
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
