package xyz.teamgravity.jnidemo.core.util.manager;

public class LoanManager {

    static {
        System.loadLibrary("loan_manager");
    }

    public native static double calculateExtra(double amount);
}
