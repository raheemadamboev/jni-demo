package xyz.teamgravity.jnidemo.core.sample.override;

public class Parent {

    static {
        System.loadLibrary("parent");
    }

    public native double mustang();

    public double malibu() {
        return 249.0;
    }
}
