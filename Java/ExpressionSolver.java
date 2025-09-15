import java.util.*;

public class ExpressionSolver {
    private static boolean dfsAll(List<Integer> nums, int index, int currentValue, int target) {
        if (index == nums.size()) {
            return currentValue == target;
        }

        int next = nums.get(index);
        return dfsAll(nums, index + 1, currentValue + next, target) ||
               dfsAll(nums, index + 1, currentValue * next, target);
    }

    public static boolean expressionCanFormTarget(List<Integer> numbers, int target) {
        if (numbers.isEmpty()) return false;
        return dfsAll(numbers, 1, numbers.get(0), target);
    }
}
