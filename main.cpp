/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stdlib.h>
  // Rock-Paper-Scissor-Lizard-Spock
  // Too many rules to describe

int usersChoice(){
  int choice;  
  std::cout << "Choose your weapon!\n";
  std::cout << "1) Rock\n";
  std::cout << "2) Paper\n";
  std::cout << "3) Scissors\n";
  std::cout << "4) Lizard\n";
  std::cout << "5) Spock\n";
  std::cin >> choice;
  
  if (choice > 0 and choice <= 5){
    if (choice == 4){
      return 5;
    } else if (choice == 5){
      return 4;
    } else {
      return choice;
    }
  } else {
    std::cout << "Invalid choice. Try Again.\n";
    usersChoice();
  }
}

std::string usersWeapon(int choice){
  switch(choice){
  case 0:
      return "Rock!";
      break;
  case 1:
      return "Paper!";
      break;
  case 2:
      return "Scissors!";
      break;
  case 3:
      return "Spock!";
      break;
  case 4:
      return "Lizard!";
      break;
  }
}

int main(){
  // I will die before watching Big Bang
  int userChoice;
  int computerChoice;
  std::string userWeapon;
  std::string compWeapon;
  
  srand (time(NULL));
  computerChoice = rand() % 5;
  userChoice = usersChoice() - 1;
  
  userWeapon = usersWeapon(userChoice);
  compWeapon = usersWeapon(computerChoice);
  
  std::cout << "Player has chosen: " << userWeapon << "\n";
  std::cout << "Computer has chosen: " << compWeapon << "\n";
  
  if (userChoice > computerChoice){
    computerChoice += 5;
  }
  
  if (computerChoice == userChoice){
    std::cout << "It's a Draw!\n";
  } else if ((computerChoice - userChoice) % 2 == 0){
    std::cout << "Player wins!\n";
  } else {
    std::cout << "Computer wins!\n";
  }
}