CXX=/usr/bin/g++-4.4 
CXXFLAGS=-fPIC -pg -O3 #-g -msse4.2 -O3


#OpenMP
CXXFLAGS += -fopenmp


#CXX=icpc
#CXXFLAGS=-g -fast -openmp -msse4.2

RM=/bin/rm -rf

CXXFLAGS	+= `pkg-config opencv --cflags` -I../../features-cpu -I../../segment -I../../execEngine -I/usr/include -I/home/tcpan/PhD/path/ext/hdf5-1.8.7-linux-x86_64-shared/include
LDFLAGS		+= `pkg-config opencv --libs` -L../../features-cpu -lfeatures -L../../segment -lsegment -L../../execEngine -lexecengine -L/usr/lib -L/home/tcpan/PhD/path/ext/hdf5-1.8.7-linux-x86_64-shared/lib -lsz -lhdf5 -lhdf5_hl
