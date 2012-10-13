/*
 * GenerateOutput.h
 *
 *  Created on: Jun 18, 2012
 *      Author: tcpan
 */

#ifndef GENERATE_OUTPUT_H_
#define GENERATE_OUTPUT_H_

#include <Action_I.h>

namespace cci {
namespace rt {
namespace syntest {

class GenerateOutput: public cci::rt::Action_I {
public:
	GenerateOutput(MPI_Comm const * _parent_comm, int const _gid,
			DataBuffer *_input, DataBuffer *_output,
			std::string &proctype, int imagedim, int gpuid,
			bool _compress,
			cciutils::SCIOLogSession *_logsession = NULL);
	virtual ~GenerateOutput();
	virtual int run();
	virtual const char* getClassName() { return "GenerateOutput"; };

protected:
	virtual int compute(int const &input_size , void * const &input,
				int &output_size, void * &output);

	int proc_code;
	int output_dim;
	int output_count;
	bool compress;

};

}
} /* namespace rt */
} /* namespace cci */
#endif /* GENERATE_OUTPUT_H_ */
