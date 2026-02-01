cmake -B build
cd build
make
cd ..
sh ./ctags.sh
cd build
./src/app
