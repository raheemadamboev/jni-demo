package xyz.teamgravity.jnidemo.core.util;

public class FileReader implements AutoCloseable {

    static {
        System.loadLibrary("file_reader");
        initIds();
    }

    public String file;
    private boolean isClosed = false;

    public FileReader(final String file) {
        this.file = file;
        open0();
    }

    private static native void initIds();

    private native void open0();

    private native void close0();

    private native String next0();

    public native boolean eof();

    public String next() {
        if (isClosed) {
            throw new IllegalStateException("File stream has been closed.");
        } else {
            return next0();
        }
    }

    @Override
    public void close() {
        close0();
        isClosed = true;
        System.out.println("close()");
    }

    @Override
    protected void finalize() {
        close0();
        isClosed = true;
        System.out.println("finalize()");
    }
}
