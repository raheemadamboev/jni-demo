package xyz.teamgravity.jnidemo.core.util.manager;

import xyz.teamgravity.jnidemo.data.model.PersonModel;

public class TextManager {

    static {
        System.loadLibrary("text_manager");
    }

    public static native String hello();

    public static native void print(final String message);

    public static native String concat(final String a, final String b);

    public static native void evaluatePerson(final PersonModel person);
}
