public class Priklad5 {
    public static void main(String[] args) {
        Autor autor1 = new Autor("Anna");
        Autor autor2 = new Autor("Peter");
        Autor autor3 = new Autor("Zuzana");

        Publikacia publikacia1 = new Publikacia("Kniha A");
        Publikacia publikacia2 = new Publikacia("Kniha B");

        publikacia1.autori = new Autor[]{autor1};
        autor1.publikacie = new Publikacia[]{publikacia1};

        publikacia2.autori = new Autor[]{autor2, autor3};
        autor2.publikacie = new Publikacia[]{publikacia2};
        autor3.publikacie = new Publikacia[]{publikacia2};
    }
}

class Autor {
    String meno;
    Publikacia[] publikacie;

    public Autor(String meno) {
        this.meno = meno;
    }
}

class Publikacia {
    String nazov;
    Autor[] autori;

    public Publikacia(String nazov) {
        this.nazov = nazov;
    }
}
