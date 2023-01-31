public class VehicleManager {

    public static void run(){

        Motorcycle[] groupCycles = new Motorcycle[3];
        MotorvehicleCar[] groupCars = new MotorvehicleCar[3];

        Motorcycle cycleOne = new Motorcycle();
        Motorcycle cycleTwo = new Motorcycle();
        Motorcycle cycleThree = new Motorcycle();

        MotorvehicleCar carOne = new MotorvehicleCar();
        MotorvehicleCar carTwo = new MotorvehicleCar();
        MotorvehicleCar carThree = new MotorvehicleCar();

        cycleOne.running = false;
        cycleTwo.running = false;
        cycleThree.running = false;

        cycleOne.color = "Red";
        cycleTwo.color = "Blue";
        cycleThree.color = "Orange";

        carOne.running = false;
        carTwo.running = false;
        carThree.running = false;

        carOne.color = "Yellow";
        carTwo.color = "Pink";
        carThree.color = "Light Blue";

        groupCycles[0] = cycleOne;
        groupCycles[1] = cycleTwo;
        groupCycles[2] = cycleThree;

        groupCars[0] = carOne;
        groupCars[1] = carTwo;
        groupCars[2] = carThree;

        System.out.println("Select a car to choose from");
        

    }
}
