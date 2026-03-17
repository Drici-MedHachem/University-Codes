public class Triangle {
    public static void main(String[] args) {
        for(int i = 1 ; i <= 4 ; i++) {
            String line = "";
            for(int j = 0 ; j < i ; j++) {
                line += "*";
            }
            System.out.println(line);
        }
    }
}
