package xyz.teamgravity.jnidemo.data.model;

import androidx.annotation.NonNull;

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

    @NonNull
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
