import java.util.*;

public class Decoder {
    public static String decodeString(String s) {
        Stack<Integer> counts = new Stack<>();
        Stack<String> resultStack = new Stack<>();
        StringBuilder current = new StringBuilder();
        int k = 0;

        for (char ch : s.toCharArray()) {
            if (Character.isDigit(ch)) {
                k = k * 10 + (ch - '0');
            } else if (ch == '[') {
                counts.push(k);
                resultStack.push(current.toString());
                current = new StringBuilder();
                k = 0;
            } else if (ch == ']') {
                String temp = current.toString();
                current = new StringBuilder(resultStack.pop());
                int repeat = counts.pop();
                current.append(temp.repeat(repeat));
            } else {
                current.append(ch);
            }
        }

        return current.toString();
    }
}
