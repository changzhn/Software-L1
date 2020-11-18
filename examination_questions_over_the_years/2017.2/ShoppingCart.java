interface Item {
    public void accept(Visitor visitor);
    public double getPrice();
}

// class Book (1) {
class Book implements Item {
    private double price;
    public Book(double price) {
        // (2);
        this.price = price;
    }
    public void accept(Visitor visitor) { //访问本元素
        // TODO: (3)
        visitor.visit(this);
    }
    public double getPrice() {
        return price;
    }
}

interface Visitor {
    public void visit(Book book);
    //其它物品的visit方法
}

// class Cashier (4) {
class Cashier implements Visitor {
    private double totalForCart;
    //访问Book类型对象的价格并累加
    // (5) {
    public void visit(Book book) {
        //假设Book类型的物品价格超过10元打8折
        if (book.getPrice() < 10.0） {
                totalForCart += book.getPrice();
            } else
                totalForCart += book.getPrice() * 0.8;
        }
        //其它visit方法和折扣策略类似，此处略

        public double getTotal() {
            return totalForCart;
        }
    }
}


class ShoppingCart {
    //normal shopping cart stuff
    private java.util.ArrayList<Item> items = new java.util.ArrayList<>();
    public double calculatePrice() {
        Cashier visitor = new Cashier();

        for (Item item: items) {
            // (6)
            item.accept(visitor);
        }
        double total = visitor.getTotal();
        return total;
    }
    public void add(Item e) {
        this.items.add(e);
    }
}