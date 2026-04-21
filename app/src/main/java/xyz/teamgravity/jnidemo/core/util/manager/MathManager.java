package xyz.teamgravity.jnidemo.core.util.manager;

import xyz.teamgravity.jnidemo.core.util.MathFunction;

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

    public native double callValue(
            final MathFunction function,
            final double x
    );

    public native double callValueScaled(
            final MathFunction function,
            final double x
    );

    public native MathFunction callFunctionScaled(final MathFunction function);

    public static native double ai(double x);

    public static native double bi(double x);
}
