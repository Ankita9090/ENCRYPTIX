#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main() {

      srand(time(0));
      int number;
      
      number = rand() % 100 + 1;

      int guess;
      cout<<"\t\t WELCOME TO NUMBER GUESSING GAME \n\n";
      cout<<" enter the number between 1 and 100:\n";

      do {
            cin >> guess;
            if (guess < number)

            cout << "Your estimate is less, than the secret number" << endl;
            else if (guess > number)

            cout << "Your estimate is more, than the secret number" << endl;
            else

            cout << "Your guess is right!" << endl;
            } while (guess != number);

            system("PAUSE");

            return 0;

         }