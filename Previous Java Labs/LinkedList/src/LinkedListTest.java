public class LinkedListTest {

    public static void main(String[] args) {

        LinkedList oLinkedList = new LinkedList();
        AirportNode oNode;

        oLinkedList.addNode("SAN");
        oLinkedList.addNode("LAX");

        oNode = oLinkedList.getHeadnode();

        System.out.println("head node: " + oNode.airportID);
        System.out.println("previous node: " + oNode.nextNode.airportID);


    }

}
