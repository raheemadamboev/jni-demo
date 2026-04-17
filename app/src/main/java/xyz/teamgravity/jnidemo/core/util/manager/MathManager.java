package xyz.teamgravity.jnidemo.core.util.manager;

public class MathManager {

    static {
        System.loadLibrary("math_manager");
    }

    public native static void sayHi();

    public native double multiply(final double a, final double b);

    public native boolean isOdd(final int a);

    public native float damage(final long a);

    public native double[] linearSpace(
            final double start,
            final double end,
            final int number
    );

    public native double sum(final double[] values);

    public native double[] squareOf(final double[] values);

    public native double[][] ones(
            final int rows,
            final int columns
    );

    public native double[][] ones(final double[][] values);

    public native double max(final double[][] values);
}
