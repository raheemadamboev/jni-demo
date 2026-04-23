package xyz.teamgravity.jnidemo.core.sample;

public class StringCriticalAccessSample {

    static {
        System.loadLibrary("string_critical_access_sample");
    }

    public static native void printStringRegular(String value);

    public static native void printStringCritical(String value);
}
