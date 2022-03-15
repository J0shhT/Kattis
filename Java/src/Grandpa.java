import java.util.ArrayList;
import java.util.Scanner;

public class Grandpa {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.nextLine();

        int white = 0, black = 0;
        char lastCharacter = 0;
        int consecutive = 0;
        ArrayList<String> lines = new ArrayList<>();

        for (int row = 0; row < n; row++) {
            String line = in.nextLine();
            lines.add(line);
            white = 0;
            black = 0;
            lastCharacter = 0;
            consecutive = 0;
            for (int col = 0; col < n; col++) {
                char c = line.charAt(col);
                if (c == lastCharacter) {
                    consecutive++;
                    if (consecutive >= 3) {
                        System.out.println("0");
                        return;
                    }
                }
                if (c == 'W') {
                    white++;
                    lastCharacter = 'W';
                } else if (c == 'B') {
                    black++;
                    lastCharacter = 'B';
                }
            }
        }


        for (int col = 0; col < n; col++) {
            for (int row = 0; row < n; row++) {
                char c = lines.get(col).charAt(col);

            }
        }

    }
}