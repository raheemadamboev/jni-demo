package xyz.teamgravity.jnidemo.core.sample;

public class OverloadSample {

    static {
        System.loadLibrary("overload_sample");
    }

    public native double add(double a);

    public native double add(double a, double b);

    public native double add(double a, String b);

    public double add(double a, double b, double c) {
        return a + b + c;
    }
}
