package xyz.teamgravity.jnidemo.core.util;

public class Unsafe {

    static {
        System.loadLibrary("unsafe");
    }

    public static native long allocateMemory(final long bytes);

    public static native void freeMemory(final long address);

    public static native void putInt(
            final long address,
            final int value
    );

    public static native int getInt(final long address);

    public static native void putDouble(
            final long address,
            final double value
    );

    public static native double getDouble(final long address);
}
