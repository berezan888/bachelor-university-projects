public class Priklad2 {
    public static void main(String[] args) {
        int[] cisla = {5, 3, 8, 3, 9, 1, 3, 7};
        int hodnota = 3;
        int index = -1;
        int pocetVyskytov = 0;
        for (int i = 0; i < cisla.length; i++) {
            if (cisla[i] == hodnota) {
                pocetVyskytov++;
                if (pocetVyskytov == 2) {
                    index = i;
                    break;
                }
            }
        }
        System.out.println("Hľadaná hodnota: " + hodnota);
        System.out.println("Index druhého výskytu: " + index);
    }
}
