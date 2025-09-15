import java.util.*;

public class Input {
    public static void clearInput(Scanner scanner) {
        if (scanner.hasNextLine()) {
            scanner.nextLine();
        }
    }

    public static <T> T getValue(String message, Scanner scanner) {
        while (true) {
            System.out.print(message + ": ");
            try {
                String input = scanner.nextLine();
                return (T) parseValue(input);
            } catch (Exception e) {
                System.out.println("Ошибка ввода. Попробуйте снова.");
            }
        }
    }

    private static Object parseValue(String input) {
        if (input.matches("-?\\d+")) {
            return Integer.parseInt(input);
        }
        return input;
    }

    public static String getLine(String message, Scanner scanner) {
        System.out.print(message + ": ");
        return scanner.nextLine();
    }

    public static List<Integer> getVector(String message, Scanner scanner) {
        while (true) {
            System.out.print(message + ": ");
            String line = scanner.nextLine();
            try {
                List<Integer> result = new ArrayList<>();
                for (String part : line.trim().split("\\s+")) {
                    result.add(Integer.parseInt(part));
                }
                return result;
            } catch (NumberFormatException e) {
                System.out.println("Ошибка ввода. Попробуйте снова.");
            }
        }
    }
}
