package xyz.teamgravity.jnidemo.core.sample;

public class RegisterNativesSample {

    static {
        System.loadLibrary("register_natives_sample");
    }

    public static native int doubleValue(final int value);

    public native String sayHi();
}
