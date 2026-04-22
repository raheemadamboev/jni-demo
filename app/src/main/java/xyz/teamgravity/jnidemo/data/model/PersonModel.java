package xyz.teamgravity.jnidemo.data.model;

public class PersonModel {

    private final String name;
    final int age;
    public final boolean isMarried;
    protected double debt;

    private static String STATUS;
    private static double BUDGET = 500.0;

    public PersonModel(String name, int age, boolean isMarried, double debt) {
        this.name = name;
        this.age = age;
        this.isMarried = isMarried;
        this.debt = debt;
        STATUS = isMarried ? "Married" : "Single";
        BUDGET -= debt;
    }

    public PersonModel(String name) {
        this.name = name;
        age = 0;
        isMarried = false;
        debt = 0;
        STATUS = "Single";
        BUDGET = 0;
    }

    public void print() {
        System.out.println(this);
    }

    public String agePeriod() {
        if (age > 50) {
            return "Elder";
        } else if (age > 30) {
            return "Midlife";
        } else if (age > 20) {
            return "Prime";
        } else if (age > 10) {
            return "Adolescence";
        } else {
            return "Kid";
        }
    }

    public static void evaluate(final PersonModel person) {
        System.out.println(person);
    }

    public static void bankrupt(final PersonModel person) {
        BUDGET = 0;
        person.debt = 10000.0;
    }

    @Override
    public String toString() {
        return "PersonModel{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", isMarried=" + isMarried +
                ", debt=" + debt +
                ", STATUS=" + STATUS +
                ", BUDGET=" + BUDGET +
                '}';
    }

    public class Book {

        static {
            System.loadLibrary("person_model_book");
        }

        final String title;

        public Book(final String title) {
            this.title = name + "'s book named " + title;
        }

        public native void printTitle();

        @Override
        public String toString() {
            return "Book{" +
                    "title='" + title + '\'' +
                    '}';
        }
    }

    public static class Bag {

        static {
            System.loadLibrary("person_model_bag");
        }

        final int size;

        public Bag(final int size) {
            this.size = size;
        }

        public native void printSize();

        public static native void printSize(final Bag bag);

        @Override
        public String toString() {
            return "Bag{" +
                    "size=" + size +
                    '}';
        }
    }
}
