public class Pes {

    public void aport(String predmet) {
        if (predmet == null) {
            throw new NullPointerException();
        }

        if (predmet.equals("topanka")) {
            throw new IllegalArgumentException();
        }
    }

    public void sadni() {
        System.out.println("Sadni");
    }

    public static void main(String args[]) {
        Pes pes = new Pes();

        try {
            pes.aport("topanka");
        } catch (NullPointerException e) {
            pes.sadni();
        } catch (IllegalArgumentException e) {
            System.out.println("toto nebudem aportovat");
        } finally {
            System.out.println("hav");
        }
    }
}
