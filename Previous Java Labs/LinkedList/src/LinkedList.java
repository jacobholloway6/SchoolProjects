public class LinkedList {

    private AirportNode headNode;


    //This is for adding to the node, not to remove from the code
    public void  addNode(String sAirportID){

        AirportNode oNode = new AirportNode(); //Makes a new Airport node object

        oNode.airportID = sAirportID; // Takes the string in and sets the AirportID
        oNode.nextNode = headNode; //Makes new node the head node and sets it up to be headnode

        headNode = oNode; // Sets head node to the next node we made
    }



    public AirportNode getHeadnode(){
        return headNode;
    }
}
