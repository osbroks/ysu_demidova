/**
 * Created by hamas on 20.04.17.
 */
import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

class Main {
    static String filePath = "drob.txt";
    static File file = new File(filePath);
    static ArrayList<Drob> drobs = new ArrayList<>();
    static ArrayList<Drob> ansDrobs = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(file);

        while (scanner.hasNextLine()) {
            Drob drob = new Drob(scanner.nextLine());
            drobs.add(drob);
        }

        for (Drob drob: drobs) {
            System.out.println(drob);
        }

        for (int i = 0; i <= drobs.size(); i++){
            for (int j = i + 1; j < drobs.size(); j++){
                ansDrobs.add(drobs.get(i).summDrob(drobs.get(j)));
            }
        }
        System.out.println(ansDrobs);
    }
}
