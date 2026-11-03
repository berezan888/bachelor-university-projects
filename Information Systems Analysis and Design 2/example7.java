public class Pes extends Zviera {

    public Pes() {
        super();
    }

    public Pes(String majitel) {
        super(majitel);
    }

    @Override
    protected boolean jeDomaceZviera() {
        return majitel != null;
    }

    @Override
    public String nakrm() {
        return "";
    }
}
