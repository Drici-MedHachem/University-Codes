public class Square extends Form {
    private double sideLength;
    public Square(double sideLength) {
        this.sideLength = sideLength;
    }
    @Override
    public double getSurface() {
        return sideLength * sideLength;
    }
}