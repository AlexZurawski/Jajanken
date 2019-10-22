/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstdlib>
//Dungeon crawler program. Escape is the only option.

  int keyX = 0;
  int keyY = 4;
  
  int pitX = 4;
  int pitY = 4;
  
  int torchX = 1;
  int torchY = 2;
  
  int swordX = 4;
  int swordY = 2;
  
  int startX = 2;
  int startY = 2;
  
  int minX = 2;
  int minY = 0;
  
  int doorX = 4;
  int doorY = 0;

  int playerX = startX;
  int playerY = startY;

  bool nWall;
  bool eWall;
  bool sWall;
  bool wWall;

  bool haveTorch = false;
  bool haveSword = false;
  bool haveKey = false;

  bool life = true;

void spaceCheck(){
  if (haveTorch && !haveSword && (((abs(playerX - swordX)) == 1 && (playerY == swordY)) || ((abs(playerY - swordY)) == 1 && (playerX == swordX)))){
    if (playerX + 1 == swordX){
      std::cout << "There is a chest to the East.\n";
    } else if (playerX - 1 == swordX){
      std::cout << "There is a chest to the West.\n";
    } else if (playerY + 1 == swordY){
      std::cout << "There is a chest to the North.\n";
    } else {
      std::cout << "There is a chest to the South.\n";
    }
  }
  
  if (playerX == swordX && playerY == swordY && !haveSword){
    haveSword = true;
    std::cout << "You open a chest and find a sword.\n";
    std::cout << "You are filled with determination.\n";
  }
  
  if (haveTorch && !haveKey && (((abs(playerX - keyX)) == 1 && (playerY == keyY)) || ((abs(playerY - keyY)) == 1 && (playerX == keyX)))){
    if (playerX + 1 == keyX){
      std::cout << "There is a chest to the East.\n";
    } else if (playerX - 1 == keyX){
      std::cout << "There is a chest to the West.\n";
    } else if (playerY + 1 == keyY){
      std::cout << "There is a chest to the North.\n";
    } else {
      std::cout << "There is a chest to the South.\n";
    }
  }
  
  if (playerX == keyX && playerY == keyY && !haveKey){
    haveKey = true;
    std::cout << "You open a chest and find a key.\n";
    std::cout << "You are filled with determination.\n";
  }
  
  if (haveTorch && ((abs(playerX - pitX)) == 1 && (playerY == pitY)) || ((abs(playerY - pitY)) == 1 && (playerX == pitX))){
    if (playerX + 1 == pitX){
      std::cout << "The ground looks shifty to the East.\n";
    } else if (playerX - 1 == pitX){
      std::cout << "The ground looks shifty to the West.\n";
    } else if (playerY + 1 == pitY){
      std::cout << "The ground looks shifty to the North.\n";
    } else {
      std::cout << "The ground looks shifty to the South.\n";
    }
  }
  
  if (playerX == pitX && playerY == pitY){
    std::cout << "The ground falls from beneath you and you fall into a pit of spikes. Better luck next life.\n";
    life = false;
  }

  if (!haveTorch && (((abs(playerX - torchX)) == 1 && (playerY == torchY)) || ((abs(playerY - torchY)) == 1 && (playerX == torchX)))){
    if (playerX + 1 == torchX){
      std::cout << "There is a light to the East.\n";
    } else if (playerX - 1 == torchX){
      std::cout << "There is a light to the West.\n";
    } else if (playerY + 1 == torchY){
      std::cout << "There is a light to the North.\n";
    } else {
      std::cout << "There is a light to the South.\n";
    }
  }
  //Finding torch, can only happen once
  if (playerX == torchX && playerY == torchY && !haveTorch){
    haveTorch = true;
    std::cout << "You find a torch.\n";
    std::cout << "You are filled with determination.\n";
  }
  //Key door escape check
  if (playerX == doorX && playerY == doorY){
    int choice;
    std::cout << "There is a door with a large lock.\nDo you want to try and open it?\n1) Yes\n2) No\n";
    std::cin >> choice;
    
    if (choice == 1){
      if (haveKey){
        std::cout << "You open the door with the key. You have escaped the dungeon!\n";
        life = false;
      } else {
        std::cout << "The door won't budge. It's probably because of the giant lock.\n";
      }
    } else if (choice == 2){
        std::cout << "You leave the door alone for now.\n";
    } else {
      std::cout << "You suddenly die of a brain anurism in an attempt to be clever.\n";
      life = false;
    } 
}
  //Monster door check
  if (playerX == minX && playerY == minY){
    int minChoice;
    std::cout << "There is a door with horns.\nDo you want to try and open it?\n1) Yes\n2) No\n";
    std::cin >> minChoice;
    
    if (choice == 1){
      if (haveSword){
        std::cout << "You open the door and slay the minotaur. You have escaped the dungeon!\n";
        life = false;
      } else {
        std::cout << "You open the door and are skewered by horns. Roll tide.\n";
        life = false;
      }
    } else if (choice == 2){
        std::cout << "You leave the door alone for now.\n";
    } else {
      std::cout << "You suddenly die of a brain anurism in an attempt to be clever.\n";
      life = false;
    } 
}
}
//This section checks to see if the PC is against a wall. If so, movement is restricted.
void wallCheck(){
  if (playerX == 0){
    wWall = true;
    std::cout << "There is a wall to the West.\n";
  } else {
    wWall = false;
  }
  
  if (playerX == 4){
    eWall = true;
    std::cout << "There is a wall to the East.\n";
  } else {
    eWall = false;
  }
  
  if (playerY == 0){
    sWall = true;
    std::cout << "There is a wall to the South.\n";
  } else {
    sWall = false;
  }
  
  if (playerY == 4){
    nWall = true;
    std::cout << "There is a wall to the North.\n";
  } else {
    nWall = false;
  }
}

void movement(){
  int direction;
  std::cout << "Which direction would you like to head?\n";
  std::cout << "8) North\n6) East\n2) South\n4) West\n";
  std::cin >> direction;
  switch(direction){
    case 8:
      if (nWall){
        std::cout << "You cannot venture deeper, as you are blocked by a wall.\n";
        movement();
      } else {
        playerY += 1;
      }
      break;
    case 6:
      if (eWall){
        std::cout << "You cannot venture deeper, as you are blocked by a wall.\n";
        movement();
      } else {
        playerX += 1;
      }
      break;
    case 2:
      if (sWall){
        std::cout << "You cannot venture deeper, as you are blocked by a wall.\n";
        movement();
      } else {
        playerY -= 1;
      }
      break;
    case 4:
      if (wWall){
        std::cout << "You cannot venture deeper, as you are blocked by a wall.\n";
        movement();
      } else {
        playerX -= 1;
      }
      break;
  }
}

int breakcheck(){
  int check;
  std::cin >> check;
  return check;
}

int main(){
  int moves = 0;
  while (moves < 50){
    spaceCheck();
    if (!life){
      break;
      break;
    }
    wallCheck();
    movement();
    std::cout << "(" << playerX << "," << playerY << ")\n";
    moves += 1;
    std::cout << moves << "\n";
  }
}  
  
  