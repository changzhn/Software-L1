interface DrawCircle { //绘制圆形
    public void drawCircle(int radius, int x, int y); // 1
}

class RedCircle implements DrawCircle { //绘制红色圆形
    public void drawCircle(int radius, int x, int y) {
        System.out.println("Drawing Circle[red,radius:" + radius + ",x:" + x + ",y:" + y + "]");
    }
}

class GreenCircle implements DrawCircle { //绘制绿色圆形
    public void drawCircle(int radius, int x, int y) {
        System.out.println("Drawing Circle[green,radius:" + radius + ",x: " + x + ",y: " + y + "]");
    }
}
abstract class Shape { //形状
    protected DrawCircle drawCircle; // 2
    public Shape(DrawCircle drawCircle) {
        this.drawCircle = drawCircle;
    }
    public abstract void draw();
}

class Circle extends Shape { //圆形
    private int x, y, radius;
    public Circle(int x, int y, int radius, DrawCircle drawCircle) {
        super(drawCircle); // 3
        this.x = x;
        this.y = y;
        this.radius = radius;
    }
    public void draw() {
        drawCircle.drawCircle(radius, x, y); // 4
    }
}

public class DrawCircleMain {
    public static void main(String[] args) {
        Shape redCircle = new Circle(100, 100, 10, new RedCircle()); //绘制红色圆形 // 5
        Shape greenCircle = new Circle(200, 200, 10, new GreenCircle()); //绘制绿色圆形 // 6
        redCircle.draw();
        greenCircle.draw();
    }
}