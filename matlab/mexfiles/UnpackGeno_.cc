#include "../../src/data_manage.h"
#include "mex.h"
#include "matrix.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
  auto *geno = reinterpret_cast<uint8_t *>(mxGetData(prhs[0]));
  size_t dims[2];
  dims[0] = mxGetScalar(prhs[1]);
  dims[1] = mxGetN(prhs[0]);
  plhs[0] = mxCreateNumericArray(2, dims, mxUINT8_CLASS, mxREAL);
  mxUint8 *geno_d = 	mxGetUint8s(plhs[0]);
  snplib::UnpackGeno(geno, dims[0], dims[1], geno_d);
}