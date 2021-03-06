HOME_DIR=/nics/c/home/gteodor/

#for percent in 100 95 90 85 80 75 70 65 60 55 50 45 40 35 30 25 20 15 10 5 0; do

for percent in 100 95 90 85 80 75 70 65 60 55 50 45 40 35 30 25 20 15 10 5 0; do
	echo -ne $percent,
	for i in 1 2 3 4 5 ; do
		CPU_DIR=res/CPU/${percent}/$i
		mkdir -p $CPU_DIR
		cpuTime=`grep -R FeatureT ${CPU_DIR}/* | awk '{printf("%f", $2)}'`
		echo -ne $cpuTime,
	done	
	for i in 1 2 3 4 5 ; do
		GPU_DIR=res/GPU/${percent}/$i
		mkdir -p $GPU_DIR
		gpuTime=`grep -R FeatureT ${GPU_DIR}/* | awk '{printf("%f", $2)}'`
		echo -ne $gpuTime,
	done	

	for i in 1 2 3 4 5 ; do
		CPUGPU_DIR=res/CPUGPUFCFS/${percent}/$i
		mkdir -p $CPUGPU_DIR
		fcfsTime=`grep -R FeatureT ${CPUGPU_DIR}/* | awk '{printf("%f", $2)}'`
		echo -ne $fcfsTime,
	done

	for i in 1 2 3 4 5 ; do
		CPUGPU_DIR=res/CPUGPUPRIORITY/${percent}/$i
		mkdir -p $CPUGPU_DIR
		priorityTime=`grep -R FeatureT ${CPUGPU_DIR}/* | awk '{printf("%f", $2)}'`
		echo -ne $priorityTime,	
	done
	echo;

#
#		CPU_DIR=res/CPU/${percent}/$i
#		mkdir -p $CPU_DIR
#		cpuTime=`grep -R FeatureT ${CPU_DIR}/* | awk '{printf("%f", $2)}'`
#		
#		CPUGPU_DIR=res/CPUGPUFCFS/${percent}/$i
#		mkdir -p $CPUGPU_DIR
#		fcfsTime=`grep -R FeatureT ${CPUGPU_DIR}/* | awk '{printf("%f", $2)}'`
#
#		CPUGPU_DIR=res/CPUGPUPRIORITY/${percent}/$i
#		mkdir -p $CPUGPU_DIR
#		priorityTime=`grep -R FeatureT ${CPUGPU_DIR}/* | awk '{printf("%f", $2)}'`
#		
#		echo $percent,$i,$cpuTime,$gpuTime,$fcfsTime,$priorityTime
##	done
done
