/**
 * Created by hamas on 28.04.17.
 */
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.File;
import java.io.FileWriter;
import java.util.*;

public class Scn {
    private final String filePath;
    private final File file;
    private List<String> inners = new ArrayList<>();
    private List<String> newInners = new ArrayList<>();
    private List<String> inn = new ArrayList<>();
    private List<String> newInn = new ArrayList<>();
    private FileWriter fileWriter;

    Scn(String filePath){
        this.filePath = filePath;
        file = new File(filePath);
    }

    private void readInnerFile() {
        String date;
        try {
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()){
                date = scanner.nextLine();
                inners.add(date);
            }
            scanner.close();
        } catch (FileNotFoundException ex) {
            System.out.println("File not found" + ex);
        }
    }

    private void readInnFile() {
        String date;
        try {
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()){
                date = scanner.nextLine();
                inn.add(date);
            }
            scanner.close();
        } catch (FileNotFoundException ex) {
            System.out.println("File not found" + ex);
        }
    }

    private void rewriteFile(List<String> list){
        try{
            fileWriter = new FileWriter(file);
            for(String string: list){
                string += "\n";
                fileWriter.write(string);
            }
            fileWriter.close();
        } catch (IOException ex){
            System.out.println(ex);
        }
    }

    void sortBySourName(){
        readInnerFile();
        Collections.sort(inners);
        System.out.println(inners);
    }

    void getPercent(int ID){
        StringBuilder stringBuilder = new StringBuilder();
        String[] innerStrings, innStrings;
        String innerString, innString;
        int percent = 0;
        readInnerFile();
        readInnFile();
        while(inners.iterator().hasNext()){
            innerString = inners.iterator().next();
            innerStrings = innerString.split(",");
            if(Integer.parseInt(innerStrings[0]) == ID){
                while(inn.iterator().hasNext()){
                    innString = inn.iterator().next();
                    innStrings = innString.split(",");
                    if(Integer.parseInt(innStrings[0]) == ID){
                        percent = Integer.parseInt(innStrings[1]);
                    }
                }
                innerStrings[4] = Integer.toString(Integer.parseInt(innerStrings[4]) * percent/100);
                for(String s: innerStrings){
                    if(s == innerStrings[6]){
                        stringBuilder.append(s);
                        innerString = stringBuilder.toString();
                        break;
                    }
                    stringBuilder.append(s).append(',');
                }
            }
            newInners.add(innerString);
        }
        rewriteFile(newInners);
        System.out.println(percent);
    }

    void addSumm(int ID ,int summ) {
        StringBuilder sb = new StringBuilder();
        String[] strings;
        readInnerFile();
        for(String string: inners) {
            strings = string.split(",");
            if(Integer.parseInt(strings[0]) == ID){
                strings[4] = Integer.toString(Integer.parseInt(strings[4]) + summ);
                for(String s: strings){
                    if(s == strings[6]){
                        sb.append(s);
                        string = sb.toString();
                        break;
                    }
                    sb.append(s).append(',');
                }
            }
            newInners.add(string);
        }
        rewriteFile(newInners);
    }

    void deleteInner(int ID) {
        String[] strings;
        readInnerFile();
        for (String string: inners) {
            strings = string.split(",");
            if (Integer.parseInt(strings[0]) != ID) {
                newInners.add(string);
            }
        }
        rewriteFile(newInners);
    }

    void deleteInn(int ID) {
        String[] strings;
        readInnFile();
        for (String string: inn) {
            strings = string.split(",");
            if (Integer.parseInt(strings[0]) != ID) {
                newInn.add(string);
            }
        }
        rewriteFile(newInn);
    }
    void writeInnerToFile(Inner inner) {
         String string = inner.getInnID()+ "," + inner.getSourName() + "," + inner.getName() + ","
                 + inner.getFatherName() + "," + inner. getVid() + "," + inner.getSumm() + ","
                 + inner.getOpenDate() + "\n";
         try {
             fileWriter = new FileWriter(file, true);
             fileWriter.write(string);
             fileWriter.close();
         } catch (IOException ex) {
             System.out.println(ex);
         }

         System.out.println(string);
    }
    void writeInnToFile(Inner.Inn inn) {
        String string = inn.getID() + "," + inn.getGp() + "," + inn.getAdding() + "\n";
        try {
            fileWriter = new FileWriter(file, true);
            fileWriter.write(string);
            fileWriter.close();
        } catch (IOException ex) {
            System.out.println(ex);
        }
        System.out.println(string);
    }
    List<String> getInnersList(){
        return inners;
    }

    List<String> getInnList(){
        return inn;
    }
    @Override
    public String toString(){
        return filePath;
    }
}
