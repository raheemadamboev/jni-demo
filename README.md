Build executable libraries for Android:

```cmd
export NDK=$HOME/Library/Android/sdk/ndk/28.2.13676358
export TOOLCHAIN=$NDK/toolchains/llvm/prebuilt/darwin-x86_64
export API=26
export AR=$TOOLCHAIN/bin/llvm-ar
export RANLIB=$TOOLCHAIN/bin/llvm-ranlib
export CFLAGS="-fPIC -O2"

mkdir -p build-arm64 && cd build-arm64
export TARGET=aarch64-linux-android
export CC=$TOOLCHAIN/bin/${TARGET}${API}-clang
../configure --host=$TARGET --prefix=$PWD/../install-arm64 --disable-shared --enable-static
make -j8 && make install
cd ..

mkdir -p build-armv7 && cd build-armv7
export TARGET=armv7a-linux-androideabi
export CC=$TOOLCHAIN/bin/${TARGET}${API}-clang
../configure --host=$TARGET --prefix=$PWD/../install-armv7 --disable-shared --enable-static
make -j8 && make install
cd ..

mkdir -p build-x86_64 && cd build-x86_64
export TARGET=x86_64-linux-android
export CC=$TOOLCHAIN/bin/${TARGET}${API}-clang
../configure --host=$TARGET --prefix=$PWD/../install-x86_64 --disable-shared --enable-static
make -j8 && make install
cd ..

mkdir -p build-x86 && cd build-x86
export TARGET=i686-linux-android
export CC=$TOOLCHAIN/bin/${TARGET}${API}-clang
../configure --host=$TARGET --prefix=$PWD/../install-x86 --disable-shared --enable-static
make -j8 && make install
cd ..
```
