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

    public native double minus(double a);

    public double minus(double a, double b) {
        return a - b;
    }

    public native double multiply(double a);

    public native double[] multiply(double[] a);

    public native double multiply(double a, String b);

    public native void multiply(OverloadSample a, OverloadSample b);
}
