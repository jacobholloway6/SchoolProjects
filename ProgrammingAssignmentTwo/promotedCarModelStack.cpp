#include "promotedCarModelStack.h"
#include <iostream>
#include <stdexcept>
/*

                        Single Programmer Affidavit


   I the undersigned promise that the submitted assignment is my own work. While I was 
   free to discuss ideas with others, the work contained is my own. I recognize that 
   should this not be the case; I will be subject to penalties as outlined in the course 
   syllabus. 

   Name: Jacob Holloway
   Red ID: 827294826

*/
/**
   * @brief push operation, pushing the latest promoted model onto the stack
            Both time and auxiliary space complexity need to be O(1) 
   * @param model 
   * @param price 
   */
void PromotedCarModelStack::push(string model, int price) {


car = PromotedModel(model, price); // Takes in the values and assigns it to the car.
carModels.push_back(car); // Pushes back on the two vectors that track all the cars and the high and low cars
HighLowCarPrices.push_back(car);

            
      if(price > HighLowCarPrices.back().getPromotedPrice()){ // If the price is greater than the highest car it will push in the object with the higher value. 
         
         highCar = HighLowCarPrices.back();
        
      }
      if(lowCar.getPromotedPrice() == -1){

         lowCar = car; // grabs the value from the front of the car model stack and assigns it to low car for function later 
      }

      if(lowCar.getPromotedPrice() > price){

         lowCar = car;

      }
      
      
      if(highCar.getPromotedPrice() < price){

         highCar = car;
         HighLowCarPrices.push_back(highCar);
      }


if(carModels.empty() || HighLowCarPrices.empty()){ 

   throw logic_error("Promoted car model stack is empty"); // throws error is if stacks are emtpy.
  }
   
}

/**
   * @brief pop operation, popping the latest promoted model off the stack
            Both time and auxiliary space complexity need to be O(1) 
   * @param  
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::pop() {
  if(carModels.empty() || HighLowCarPrices.empty()){

   throw logic_error("Promoted car model stack is empty");
  }
  carModels.pop_back();
  HighLowCarPrices.pop_back();
  
  
  car = HighLowCarPrices.back(); 
  

  return PromotedModel(car); // Returns the popped model after assigning it to car. 
}

/**
   * @brief peek operation, peeking the latest promoted model at the top of the stack (without popping)
            Both time and auxiliary space complexity need to be O(1) 
   * @param 
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::peek() {
  if(carModels.empty() || HighLowCarPrices.empty()){

   throw logic_error("Promoted car model stack is empty");
  }
  return PromotedModel(carModels.back()); // Returns the model at the back of the stack
}

/**
   * @brief getHighestPricedPromotedModel, 
   *        getting the highest priced model among the past promoted models
            Both time and auxiliary space complexity need to be O(1)
   * @param 
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::getHighestPricedPromotedModel() {
  if(carModels.empty() || HighLowCarPrices.empty()){

   throw logic_error("Promoted car model stack is empty");
  }
  return PromotedModel(highCar); // From the value earlier it will return the highest priced model when this function is called.
}

/**
   * @brief getLowestPricedPromotedModel, 
   *        getting the lowest priced model among the past promoted models
            Both time and auxiliary space complexity need to be O(1)
   * @param 
   * @return PromotedModel
   */
PromotedModel PromotedCarModelStack::getLowestPricedPromotedModel() {
  if(carModels.empty() || HighLowCarPrices.empty()){

   throw logic_error("Promoted car model stack is empty");
  }
  
  return PromotedModel(lowCar); // returns the lowest priced model 
}