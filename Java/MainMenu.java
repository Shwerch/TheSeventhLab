public enum MainMenu {
    KOCH_CURVE("Кривая Коха"),
    DECODE("Декодирование строки"),
    EXPRESSION_SOLVER("Соединение двузначных чисел знаками + и *"),
    EXIT("Выход из программы");

    private final String description;

    MainMenu(String description) {
        this.description = description;
    }

    public String getDescription() {
        return description;
    }

    public static void printMainMenu() {
        for (int i = 0; i < values().length; i++) {
            System.out.printf("[%d] %s%n", i + 1, values()[i].getDescription());
        }
        System.out.println();
    }

    public static MainMenu fromInt(int i) {
        i -= 1;
        if (i < 0 || i >= values().length) {
            throw new IllegalArgumentException("Некорректный ввод");
        }
        return values()[i];
    }
}
