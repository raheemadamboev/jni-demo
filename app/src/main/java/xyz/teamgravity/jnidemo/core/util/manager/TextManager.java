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

    public static native void divorcePerson(final PersonModel person);

    public static native void printPerson(final PersonModel person);

    public static native void agePeriod(final PersonModel person);

    public static native void evaluate(final PersonModel person);

    public static native void bankrupt(final PersonModel person);

    public static native long freeMemory();

    public static native PersonModel createPerson(
            final String name,
            final int age,
            final boolean isMarried,
            final double debt
    );

    public static native PersonModel createPerson(final String name);
}