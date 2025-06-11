import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            MainMenu.printMainMenu();
            int value = Input.getValue("Введите раздел программы", scanner);
            MainMenu element;
            try {
                element = MainMenu.fromInt(value);
            } catch (IllegalArgumentException e) {
                continue;
            }

            switch (element) {
                case KOCH_CURVE -> {
                    int n = Input.getValue("Введите n", scanner);
                    KochCurve.drawKochCurve(n);
                }
                case DECODE -> {
                    String message = Input.getLine("Введите строку", scanner);
                    message = Decoder.decodeString(message);
                    Output.printString(message);
                }
                case EXPRESSION_SOLVER -> {
                    List<Integer> numbers = Input.getVector("Введите числа через пробел", scanner);
                    int target = Input.getValue("Введите число S", scanner);
                    boolean result = ExpressionSolver.expressionCanFormTarget(numbers, target);
                    Output.printString("Числа" + (result ? " " : " не ") + "могут быть соединены с помощью + и * для получения числа S");
                }
                case EXIT -> {
                    return;
                }
            }
        }
    }
}
