public class Dom {

    public void zapni(String zariadenie) {
        if (zariadenie == null) {
            throw new NullPointerException();
        }

        if (zariadenie.equals("vykurovanie")) {
            throw new IllegalStateException();
        }
    }

    public void vypni(String zariadenie) {
        System.out.println("Vypinam " + zariadenie);
    }

    public static void main(String args[]) {
        Dom dom = new Dom();

        try {
            dom.zapni("svetlo");
            dom.zapni("vykurovanie");
        } catch (IllegalStateException e) {
            dom.vypni("vykurovanie");
        } catch (NullPointerException e) {
            System.out.println("zariadenie nemoze byt null");
        } finally {
            System.out.println("koniec inicializacie");
        }
    }
}
