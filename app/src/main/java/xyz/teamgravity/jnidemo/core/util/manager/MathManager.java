package xyz.teamgravity.jnidemo.core.util.manager;

public class MathManager {

    static {
        System.loadLibrary("math_manager");
    }

    public native static void sayHi();

    public native double multiply(double a, double b);
}
