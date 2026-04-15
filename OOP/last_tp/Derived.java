public class Derived extends Base {
    public int d;
    private int e;

    public Derived() {
        super();
        System.out.println("C");
    }

    public Derived(int a, int b , int c , int d, int e) {
        super(a,b,c);
        this.d = d;
        this.e = e;
    }

    public void doIt() {
        System.out.println("D"); // (3)
        super.doIt();
        ++b;
    }

    public void doIt(int i) {
        System.out.println("E");
        d = 3;
        doIt();  
    }

}
