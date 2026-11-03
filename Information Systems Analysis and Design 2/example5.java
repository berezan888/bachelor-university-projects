public class Priklad1 {
    public static void main(String[] args) {
        int den = 1;

        switch (den) {
            case 1:
            case 2:
            case 3:
            case 5:
                System.out.println("pracovný deň");
                break;
            case 4:
                System.out.println("nestránkový deň");
                break;
            case 6:
            case 7:
                System.out.println("zatvorené");
                break;
        }
    }
}
