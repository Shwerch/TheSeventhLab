import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class KochCurve extends Application {
    private static int iterations = 0;
    private static final double WIDTH = 800;
    private static final double HEIGHT = 600;

    public static void drawKochCurve(int n) {
        iterations = Math.max(n, 0);
        Application.launch();
    }

    @Override
    public void start(Stage stage) {
        Canvas canvas = new Canvas(WIDTH, HEIGHT);
        GraphicsContext gc = canvas.getGraphicsContext2D();
        gc.setStroke(Color.BLACK);

        double x1 = 100;
        double y1 = HEIGHT / 2;
        double x2 = WIDTH - 100;
        double y2 = HEIGHT / 2;

        drawSegment(gc, x1, y1, x2, y2, iterations);

        StackPane root = new StackPane(canvas);
        Scene scene = new Scene(root);
        stage.setTitle("Koch Curve");
        stage.setScene(scene);
        stage.show();
    }

    private void drawSegment(GraphicsContext gc, double x1, double y1, double x2, double y2, int depth) {
        if (depth == 0) {
            gc.strokeLine(x1, y1, x2, y2);
            return;
        }

        double dx = (x2 - x1) / 3.0;
        double dy = (y2 - y1) / 3.0;

        double x3 = x1 + dx;
        double y3 = y1 + dy;
        double x5 = x2 - dx;
        double y5 = y2 - dy;

        double angle = Math.toRadians(60);
        double x4 = x3 + (dx * Math.cos(angle) - dy * Math.sin(angle));
        double y4 = y3 + (dx * Math.sin(angle) + dy * Math.cos(angle));

        drawSegment(gc, x1, y1, x3, y3, depth - 1);
        drawSegment(gc, x3, y3, x4, y4, depth - 1);
        drawSegment(gc, x4, y4, x5, y5, depth - 1);
        drawSegment(gc, x5, y5, x2, y2, depth - 1);
    }
}
