/**
 * Created by hamas on 20.04.17.
 */
public class Drob {
    private int chislitel;
    private int znamenatel;
    private String drobStr;
    private String CZString[];

    Drob(){}

    Drob(String drobStr) {
        this.drobStr = drobStr;
        getString(drobStr);
        chislitel = Integer.parseInt(CZString[0]);
        znamenatel = Integer.parseInt(CZString[1]);
    }

    private void getString(String drobStr) {
        this.CZString = drobStr.split(" ");
    }

    public int getChislitel(){
        return chislitel;
    }

    public int getZnamenatel(){
        return znamenatel;
    }

    public Drob summDrob(Drob drob){
        Drob newDrob = new Drob();
        System.out.print("Summ: " + this.chislitel + "/" + this.znamenatel +
                            " + " + drob.chislitel + "/" + drob.znamenatel);
        if (this.znamenatel != drob.znamenatel) {
            int a, b;
            newDrob.znamenatel = this.znamenatel * drob.znamenatel;
            a = (newDrob.znamenatel / this.znamenatel) * this.chislitel;
            b = (newDrob.znamenatel / drob.znamenatel) * drob.chislitel;
            newDrob.chislitel = a + b;
            //System.out.println("Summ: " + newDrob.chislitel + "/" + newDrob.znamenatel);
        }
        else {
            newDrob.chislitel = this.chislitel + drob.chislitel;
            newDrob.znamenatel = this.znamenatel;
            //System.out.println("Summ: " + newDrob.chislitel + "/" + newDrob.znamenatel);
        }
        while ((newDrob.chislitel % 2 == 0) && (newDrob.znamenatel % 2 == 0)) {
            newDrob.znamenatel /= 2;
            newDrob.chislitel /= 2;
            //System.out.println("Summ: " + newDrob.chislitel + "/" + newDrob.znamenatel);
        }
        while ((newDrob.chislitel % 5 == 0) && (newDrob.znamenatel % 5 == 0)) {
            newDrob.znamenatel /= 5;
            newDrob.chislitel /= 5;
            //System.out.println("Summ: " + newDrob.chislitel + "/" + newDrob.znamenatel);
        }
        float ans = (float)newDrob.chislitel / (float)newDrob.znamenatel;
        System.out.println(" = " + newDrob.chislitel + "/" + newDrob.znamenatel + ", 0.x: " + ans);
        return newDrob;
    }

    @Override
    public String toString() {
        return this.chislitel + "/" + this.znamenatel;
    }
}
