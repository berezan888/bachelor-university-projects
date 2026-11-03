public class RozsireneZariadenie extends Zariadenie {

    @Override
    protected void stav() {
        if (stav) {
            System.out.println("zariadenie zapnute");
        } else {
            System.out.println("zariadenie vypnute");
        }
    }

    @Override
    public void zapni() {
        stav = true;
    }
}
