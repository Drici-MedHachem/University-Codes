public class Rectangle {
    private double length;
    private double width;


    public Rectangle() {

    }
    public Rectangle(double len , double wid) {
        length = len;
        width = wid;
    }


    public Rectangle(Rectangle rect) {
        length = rect.length;
        width = rect.width;
    }

    public void setLength(double len) {
        if(len <= 0 ) {
            System.out.println("Length can't be negative !");
        } else {
        length = len;
        }
    }
    public void setWidth(double wid) {
        if(wid <= 0) {
            System.out.println("Width can't be negative !");
        } else {
        width = wid;
        }
    }

    public double calculateArea() {
        return (length * width);
    }

    public double calculatePermimeter() {
        return 2*(length + width);  
    }

    public void printInfo() {
        System.out.println("Length = " + length);
        System.out.println("Width = " + width);
        System.out.println("Area = " + calculateArea());
        System.out.println("Perimeter = " + calculatePermimeter());
    }




    public static void main(String[] args) {
        Rectangle r1 = new Rectangle();
        r1.setLength(17);
        r1.setWidth(-1.0);

    }
}

