import java.util.List;

public class Skola<T extends Osoba> {

    protected List<T> personal;

    public String getMeno(int index) {
        return personal.get(index).getMeno();
    }
}
