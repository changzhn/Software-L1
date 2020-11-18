interface DrawCircle { //绘制圆形
    // public (1);
    public void drawCircle(int radius, int x, int y);
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
    // protected (2)
    protected DrawCircle drawCircle;
    public Shape(DrawCircle drawCircle) {
        this.drawCircle = drawCircle;
    }
    public abstract void draw();
}

class Circle extends Shape { //圆形
    private int x, y, radius;
    public Circle(int x, int y, int radius, DrawCircle drawCircle) {
        // (3)
        super(drawCircle);
        this.x = x;
        this.y = y;
        this.radius = radius;
    }
    public void draw() {
        // drawCircle.(4)
        drawCircle.drawCircle(radius, x, y);
    }
}

public class DrawCircleMain {
    public static void main(String[] args) {
        // Shape redCircle = new Circle(100, 100, 10, (5)); //绘制红色圆形
        Shape redCircle = new Circle(100, 100, 10, new RedCircle()); //绘制红色圆形
        // Shape greenCircle = new Circle(200, 200, 10, (6)); //绘制绿色圆形 
        Shape greenCircle = new Circle(200, 200, 10, new GreenCircle()); //绘制绿色圆形
        redCircle.draw();
        greenCircle.draw();
    }
}