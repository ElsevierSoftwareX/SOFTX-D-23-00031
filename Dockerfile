FROM ubuntu:22.04

RUN apt-get update \
    && apt-get -y install cmake git wget build-essential libnetcdf-dev

# download and instal NetCDFCXX
RUN git clone https://github.com/Unidata/netcdf-cxx4.git \
    && cd netcdf-cxx4 \
    && mkdir build \
    && cd build \
    && cmake .. \
    && make \
    && ctest \
    && make install

# download, build and install BiasAdjustCXX
RUN git clone https://github.com/btschwertfeger/BiasAdjustCXX.git \
    && cd BiasAdjustCXX \
    && mkdir build && cd build \
    && cmake .. && cmake --build . \
    && cp BiasAdjustCXX /usr/local/bin

