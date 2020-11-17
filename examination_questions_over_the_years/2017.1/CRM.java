abstract class Customer {
    protected String name;
    abstract boolean isNill();
    abstract String getName();
}

class RealCustomer extends Customer {
    public RealCustomer(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public boolean isNill() {
        return false;
    }
}

class NullCustomer extends Customer {
    public String getName() {
        return "Not Avaliable";
    }

    public boolean isNill() {
        return false;
    }
}

class CustomerFactory {
    public String[] names = {"Rob", "Joe", "Julie"};
    public Customer getCustomer(String name) {
        for(int i = 0; i < names.length; i++) {
            if (names[i].equals(name)) {
                return new RealCustomer(names[i]);
            }
        }
        return new NullCustomer();
    }
}

public class CRM {
    public void getCustomer() {
        CustomerFactory cf = new CustomerFactory();
        Customer customer1 = cf.getCustomer("Rob");
        Customer customer2 = cf.getCustomer("Bob");
        Customer customer3 = cf.getCustomer("Julie");
        Customer customer4 = cf.getCustomer("Laura");
        System.out.println("Customers: ");
        System.out.println(customer1.getName());
        System.out.println(customer2.getName());
        System.out.println(customer3.getName());
        System.out.println(customer4.getName());
    }

    public static void main(String[] args) {
        CRM crm = new CRM();
        crm.getCustomer();
    }
}