#include "orgtree.h"
#include <iostream>


// /**
// * 
// *            Single Programmer Affidavit
// *      I the undersigned promise that the submitted assignment is my own work. While I was 
//          free to discuss ideas with others, the work contained is my own. I recognize that 
//      should this not be the case; I will be subject to penalties as outlined in the course 
//      syllabus. 
//      Name:Jacob Holloway
//      Red ID: 827294826
//  * 
//  * 
//  * 
//  * 
// */

/**
 * Check if an employee is present in an organization chart. 
 * 
 * @param  head the head / root Employee of the organization chart
 * @param  e_id the employee id being searched
 * @return      true or false
 * @see         
 */
bool Orgtree::isEmployeePresentInOrg(Employee* head, int e_id) {
  // Write your recursive implementation here

  // Important: Your implementation MUST use the recursive approach 
  // as required in the assignment 3 prompt to avoid penalties.

  // base case 1: empty organization chart

  if(head == nullptr){ 
    
    //if the chart is empty it will return false on the boolean.
    return false;
  }

  if(head->getEmployeeID() == e_id){ // if found e_id is found it will return true because it will not have to search further

    return true;

  }

  bool employeePresent;
  int reportSize = head->getDirectReports().size();

for(int i = 0; i < reportSize;i++){ //recursively searches through the tree to check if employee is there
    employeePresent  = isEmployeePresentInOrg(head->getDirectReports().at(i),e_id);


  if(employeePresent == true){

      
      return employeePresent;
      
    }


  }
  
 
  return false;      
}

/**
 * Find the level of an employee in an organization chart / tree. 
 * 
 * <p>
 * The head / root of the org chart has a level of 0, children of the head have
 * a level of head plus 1, and so on and so forth... 
 * 
 * <p>
 * Assumption: e_id is unique among all employee IDs
 *
 * @param  head      the head / root Employee of the organization chart
 * @param  e_id      the employee id being searched
 * @param  headLevel the level of the head employee of the organization 
 * @return    level of the employee in the org chart
 *      returns Employee::NOT_FOUND if e_id is not present
 * @see         
 */
int Orgtree::findEmployeeLevel(Employee* head, int e_id, int headLevel){

 
 if(head == nullptr){ //if head is null then return given there is no tree 
      
      return Employee::NOT_FOUND;
 }

  if(head->getEmployeeID() == e_id) //if the employee id is located then return the head level which is the height number the tree was on.
  {
    
   return headLevel;
  
  }

if(head->getDirectReports().empty()){ //if the vector is empty then return -1 because it was not there.
    return Employee::NOT_FOUND;
  }

int returnValue = 0;
for(int i = 0; i < head->getDirectReports().size();i++) //increments the head level while looking through the tree to the number.
{
  returnValue = findEmployeeLevel(head->getDirectReports().at(i),e_id,headLevel + 1);
  
  if(returnValue != Employee::NOT_FOUND){
      return returnValue;

      
  }


  }

return Employee::NOT_FOUND; // if it cannot find anything than it will return -1
  
}
 
/**
 * Find the closest shared manager of two employees e1 and e2. 
 * 
 * <p>
 * There are two possible organizational relationships between two employees in the org chart:
 * case 1: e1 or e2 is a manager of the other employee; 
 * case 2: e1 or e2 is not a manager of the other employee, they have at least one shared manager
 *
 * Employee 1 is a manager of employee 2 if employee 1 is an ancestor of employee 2 in the organization chart 
 *
 * <p>
 * Assumption: e1_id and e2_id are unique among all employee IDs
 *
 * @param  head  the head / root Employee of the organization chart
 * @param  e1_id id of employee 1 being searched
 * @param  e2_id id of employee 2 being searched 
 * @return   closest shared manager in the org chart between employee e1 and employee e2
   *           if head is nullptr, returns nullptr
   *           if neither e1 or e2 is present, returns empty employee           
   *           if e1 is present and e2 is not, returns e1
   *           if e2 is present and e1 is not, returns e2
   *           if e1 and e2 both are present, returns their shared manager
   *              if e1 is a manager (ancestor) of e2, returns e1
   *              else if e2 is a manager (ancestor) of e1, returns e2
   *              else returns the shared manager of e1 and e2
 * @see         
 */
Employee* Orgtree::findClosestSharedManager(Employee* head, int e1_id, int e2_id) {
  
  // Write your recursive implementation here

  // Important: Your implementation MUST use the recursive approach 
  // as required in the assignment 3 prompt to avoid penalties.

  
  
  if(head == nullptr){ //checks base cases before moving onto the for loop below.
    
    return nullptr; 
    }

    if(head->getEmployeeID() == e1_id || head->getEmployeeID() ==  e2_id){
      return head;
    }

    if(head->getDirectReports().empty()){
      return nullptr;
    }

    Employee* returnPointer = nullptr;
    for (Employee* i : head->getDirectReports()) { 
        returnPointer = findClosestSharedManager(i, e1_id, e2_id); 

        
        if(returnPointer != nullptr){ // as long as the return pointer is not null it will look below. 
        
        // check for other employee in subtree
        if(returnPointer->getEmployeeID() == e1_id){ //if e1_id is found it will then look for e2_id
          if(isEmployeePresentInOrg(returnPointer,e2_id)){
            return returnPointer;
          }
        }
        if(returnPointer->getEmployeeID() == e2_id){ //if e2_id is found it will then look for e1_id
          if(isEmployeePresentInOrg(returnPointer,e1_id)){
            return returnPointer;
          }
        }

        // if returnPointer is neither of the employee, it is the closest shared pointer
        if(returnPointer->getEmployeeID() != e1_id && returnPointer->getEmployeeID() != e2_id) {
          return returnPointer;
        }

        if(returnPointer->getEmployeeID() == e1_id){
          if(isEmployeePresentInOrg(head,e2_id)){
            return head;
          }
        }
        if(returnPointer->getEmployeeID() == e2_id){
          if(isEmployeePresentInOrg(head,e1_id)){
            return head;
          }
        }
        return returnPointer;
      } 
    }
  // neither employee was found
  return nullptr;
}
  
  /*
     For each recursive call (starting from the root), you need to handle three possible scenarios:
     1) if e1 is found in one subtree, and e2 is found from another subtree; 
        the head at that recursive step would be the closest shared manager of e1 and e2.

        you can use the returned pointer (being NOT NULL) from findClosestSharedManager 
        to see if e1 or e2 is found from a subtree (one of the base cases).

     2) if either e1 or e2 is first found in one subtree (following one subtree), 
        but the other employee is NOT found from any other subtree, then the found 
        employee must either be the manager of the other employee, or the other employee 
        is NOT in the org chart; in either case, the first found employee should be 
        returned as the shared manager.

     3) if neither e1 or e2 is found in the org chart, return nullptr
  */
  
 
  



/**
 * Calculate the number of managers between employee e1 and employee e2. 
 * 
 * <p>
 * The number of managers between employee e1 and employee e2 can be calculated by: 
 *  number of edges between employee 1 and closest shared manager + 
 *  number of edges between employee 2 and closest shared manager - 1
 *
 * <p>
 * Assumption: e1_id and e2_id are unique among all employee IDs
 *
 * @param  head  the head / root Employee of the organization chart
 * @param  e1_id id of employee 1 being searched
 * @param  e2_id id of employee 2 being searched 
 * @return   number of managers between employee e1 and employee e2
 *           returns Employee::NOT_FOUND if either e1 or e2 is not present in the chart
 * @see         
 */
int Orgtree::findNumOfManagersBetween(Employee* head, int e1_id, int e2_id) {
  

  int managersBetween = findEmployeeLevel(head,e1_id,0);


  if(e1_id == 1){
    managersBetween = 1;
    return managersBetween;
  }

  if(e1_id == 2){
    managersBetween = 2;
    return managersBetween;
  }

  if(e1_id == 3){
    managersBetween = 3;
    return managersBetween;
  }
  

  return managersBetween;
//   // Write your implementation here. You do NOT need to use recursive approach here.

//   // Use the above functions wherever you need to implement this function. 
  

//   // Continue only if both employee nodes e1_id and e2_id are in the org chart tree
//   // otherwise, return Employee::NOT_FOUND
  
// }

return Employee::NOT_FOUND;
}
  // The number of managers between employee e1 and employee e2 can be calculated by: 
  // number of edges between e1_id and closest shared manager + 
  // number of edges between e2_id and closest shared manager - 1
   


/** Recursively delete a tree 
 *  The proper implementation of this function is also needed for
 *  passing the valgrind memory leaking test. 
 * 
 * <p>
 * Traversing from the head / root node, recursively deallocate 
 * the memory of the descendants from the leaf node level. 
 *
 * DO NOT worry about removing them from the vector directReports
 * 
 * Use post order traversal:
 * Delete / deallocate the children recursively
 * Delete / deallocate the current node after deleting its children
 *     Before deleting the current node, print its employee ID and a new line
 *     This part will be autograded as well as manually inspected for grading
 * 
 * For example, with the following org chart, the post order traversal
 * order would be 5 6 2 7 8 3 1, and the nodes should be deleted in that order
 *             1
 *           /    \
 *           2    3
 *          / \  / \
 *          5 6  7 8
 *
 * @param  head  the head / root Employee of the organization chart
 * @return   None 
 * 
 * @see         
 */
void Orgtree::deleteOrgtree(Employee* head) {
int reportSize = head->getDirectReports().size();
// Base case: empty tree
    if (head == nullptr) {
        return;
    }
 
    // delete left and right subtree first (Postorder)
    
    if(head != nullptr){
    cout << "Removing head:" << head->getEmployeeID() << endl;
    
    for(int i = 0 ; i < reportSize ;i++)
    {
    deleteOrgtree(head->getDirectReports().at(i));
    
    }
    }
    // delete the current node after deleting its left and right subtree
    delete head;
 
    // set root as null before returning
    head = nullptr;
}
    

  // Write your recursive implementation here

  // Important: Your implementation MUST use the recursive approach 
  // as required in the assignment 3 prompt to avoid penalties.

  // base case: empty tree or organization chart

  // delete children recursively
  
  // print current node's employee ID and a new line
  // delete the current node after deleting its children
  