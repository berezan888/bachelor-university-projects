public final class Administrator extends Pouzivatel implements ZmenHeslo {

    public static Administrator spravca = new Administrator();

    protected Administrator() {
        this.heslo = "admin";
    }

    @Override
    public void zmenHeslo(Pouzivatel pouzivatel, String noveHeslo) {
        pouzivatel.heslo = noveHeslo;
    }
}
