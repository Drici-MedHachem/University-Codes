public class Pyramid {
    public static void main(String[] args) {
        int max = 7;
        int ast = 1;
        int empty = (int)max/2;
        int level = empty + 1;
        for(int i = 0 ; i < level ; i++) {
            String line = "";
            for(int j = 0 ; j < empty ; j++) {
                line += " ";
            }
            for(int k = 0 ; k < ast ; k++) {
                line += "*";
            }
            System.out.println(line);
            empty -= 1;
            ast += 2;
        }
    }
}
