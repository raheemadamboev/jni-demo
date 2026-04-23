package xyz.teamgravity.jnidemo.core.sample;

public class ArrayCriticalAccessSample {

    static  {
        System.loadLibrary("array_critical_access_sample");
    }

    public static native void addRegion(double[] array, double x);

    public static native void addElements(double[] array, double x);

    public static native void addCritical(double[] array, double x);
}
