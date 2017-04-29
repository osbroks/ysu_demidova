import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Random;

/**
 * Created by hamas on 28.04.17.
 */
public class Inner {
    private String name, sourName, fatherName, openDate;
    private int innID, vid, summ;
    private static String innerFilePath = "inner.txt";
    private static String innFilePath = "inn.txt";
    Random random = new Random();

    Inner(){}

    Inner(String name, String sourName, String fatherName, int vid, int summ){
        this.name = name;
        this.fatherName = fatherName;
        this.sourName = sourName;
        this.vid = vid;
        this.summ = summ;
        this.innID = random.nextInt(100);

        Date date = new Date();
        SimpleDateFormat sdf = new SimpleDateFormat("dd.MM.YYYY hh:mm:ss");
        this.openDate = sdf.format(date);
    }

    public int getSumm(){
        return summ;
    }

    public int getVid(){
        return vid;
    }

    public String getName(){
        return name;
    }

    public String getSourName(){
        return sourName;
    }

    public String getFatherName(){
        return fatherName;
    }

    public String getOpenDate(){
        return openDate;
    }

    public int getInnID(){
        return innID;
    }

    public static String getInnerFilePath(){
        return innerFilePath;
    }

    public static String getInnFilePath(){
        return innFilePath;
    }

    public class Inn {
        private int ID;
        private float gp;
        private boolean adding;

        Inn(){}
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
