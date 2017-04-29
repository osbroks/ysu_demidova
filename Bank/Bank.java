import java.util.Scanner;

/**
 * Created by hamas on 28.04.17.

 Написать программу, моделирующую работу с вкладами в бан-
 ке. Сведения о каждом вкладе содержат: название, годовой про-
 цент, возможность пополнения счета. Сведения о каждом вклад-
 чике содержат: фамилию, имя, отчество, номер счета, вид вкла-
 да, сумму, дату открытия. Начальное формирование данных
 осуществляется из файла (или файлов). С помощью меню необ-
 ходимо обеспечить следующие функции:
 a) добавление вклада или вкладчика;
 b) удаление вклада или вкладчика;
 c) пополнение счета, если это возможно, по имени вкладчика
 и номеру счета;
 d) снятие процентов с вклада;
 e) закрытие счета с выплатой процентов;
 f) вывод на экран списка вкладчиков, отсортированных по
 фамилии;
 g) вывод на экран списка вкладчиков по заданному диапазо-
 ну размера вклада.

 */
public class Bank {
    public static void main(String[] args) throws Exception {
        System.out.println("hi am bank");

        final Scn innerScn = new Scn(Inner.getInnerFilePath());
        final Scn innScn = new Scn(Inner.getInnFilePath());
        final Scanner scn = new Scanner(System.in);
        int choose;

        String name, sourName, fatherName;
        int vid, summ;
        float gp;
        boolean adding;
//
//        Inner inner = new Inner(name, sourName, fatherName, vid, summ);
//        Inner.Inn inn = inner.new Inn(gp, adding);

        choose = scn.nextInt();
        switch (choose){
            case 1: {
                System.out.println("Добавить вкладчика и вклад");
                name = scn.next();
                sourName = scn.next();
                fatherName = scn.next();
                vid = scn.nextInt();
                summ = scn.nextInt();
                gp = scn.nextFloat();
                adding = scn.nextBoolean();
                Inner inner = new Inner(name, sourName, fatherName, vid, summ);
                Inner.Inn inn = inner.new Inn(gp, adding);
                innerScn.writeInnerToFile(inner);
                innScn.writeInnToFile(inn);
            }
        }
    }
}
