public class Base {
    public int a;
     int b;
    private int c;

    public Base() {
        System.out.println("A");
    }

    public Base(int a, int b , int c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }


    public void doIt() {
        System.out.println("B"); // (1)
    }
}

