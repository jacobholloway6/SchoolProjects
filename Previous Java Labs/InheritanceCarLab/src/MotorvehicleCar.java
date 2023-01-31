public class MotorvehicleCar extends Motorvehicle{

    public int doorCount;

    public void start() {
        running = true;
        System.out.println(color);
        System.out.println(doorCount);
        System.out.println(running);
    }

    public void stop(){
        running = false;
        System.out.println(color);
        System.out.println(doorCount);
        System.out.println(running);
    }
}
