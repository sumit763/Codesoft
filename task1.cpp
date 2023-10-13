# include<iostream>
# include<ctime>
using namespace std;

int main(){
    int random , guess;
    srand(static_cast<unsigned int>(time(0)));
    random = rand() %100;
    do
    {
      cout<<"Guess a number (1-99)"<<endl;
      cin>>guess;
      if ( guess > random )
      {
        cout<<"Far from number guess again"<<endl;
        cout<<"hint: guess smaller"<<endl;
      }
      else if ( guess < random)
      {
        cout<<"Far from number guess again"<<endl;
        cout<<"hint: guess larger"<<endl;
      } 
    } while (guess!= random);
    cout<<"Bingo! right guess";
    return 0;
}