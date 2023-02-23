#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <random>
#include <cstdlib>
using namespace std;

int main()
{

//Name display:

cout << "+---------------------------------------------------------+"<<endl;
cout << "|            Computer Science and Engineering             |"<<endl;
cout << "|             CSCE 1030 - Computer Science 1              |"<<endl;
cout << "|   Fatima Shibli    fms0055    FatimaShibli@my.unt.edu   |"<<endl;
cout << "|   Discussed with Samantha paxton and Any Khounnoraj     |"<<endl;
cout << "+---------------------------------------------------------+"<<endl;


 //Declaring size for the hidden and display array
    const int SIZE = 5;

    //Sizes of the 2 arrays
    int hidden_board[SIZE][SIZE];
    int disp_board[SIZE][SIZE];

	//Declared variables for displaying arrays
	int displayed_cord;
	int old_cord;
    int wins = 0;
    int counter = 0;

    //Declaring the variables that will be used in the nested loops for both arrays
    int i;
    int j;
    int randomNum;

    srand(time(NULL));

    char answer = 'Y';
    while ((answer == 'Y') || (answer == 'y')) {
        counter = counter + 1;;
        cout << "The game count is:" << counter << endl;

        //Generates the random integers for the hidden array
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                randomNum = rand() % 25 - 1 + 1 + 1;
                hidden_board[i][j] = randomNum;
            }
        }

        //Generates the -1 masks for the display array
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                disp_board[i][j] = -1;
                cout << disp_board[i][j] << "\t ";
            }
            cout << endl;
        }

        //Variables for entering the coordinates of the array user wants to see
        int coordNum1;
        int coordNum2;

        //Do-while loop to make sure the user enters integers in the range of array
        for(bool valid_coord = false; !valid_coord;){cout << "Enter co-ordinates to reveal a position: ";
        cin >>coordNum1>>coordNum2;
        cout << endl;
        if ((coordNum1 >= 0 && coordNum1 <= 4) && (coordNum2 >= 0 && coordNum2 <= 4))
        {
        valid_coord=true;
        }
        else
        {
        valid_coord=false;
        cout << "Co-ordinates are out of range. Please enter again."<<endl;
        }
        }
        
		//Swapping variables
        char tempVar = hidden_board[coordNum1][coordNum2];
        hidden_board[coordNum1][coordNum2] = disp_board[coordNum1][coordNum2];
        disp_board[coordNum1][coordNum2] = tempVar;
        
        
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                cout << disp_board[i][j] << "\t ";
            }
            cout << endl;

        }

        int tries = 5;
        bool gameWin = false;
		
		
		//Game loop begins
        while ((tries != 0) && (gameWin = true)) {

            int userNum1;
            int userNum2;

            --tries;

            cout << "Guess the coordinates of the matching integer: ";
            cin >> userNum1 >> userNum2;
            cin.ignore();
        
            cout << endl;

            if ((userNum1 >= 0 && userNum1 <= 4) && (userNum2 >= 0 && userNum2 <= 4)) {
                if (hidden_board[userNum1][userNum2] == tempVar)//If user finds correct match 
				{
                    cout << "You guessed correctly.You win!" << " \t" << endl;
                    wins++;
                    cout << "You won " << wins << " times" << endl;
                    gameWin = true;

                    disp_board[userNum1][userNum2] = hidden_board[userNum1][userNum2];
                    cout << endl;

                    for (int i = 0; i < SIZE; i++) {
                        for (int j = 0; j < SIZE; j++) {
                            displayed_cord = disp_board[i][j];
                            cout << disp_board[i][j] << "\t ";
                        }
                        cout << endl;
                    }
                    old_cord = hidden_board[userNum1][userNum2];

                    break;
                } else if (hidden_board[userNum1][userNum2] == -1)//If user selects same point 
				{
                    cout << "You have selected this point before. Please enter again." << endl;
                    cout << "You have " << tries << " guesses remaining." << endl;
                    gameWin = false;
                } else//If user selects wrong point
				{
                    cout << "Incorrect. Please try again." << endl;
                    cout << "You have " << tries << " guesses remaining" << endl;
                    gameWin = false;
                    char temp = hidden_board[userNum1][userNum2];
                    hidden_board[userNum1][userNum2] = disp_board[userNum1][userNum2];
                    disp_board[userNum1][userNum2] = temp;
                }
            } else //Out of range coordinate
			{
                cout << "Selected coordinate is out of range. Please try again." << endl;
                cout << "You have " << tries << " guesses remaining. " << endl;
                cout << endl;
                gameWin = false;
            }

            cout << endl;
			
			//Displays array
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    displayed_cord = disp_board[i][j];
                    cout << disp_board[i][j] << "\t ";
                }
                cout << endl;
            }

        }
		//Ask users if they would like to play again
        cout << "Do you want to play again? Enter 'Y' or 'y' to play again, put any other character to stop: ";
        cin >> answer;
        cin.ignore();
        cout << endl;

    }
	
	//Shows game count and win count
    cout << "The game count is:" << counter << endl;
    cout << "The win count is:" << wins << endl;
	
	//Calculates win percentage
    float percentWin;
    percentWin = static_cast < float > (wins) / counter * 100;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "You won " << percentWin << "%" << " of the game. Goodbye!!!" << endl;

    return 0;
}


