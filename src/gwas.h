#ifndef SNPLIB_SRC_GWAS_H_
#define SNPLIB_SRC_GWAS_H_

#include <atomic>
#include <numeric>
#include <thread>
#include <vector>

#include "line_search.h"
#include "logistc_regression.h"
#include "snp.h"
#include "uni_lmm.h"

namespace snplib {
void CalcLinearRegressionGWAS(const uint8_t *geno, size_t num_samples,
                              size_t num_snps, const double *covariates,
                              size_t num_covariates, const double *trait,
                              double *betas, double *stats, size_t num_threads);
void CalcLogisticGWAS(const uint8_t *geno, size_t num_samples, size_t num_snps,
                      const double *covariates, size_t num_covariates,
                      const double *trait, double *betas, double *stats,
                      size_t num_threads);
void CalcCCAGWAS(const uint8_t *geno, size_t num_samples, size_t num_snps,
                 const double *trait, size_t num_dims, double *betas,
                 double *rho2, size_t num_threads);
void CalcCCAReplication(const uint8_t *geno, size_t num_samples,
                        size_t num_snps, const double *scores,
                        const double *betas, size_t num_dims, double *rho,
                        size_t num_threads);
void CalcUniLMMGWAS(const uint8_t *geno, size_t num_samples, size_t num_snps,
                    const double *lambda, const double *V,
                    const double *covariates, size_t num_covariates,
                    const double *trait, double *betas, double *dfs, double *se,
                    size_t num_threads);
void CalcCCALMM(const uint8_t *geno, size_t num_samples, size_t num_snps,
                const double *lambda, const double *V, const double *covariates,
                size_t num_covariates, const double *scores, size_t num_dims,
                const double *cca_betas, double *betas, double *dfs, double *se,
                size_t num_threads);
}  // namespace snplib

#endif  // SNPLIB_SRC_GWAS_H_
