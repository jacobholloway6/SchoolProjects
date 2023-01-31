#include "sortcar.h"
#include <iostream>   
#include <vector>

/**
 * @brief sort car inventory
 * 
 * @param carInventory      input car inventory array
 * @param promotionOrder    car promotion order
 * @return vector<string>   sorted car inventory according to the car promotion order
 * 
 * Time complexity has to be linear: O(N), N is the size/length of the input car inventory array
 * Space complexity has to be constant: O(1), hint: sorting can be done by mutating the input car inventory array.
 * 
 * 
 * I the undersigned promise that the submitted assignment is my own work. While I was 
 * free to discuss ideas with others, the work contained is my own. I recognize that 
 * should this not be the case; I will be subject to penalties as outlined in the course 
 * syllabus. 
 * Name: Jacob Holloway
 * Red_ID: 827294826
 **/



int partition(vector<string>& carInventory, int lowIndex, int highIndex, string promo) //takes in the vector as reference along with the high and low index 
{
   // Pick middle element as pivot
   int midpoint = lowIndex + (highIndex - lowIndex) / 2; // in this case we should set the mid point of our vector car inventory
   string pivot = carInventory[midpoint]; //this is where we should be able to pass in the string we want as the pivot converts 
   
   //cout << "Pivot:" << pivot << " Car Inventory Low: " << carInventory[lowIndex]  << " Car Promo at 0:" << carPromo.at(0) <<  endl;
   
   bool done = false;
   while (!done) {
    
      while (carInventory[lowIndex] < pivot) { 
         lowIndex += 1; //compares the lowIndex to the pivot and adds +1 if its less than
         
      }
      
      
      while (pivot < carInventory[highIndex]) { 
         highIndex -= 1;
         
      }
      
      // If zero or one elements remain, then while loop exits 
      if (lowIndex >= highIndex) {
         done = true; 
      }
      else {
         
         string temp = carInventory[lowIndex]; // need a temp string to hold the value in place 
         carInventory[lowIndex] = carInventory[highIndex]; // the value at the top goes to the bottom 
         carInventory[highIndex] = temp; //value at the bottom goes to the top. 
         
         // Update lowIndex and highIndex
         lowIndex += 1; //pushes along the indexes
         highIndex -= 1;
      }
      
   }
    
   return highIndex; // returns the top of the index 
}

void quicksort(vector<string>& carInventory, int lowIndex, int highIndex, string promo) //quick sort takes in the array, low, and high.
{
   // Base case: If the partition size is 1 or zero 
   // elements, then the partition is already sorted
   if (lowIndex >= highIndex) {
      return;
   }
   
   // Partition the data within the array. Value lowEndIndex 
   // returned from partitioning is the index of the low 
   // partition's last element.
   int lowEndIndex = partition(carInventory, lowIndex, highIndex, promo); // if the array is not sorted it goes to partition it. 
   
  
   // Recursively sort low partition (lowIndex to lowEndIndex) 
   // and high partition (lowEndIndex + 1 to highIndex)
   quicksort(carInventory, lowIndex, lowEndIndex, promo );
   quicksort(carInventory,  lowEndIndex + 1, highIndex, promo);
}

vector<string> SortCar::sortCarInventory(vector<string> carInventory, vector<string> promotionOrder) {
   string carPromo = promotionOrder.at(0);

   quicksort(carInventory, 0, carInventory.size() - 1, carPromo);
  

    return carInventory;
}
  
