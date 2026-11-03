public final class RozsirenySubor extends Subor implements RozsireneOperacie {

    @Override
    public void zapis() {
        System.out.println("Zapisujem subor");
    }

    @Override
    public void zmaz() {
        System.out.println("Mazem subor");
    }

    @Override
    public void presun(String adresar) {
        System.out.println("Presuvam subor do adresara " + adresar);
    }
}
