public class Motorcycle extends Motorvehicle{

    public boolean windshield;

    public void start() {
        running = true;
        System.out.println(color);
        System.out.println(windshield);
        System.out.println(running);
    }

    public void stop(){
        running = false;
        System.out.println(color);
        System.out.println(windshield);
        System.out.println(running);
    }
}
