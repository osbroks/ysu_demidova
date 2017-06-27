package lab8;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.scene.control.*;

/**
 * Created by hamas on 27.06.17.
 */
public class Controller {
    public Label labelTable;
    public ListView<String> multiplyTable = new ListView<String>();

    public void button_1(ActionEvent actionEvent) {
        labelTable.setText("1");
    }

    public void button_2(ActionEvent actionEvent) {
        labelTable.setText("2");
    }

    public void button_3(ActionEvent actionEvent) {
        labelTable.setText("3");
    }

    public void button_4(ActionEvent actionEvent) {
        labelTable.setText("4");
    }

    public void button_5(ActionEvent actionEvent) {
        labelTable.setText("5");
    }

    public void button_6(ActionEvent actionEvent) {
        labelTable.setText("6");
    }

    public void button_7(ActionEvent actionEvent) {
        labelTable.setText("7");
    }

    public void button_8(ActionEvent actionEvent) {
        labelTable.setText("8");
    }

    public void button_9(ActionEvent actionEvent) {
        labelTable.setText("9");
    }

    public void button_ok(ActionEvent actionEvent) {
        String str;
        int num = Integer.valueOf(labelTable.getText());
        ObservableList<String> items = FXCollections.observableArrayList();
        for (int i = 1; i <= 9; i++) {
            str = num + " * " + i + " = " + (num * i);
            items.add(str);
        }
        multiplyTable.setItems(items);
    }
}
