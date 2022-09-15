import java.lang.Math;
import java.util.Random;

class Tiles_count {
    int tiles(int n, int r, int b, int g) {
        int reached;
        int iterations = 0;
        int limit = Math.min(n, Math.min(b, r));
        int column = limit;
        r = r - limit;
        b = b - limit;
        int count = r + b + g;
        if (count >= limit)
            return limit;
        while (true) {
            iterations++;
            if (column == count) {
                reached = column;
                break;
            } else if (count == column + 1) {
                reached = column;
                break;
            } else if (column == count + 1) {
                reached = count;
                break;
            } else {
                count += 2;
                column--;
            }
        }
        System.out.println(iterations);
        return reached;
    }
}

class Main {
    public static void main(String[] args) {
        Random rand = new Random();
        int n = rand.nextInt(100000) % 100;
        int r = rand.nextInt(100000) % 100;
        int b = rand.nextInt(100000) % 100;
        int g = rand.nextInt(100000) % 100;
        Tiles_count T = new Tiles_count();
        System.out.println("N=" + n + ":B=" + b + ":G=" + g + ":R=" + "" + r);
        System.out.println(T.tiles(n, r, b, g));

    }
}
