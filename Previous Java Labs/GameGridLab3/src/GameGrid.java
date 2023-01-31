import java.security.SecureRandom;
import java.util.Scanner;


public class GameGrid {
    void run() {
      int[][] aiGrid = new int[10][10];
  
      int iUserRowX = 0;
      int iUserColY = 0;
      int userChoice;
      boolean gameExit = false;
      Scanner scan1 = new Scanner(System.in);
  
      SecureRandom oRand1 = new SecureRandom();
  
      int iWallChance = 1;
  
      aiGrid[0][iUserRowX] = 0;
  
      for (int y = 0; y < aiGrid[0].length; y++) {
        for (int x = 0; x < aiGrid.length; x++) {
          int iChance = oRand1.nextInt(100);
  
          if (iChance < iWallChance) {
            aiGrid[x][y] = 1;
          } else {
            aiGrid[x][y] = 0;
          }
        }
      }
  
      while (!gameExit) {
        System.out.println("Enter 1 to move down or 2 to move right: ");
        userChoice = scan1.nextInt();
        scan1.nextLine();
  
        if (userChoice == 1) {
          iUserColY = iUserColY + 1;
        } else if (userChoice == 2) {
          iUserRowX = iUserRowX + 1;
        }
  
        if (iUserColY == 9 || iUserRowX == 9) {
          gameExit = true;
          System.out.println("Congrats you made it to the end!");
        }
  
        if (aiGrid[iUserRowX][iUserColY] == 1) {
          gameExit = true;
          System.out.println("You failed");
        }
      }
  
      for (int y = 0; y < aiGrid[0].length; y++) {
        for (int x = 0; x < aiGrid.length; x++) {
          if (x == iUserRowX && y == iUserColY) {
            System.out.print("X");
          } else {
            System.out.print(aiGrid[x][y] + " ");
          }
        }
        System.out.println();
      }
  
      scan1.close();
    }
  }