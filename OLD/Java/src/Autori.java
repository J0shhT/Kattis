import java.util.Scanner;

public class Autori
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        String input = in.nextLine();
        String[] names = input.split("-");
        for (String name : names)
        {
            System.out.print(name.charAt(0));
        }
        System.out.println();
    }
}
