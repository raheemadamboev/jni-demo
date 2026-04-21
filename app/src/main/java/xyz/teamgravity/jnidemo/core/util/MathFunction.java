package xyz.teamgravity.jnidemo.core.util;

public interface MathFunction {

    double value(final double x);

    default double valueScaled(final double x) {
        return value(x) * 5.0;
    }

    static MathFunction functionScaled(final MathFunction function) {
        return x -> function.value(x) * 5.0;
    }
}
