package xyz.teamgravity.jnidemo.core.util.manager;

public class TextManager {

    static {
        System.loadLibrary("text_manager");
    }

    public static native String hello();

    public static native void print(final String message);

    public static native String concat(final String a, final String b);
}
