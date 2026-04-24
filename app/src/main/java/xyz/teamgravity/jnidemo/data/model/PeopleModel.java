package xyz.teamgravity.jnidemo.data.model;

public class PeopleModel {

    static {
        System.loadLibrary("people_model");
    }

    private long pointer;

    private static native long allocate0(final String name, final int age);

    private static native void free0(final long pointer);

    private native String getName0(final long pointer);

    private native int getAge0(final long pointer);

    private native void sayHi0(final long pointer);

    private PeopleModel(
            final String name,
            final int age
    ) {
        this.pointer = allocate0(name, age);
    }

    public static PeopleModel allocate(
            final String name,
            final int age
    ) {
        return new PeopleModel(name, age);
    }

    public static void free(PeopleModel people) {
        free0(people.pointer);
    }

    public String getName() {
        return getName0(pointer);
    }

    public int getAge() {
        return getAge0(pointer);
    }

    public void sayHi() {
        sayHi0(pointer);
    }
}
