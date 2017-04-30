/**
 * Created by hamas on 28.04.17.
 */
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Random;

public class Inner {
    private String name, sourName, fatherName, openDate;
    private int innID, vid, summ;
    private static String innerFilePath = "inner.txt";
    private static String innFilePath = "inn.txt";
    Random random = new Random();

    Inner(String name, String sourName, String fatherName, int vid, int summ){
        this.name = name;
        this.fatherName = fatherName;
        this.sourName = sourName;
        this.vid = vid;
        this.summ = summ;
        this.innID = random.nextInt(1000);

        Date date = new Date();
        SimpleDateFormat sdf = new SimpleDateFormat("dd.MM.YYYY hh:mm:ss");
        this.openDate = sdf.format(date);
    }

    int getSumm(){
        return summ;
    }
    int getVid(){
        return vid;
    }
    String getName(){
        return name;
    }
    String getSourName(){
        return sourName;
    }
    String getFatherName(){
        return fatherName;
    }
    String getOpenDate(){
        return openDate;
    }
    int getInnID(){
        return innID;
    }
    static String getInnerFilePath(){
        return innerFilePath;
    }
    static String getInnFilePath(){
        return innFilePath;
    }

    public class Inn {
        private int ID;
        private float gp;
        private boolean adding;

        Inn(float gp, boolean adding){
            this.gp = gp;
            this.adding = adding;
            this.ID = Inner.this.innID;
        }

        public String toString(){
            return Inner.innFilePath;
        }

        public int getID(){
            return ID;
        }

        public float getGp(){
            return gp;
        }

        public boolean getAdding(){
            return adding;
        }
    }

}
