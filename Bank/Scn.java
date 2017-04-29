/**
 * Created by hamas on 28.04.17.
 */
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.List;
import java.util.Scanner;

public class Scn {
    private String filePath;
    private File file;
    private String date;
    private List<String> inners;
    private FileWriter fileWriter;
    private FileReader fileReader;

    Scn(String filePath){
        this.filePath = filePath;
        file = new File(filePath);
    }

    public void writeInnerToFile(Inner inner) {
         String string = inner.getInnID()+ "," + inner.getSourName() + "," + inner.getName() + ","
                 + inner.getFatherName() + "," + inner. getVid() + "," + inner.getSumm() + ","
                 + inner.getOpenDate() + ";" + '\n';
         try {
             this.fileWriter = new FileWriter(file, true);
             this.fileWriter.write(string);
             this.fileWriter.close();
         } catch (IOException ex) {
             System.out.println(ex);
         }

         System.out.println(string);
    }

    public void writeInnToFile(Inner.Inn inn) {
        String string = inn.getID() + "," + inn.getGp() + "," + inn.getAdding() + ";"  + '\n';
        try {
            this.fileWriter = new FileWriter(file, true);
            this.fileWriter.write(string);
            this.fileWriter.close();
        } catch (IOException ex) {
            System.out.println(ex);
        }
        System.out.println(string);
    }

    public void readFile(){
        try {
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()){
                date = scanner.nextLine();
                inners.add(date);
            }
        } catch (FileNotFoundException ex) {
            System.out.println("File not found" + ex);
        }

    }

    public List<String> getInnersList(){
        return inners;
    }

    @Override
    public String toString(){
        return filePath;
    }
}
