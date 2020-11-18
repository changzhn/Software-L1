import java.util. ArrayList;
import java.util.List;

interface PaymentMethod {
    // public (1);
    public void pay(int cents);
}

// Cash、DebitCard和Item实现略，Item中getPrice( )获取当前物品对象的价格
// abstract class Card (2) {
abstract class Card implements PaymentMethod {
    private final String name, num;
    public Card(String name, String num) {
        this.name = name;
        this.num = num;
    }

    @Override
    public String toString() {
        return String.format("%s card[name = %s, num = %s]", this.getType(), this.name, this.num);
    }

    @Override
    public void pay(int cents) {
        System.out.println("payed" + cents + " cents using" + toString());
        this.executeTransaction(cents);
    }

    protected abstract String getType();
    protected abstract void executeTransaction(int cents);
}

// class CreditCard (3) {
class CreditCard extends Card {
    public CreditCard(String name, String num) {
        //  (4);
        super(name, num);
    }

    @Override
    protected String getType() {
        return "CREDIT_CARD";
    }

    @Override
    protected void executeTransaction(int cents) {
        System.out.println(cents + " paid using Credit Card.");
    }
}

class Bill {
    private List<Item> items = new ArrayList<Item>();
    public void add(Item item) {
        items.add(item);
    }

    public int getTotalPrice() {}

    public void pay(PaymentMethod paymentMethod) {
        paymentMethod.pay(getTotalPrice());
    }
}

public class PaymentSystem {
    public void pay() {
        Bill bill = new Bill();
    }

    public static void main(String[] args) {
        // (6) payment = new PaymentSystem();
        PaymentSystem payment = new PaymentSystem();
        payment.pay();
    }
}