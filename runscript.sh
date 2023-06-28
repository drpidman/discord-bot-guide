

if $1  == --cmake-clean
    rm -rf build/*
elif $1 == --cmake-make
    cmake build/
elif $1 == --make-build
    make -j4
fi

