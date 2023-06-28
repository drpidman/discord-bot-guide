

echo "Running build ->"
cmake build/
echo "Joining build dir"
cd build
echo "Running make"
make -j4
echo "Exit build dir"
cd ..
echo "Running app"
build/discord-programming-guide
