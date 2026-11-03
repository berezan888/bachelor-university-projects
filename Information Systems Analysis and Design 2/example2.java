public class Priklad4 {
    public static void main(String[] args) {
        int[][] matica = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        int riadky = matica.length;
        int stlpce = matica[0].length;

        int[] maxVStlpci = new int[stlpce];
        
        for (int j = 0; j < stlpce; j++) {
            int max = matica[0][j]; 
            for (int i = 0; i < riadky; i++) {
                if (matica[i][j] > max) {
                    max = matica[i][j];
                }
            }
            maxVStlpci[j] = max;
        }

        for (int i = 0; i < riadky; i++) {
            for (int j = 0; j < stlpce; j++) {
                matica[i][j] = matica[i][j] - maxVStlpci[j];
            }
        }

        System.out.println("Upravená matica:");
        for (int i = 0; i < riadky; i++) {
            for (int j = 0; j < stlpce; j++) {
                System.out.print(matica[i][j] + "\t");
            }
            System.out.println();
        }
    }
}
