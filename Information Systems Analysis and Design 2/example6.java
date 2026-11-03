public final class Sucet extends Operacia implements VypisVysledok {

    public static int MAX_HODNOTA = 10;

    @Override
    public void spocitaj(int cislo1, int cislo2) {
        super.spocitaj(cislo1, cislo2);

        if (vysledok > MAX_HODNOTA) {
            vysledok = MAX_HODNOTA;
        }
    }

    @Override
    public void vypis() {
        System.out.println(vysledok);
    }
}
