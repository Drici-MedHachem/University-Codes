public class Circle extends Form {
    private double radius;
    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double getSurface() {
        return radius * radius * Form.PI;
    }
}
