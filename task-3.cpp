 #include <iostream>
#include <ctime>
#include <random>
#include <stdlib.h>
using namespace std;

char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

void show_board();
void get_X_player_choice();
void get_O_player_choice();
void get_computer_choice();
int count_board(char symbol);
char check_winner();
void computer_vs_player();
void player_vs_player();

int main()
{   cout<<"\t\t W E L C O M E "<<endl;
    cout<<"\t T I C -- T A C -- T O E"<<endl;
    cout<<"1. Computer vs player"<<endl;
    cout<<"2. player1 vs player2"<<endl;
    int ch;
    cout<<"Enter your choice in number(1 or 2)"<<endl;
    cin>>ch;
    switch ( ch)
    {
    case 1:
        computer_vs_player();
        break;
    case 2:
        player_vs_player();
        break;
    
    default: cout<<"INVALID CHOICE";
        break;
    }
    return 0;
}

void get_computer_choice(){
    srand(time(0));
    int choice;
    do
    {
        choice = rand() % 9;
    } while (board[choice] != ' ');
    board[choice] = 'O';
}

char check_winner(){
    // horizontal line
    if(board[0] == board[1] && board[1] == board[2] && board[0] != ' '){
        return board[0];
    }
    if(board[3] == board[4] && board[4] == board[5] && board[3] != ' '){
        return board[3];
    }
    if(board[6] == board[7] && board[7] == board[8] && board[6] != ' '){
        return board[6];
    }
    //vertical line 
     if(board[0] == board[3] && board[3] == board[6] && board[0] != ' '){
        return board[0];
    } 
    if(board[1] == board[4] && board[4] == board[7] && board[1] != ' '){
        return board[1];
    }
     if(board[2] == board[5] && board[5] == board[8] && board[2] != ' '){
        return board[2];
    }
    //diagonal line
     if(board[0] == board[4] && board[4] == board[8] && board[0] != ' '){
        return board[0];
    }
     if(board[2] == board[4] && board[4] == board[6] && board[2] != ' '){
        return board[2];
    }
    //empty palaces
    if(count_board('X') + count_board('O') < 9){
        return 'C';  // c = countinue
    } else{
        return 'D' ; // d = draw
    }
}

void computer_vs_player(){
 
 string player_name;
 cout<<"ENTER YOUR NAME :  ";
 cin>> player_name;
 while ( true)
 {
    system("CLS");
    show_board();
    if(count_board('X') == count_board('O'))
    {
        cout<<player_name<<" turn."<<endl;
        get_X_player_choice();
        }
        else{
            get_computer_choice();
        }
        char winner = check_winner();
        if(winner == 'X')
        {
            system("CLS");
            show_board();
            cout<<player_name<<"won the game"<<endl;
            break;
        }
        else if(winner == 'O')
        {
            system("CLS");
            show_board();
            cout<<"computer won the game."<<endl;
            break;
        }
        else if(winner == 'D'){
            cout<<"game is draw"<<endl;
            break;
        }
 }
 
}


 int count_board(char symbol){
    int total = 0;
    for (int i = 0; i < 9; i++)
    {
        total += (board[i] == symbol);
    }
    return total;
}



void player_vs_player()
{
    string player1_name, player2_name;
    cout << "PLAYER 1, ENTER YOUR NAME: ";
    cin >> player1_name;
    cout << "PLAYER 2, ENTER YOUR NAME: ";
    cin >> player2_name;

    while (true)
    {
        system("CLS");
        show_board();

        if (count_board('X') == count_board('O'))
        {
            cout << player1_name << "'s turn." << endl;
            get_X_player_choice();
        }
        else
        {
            cout << player2_name << "'s turn." << endl;
            get_O_player_choice();
        }

        char winner = check_winner();

        if (winner == 'X')
        {
            system("CLS");
            show_board();
            cout << player1_name << "  won the game." << endl;
            break;
        }
        else if (winner == 'O')
        {
            system("CLS");
            show_board();
            cout << player2_name << "  won the game." << endl;
            break;
        }
        else if (winner == 'D')
        {
            cout << "Game is a draw." << endl;
            break;
        }
    }
}



void get_X_player_choice(){
    while ( true)
    {
        cout<<"select your position(1-9):  ";
        int choice;
        cin>> choice;
        choice--;   // because array indexing starting from 0
        if(choice < 0 || choice > 8){
            cout<<"please select from (1-9) only"<<endl;
        }
        else if(board[choice] != ' '){
            cout<<"please select an empty position"<<endl;
        }
        else{
            board[choice] = 'X';
            break;
        }
    }
    
}
void get_O_player_choice(){
    while ( true)
    {
        cout<<"select your position(1-9):  ";
        int choice;
        cin>> choice;
        choice--;   // because array indexing starting from 0
        if(choice < 0 || choice > 8){
            cout<<"please select from (1-9) only"<<endl;
        }
        else if(board[choice] != ' '){
            cout<<"please select an empty position"<<endl;
        }
        else{
            board[choice] = 'O';
            break;
        }
    }
    
}

void show_board(){


          cout<<"   "<<"    |   "<<"    |   "<<endl;
          cout<<"   "<<board[0]<<"   |   "<<board[1]<<"   |   "<<board[2]<<endl;
          cout<<"   "<<"    |   "<<"    |   "<<endl;
          cout<<"-----------------------"<<endl;
          cout<<"   "<<"    |   "<<"    |   "<<endl;
          cout<<"   "<<board[3]<<"   |   "<<board[4]<<"   |   "<<board[5]<<endl;
          cout<<"   "<<"    |   "<<"    |   "<<endl;
          cout<<"-----------------------"<<endl;
          cout<<"   "<<"    |   "<<"    |   "<<endl;
          cout<<"   "<<board[6]<<"   |   "<<board[7]<<"   |   "<<board[8]<<endl;
          cout<<"   "<<"    |   "<<"    |   "<<endl;
 
}