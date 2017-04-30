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
import java.util.Scanner;

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

        choose = scn.nextInt();
        switch (choose){
            case 1: {
                System.out.println("Добавить вкладчика и вклад");
                System.out.println("Введите имя ");
                name = scn.next();
                System.out.println("Ведите фамилию");
                sourName = scn.next();
                System.out.println("Введите отчество");
                fatherName = scn.next();
                System.out.println("Вид вклада");
                vid = scn.nextInt();
                System.out.println("Сумма вклада");
                summ = scn.nextInt();
                System.out.println("Годовой процент");
                gp = scn.nextFloat();
                System.out.println("Возможность пополнения(true/false)");
                adding = scn.nextBoolean();
                Inner inner = new Inner(name, sourName, fatherName, vid, summ);
                Inner.Inn inn = inner.new Inn(gp, adding);
                innerScn.writeInnerToFile(inner);
                innScn.writeInnToFile(inn);
                break;
            }
            case 2: {
                System.out.println("Удалить вклад и вкладчика");
                int id = scn.nextInt();
                innerScn.deleteInner(id);
                innScn.deleteInn(id);
                break;
            }
            case 3: {
                System.out.println("Пополнить счет по ID");
                int id = scn.nextInt();
                summ = scn.nextInt();
                innerScn.addSumm(id, summ);
                break;
            }
            case 4: {
                System.out.println("Снять проценты с вклада");
                int id = scn.nextInt();
                innerScn.getPercent(id);
                break;
            }
            case 5: {
                System.out.println("Вывод на экран списка вкладчиков, отсортированных по фамилии");
                innerScn.sortBySourName();
                break;
            }
        }
    }
}
