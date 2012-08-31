/*
 * CommHandler_I.cpp
 *
 *  Created on: Jun 25, 2012
 *      Author: tcpan
 */

#include "CommHandler_I.h"
#include <sstream>
#include "mpi.h"

namespace cci {
namespace rt {


const int CommHandler_I::CONTROL_TAG = 0;
const int CommHandler_I::DATA_TAG = 1;


CommHandler_I::CommHandler_I(MPI_Comm const * _parent_comm, int const _gid, Scheduler_I * _scheduler,
		cciutils::SCIOLogSession *_logsession) :
	Communicator_I(_parent_comm, _gid, _logsession), action(NULL), status(READY) {
	long long t1, t2;

	t1 = ::cciutils::event::timestampInUS();

	if (comm == MPI_COMM_NULL) {
		Debug::print("%s ERROR: comm member %d must have a MPI communicator.\n", getClassName(), rank);
		status = ERROR;

	} else {

		scheduler = _scheduler;
		scheduler->configure(comm);

		if (scheduler->isRoot()) {

			std::vector<int> workers = scheduler->getLeaves();
			for (std::vector<int>::iterator iter = workers.begin();
					iter != workers.end(); ++iter) {
				activeWorkers[*iter] = READY;
			}

		}

	}
	t2 = ::cciutils::event::timestampInUS();
	if (this->logsession != NULL) this->logsession->log(cciutils::event(0, std::string("MPI scheduler"), t1, t2, std::string(), ::cciutils::event::NETWORK_IO));
}

CommHandler_I::~CommHandler_I() {
	//printf("CommHandler destructor called\n");
	if (!activeWorkers.empty()) {
		activeWorkers.clear();
	}

	Communicator_I::dereference(action, this);
	if (scheduler != NULL) delete scheduler;
}

} /* namespace rt */
} /* namespace cci */