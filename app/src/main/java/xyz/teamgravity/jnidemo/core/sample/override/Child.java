package xyz.teamgravity.jnidemo.core.sample.override;

public class Child extends Parent {

    static {
        System.loadLibrary("child");
    }

    @Override
    public double mustang() {
        return 460.0;
    }

    @Override
    public native double malibu();
}
