# Installation of CP2K on Condo at ORNL

Step 1. Load the modules

    module load cmake/3.8.2
    module load fftw/3.3.5
    module load mkl/2017
    module load scalapack/2.0.2

    # default modules
    module load gcc/5.3.0
    module load openmpi/2.1.1
    module load xalt/0.7.6
    module load PE-gnu/2.0

Step 2. Install the libs with toolchain

    cd cp2k/tools/toolchain/

    ./install_cp2k_toolchain.sh --install-all --mpi-mode=openmpi --math-mode=mkl --enable-omp=no --enable-cuda=no --with-libsmm=install --with-elpa=no --with-valgrind=no --with-cmake=system --with-make=system --with-gcc=system --with-binutils=system --with-openmpi=system --with-mpich=no --with-reflapack=no --with-acml=no --with-mkl=no --with-ptscotch=no --with-parmetis=no --with-metis=no --with-superlu=no --with-pexsi=no --with-quip=no --with-openblas=install --with-scalapack=system
    
    source cp2k/tools/toolchain/install/setup
    
Step 3. Copy the configuration files to cp2k's architecture directory.

    cp cp2k/tools/toolchain/install/arch/* cp2k/arch/
   
Step 4. Build CP2K

    cd cp2k/makefiles/
    make ARCH=local VERSION="sopt popt"
    
