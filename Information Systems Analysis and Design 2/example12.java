public final class Auto extends DopravnyProstriedok implements Naviguj, Parkuj {

    @Override
    public void nastartuj() {
        System.out.println("Auto nastartovane");
    }

    @Override
    public void naviguj() {
        System.out.println("Navigujem");
    }

    @Override
    public void parkuj() {
        System.out.println("Parkujem");
    }
}
