package xyz.teamgravity.jnidemo.data.model;

public class PersonModel {

    private final String name;
    final int age;
    public final boolean isMarried;
    protected final double debt;

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
}
