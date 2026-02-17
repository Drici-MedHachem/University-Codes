public class Trianglereverse {
    public static void main(String[] args) {
        for(int i = 1 ; i <= 4 ; i++) {
            String line = "";
            for(int j = 4-i+1 ; j > 0 ; j--) {
                line += "*";
            }
            System.out.println(line);
        }
    }
}