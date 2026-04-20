package xyz.teamgravity.jnidemo.data.model;

public class PersonModel {

    private final String name;
    final int age;
    public final boolean isMarried;
    protected final double debt;

    private static String status;
    private static double budget = 500.0;

    public PersonModel(String name, int age, boolean isMarried, double debt) {
        this.name = name;
        this.age = age;
        this.isMarried = isMarried;
        this.debt = debt;
        status = isMarried ? "Married" : "Single";
        budget -= debt;
    }
}
