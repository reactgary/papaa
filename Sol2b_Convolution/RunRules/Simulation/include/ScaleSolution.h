/**\file */
#ifndef SLIC_DECLARATIONS_ScaleSolution_H
#define SLIC_DECLARATIONS_ScaleSolution_H
#include "MaxSLiCInterface.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define ScaleSolution_PCIE_ALIGNMENT (16)


/*----------------------------------------------------------------------------*/
/*---------------------------- Interface default -----------------------------*/
/*----------------------------------------------------------------------------*/




/**
 * \brief Basic static function for the interface 'default'.
 * 
 * \param [in] param_height Interface Parameter "height".
 * \param [in] param_width Interface Parameter "width".
 * \param [in] offset_ScaleSolutionKernel_ny Offset parameter "ny" for kernel "ScaleSolutionKernel".
 * \param [in] inscalar_ScaleSolutionKernel_w1 Input scalar parameter "ScaleSolutionKernel.w1".
 * \param [in] inscalar_ScaleSolutionKernel_w2 Input scalar parameter "ScaleSolutionKernel.w2".
 * \param [in] inscalar_ScaleSolutionKernel_w3 Input scalar parameter "ScaleSolutionKernel.w3".
 * \param [in] inscalar_ScaleSolutionKernel_w4 Input scalar parameter "ScaleSolutionKernel.w4".
 * \param [in] inscalar_ScaleSolutionKernel_w5 Input scalar parameter "ScaleSolutionKernel.w5".
 * \param [in] inscalar_ScaleSolutionKernel_w6 Input scalar parameter "ScaleSolutionKernel.w6".
 * \param [in] inscalar_ScaleSolutionKernel_w7 Input scalar parameter "ScaleSolutionKernel.w7".
 * \param [in] inscalar_ScaleSolutionKernel_w8 Input scalar parameter "ScaleSolutionKernel.w8".
 * \param [in] inscalar_ScaleSolutionKernel_w9 Input scalar parameter "ScaleSolutionKernel.w9".
 * \param [in] instream_inStream The stream should be of size ((param_width * param_height) * 4) bytes.
 * \param [out] outstream_outStream The stream should be of size (((param_width - 2) * (param_height - 2)) * 4) bytes.
 */
void ScaleSolution(
	int64_t param_height,
	int64_t param_width,
	long offset_ScaleSolutionKernel_ny,
	double inscalar_ScaleSolutionKernel_w1,
	double inscalar_ScaleSolutionKernel_w2,
	double inscalar_ScaleSolutionKernel_w3,
	double inscalar_ScaleSolutionKernel_w4,
	double inscalar_ScaleSolutionKernel_w5,
	double inscalar_ScaleSolutionKernel_w6,
	double inscalar_ScaleSolutionKernel_w7,
	double inscalar_ScaleSolutionKernel_w8,
	double inscalar_ScaleSolutionKernel_w9,
	const float *instream_inStream,
	float *outstream_outStream);

/**
 * \brief Basic static non-blocking function for the interface 'default'.
 * 
 * Schedule to run on an engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 * 
 * 
 * \param [in] param_height Interface Parameter "height".
 * \param [in] param_width Interface Parameter "width".
 * \param [in] offset_ScaleSolutionKernel_ny Offset parameter "ny" for kernel "ScaleSolutionKernel".
 * \param [in] inscalar_ScaleSolutionKernel_w1 Input scalar parameter "ScaleSolutionKernel.w1".
 * \param [in] inscalar_ScaleSolutionKernel_w2 Input scalar parameter "ScaleSolutionKernel.w2".
 * \param [in] inscalar_ScaleSolutionKernel_w3 Input scalar parameter "ScaleSolutionKernel.w3".
 * \param [in] inscalar_ScaleSolutionKernel_w4 Input scalar parameter "ScaleSolutionKernel.w4".
 * \param [in] inscalar_ScaleSolutionKernel_w5 Input scalar parameter "ScaleSolutionKernel.w5".
 * \param [in] inscalar_ScaleSolutionKernel_w6 Input scalar parameter "ScaleSolutionKernel.w6".
 * \param [in] inscalar_ScaleSolutionKernel_w7 Input scalar parameter "ScaleSolutionKernel.w7".
 * \param [in] inscalar_ScaleSolutionKernel_w8 Input scalar parameter "ScaleSolutionKernel.w8".
 * \param [in] inscalar_ScaleSolutionKernel_w9 Input scalar parameter "ScaleSolutionKernel.w9".
 * \param [in] instream_inStream The stream should be of size ((param_width * param_height) * 4) bytes.
 * \param [out] outstream_outStream The stream should be of size (((param_width - 2) * (param_height - 2)) * 4) bytes.
 * \return A handle on the execution status, or NULL in case of error.
 */
max_run_t *ScaleSolution_nonblock(
	int64_t param_height,
	int64_t param_width,
	long offset_ScaleSolutionKernel_ny,
	double inscalar_ScaleSolutionKernel_w1,
	double inscalar_ScaleSolutionKernel_w2,
	double inscalar_ScaleSolutionKernel_w3,
	double inscalar_ScaleSolutionKernel_w4,
	double inscalar_ScaleSolutionKernel_w5,
	double inscalar_ScaleSolutionKernel_w6,
	double inscalar_ScaleSolutionKernel_w7,
	double inscalar_ScaleSolutionKernel_w8,
	double inscalar_ScaleSolutionKernel_w9,
	const float *instream_inStream,
	float *outstream_outStream);

/**
 * \brief Advanced static interface, structure for the engine interface 'default'
 * 
 */
typedef struct { 
	int64_t param_height; /**<  [in] Interface Parameter "height". */
	int64_t param_width; /**<  [in] Interface Parameter "width". */
	long offset_ScaleSolutionKernel_ny; /**<  [in] Offset parameter "ny" for kernel "ScaleSolutionKernel". */
	double inscalar_ScaleSolutionKernel_w1; /**<  [in] Input scalar parameter "ScaleSolutionKernel.w1". */
	double inscalar_ScaleSolutionKernel_w2; /**<  [in] Input scalar parameter "ScaleSolutionKernel.w2". */
	double inscalar_ScaleSolutionKernel_w3; /**<  [in] Input scalar parameter "ScaleSolutionKernel.w3". */
	double inscalar_ScaleSolutionKernel_w4; /**<  [in] Input scalar parameter "ScaleSolutionKernel.w4". */
	double inscalar_ScaleSolutionKernel_w5; /**<  [in] Input scalar parameter "ScaleSolutionKernel.w5". */
	double inscalar_ScaleSolutionKernel_w6; /**<  [in] Input scalar parameter "ScaleSolutionKernel.w6". */
	double inscalar_ScaleSolutionKernel_w7; /**<  [in] Input scalar parameter "ScaleSolutionKernel.w7". */
	double inscalar_ScaleSolutionKernel_w8; /**<  [in] Input scalar parameter "ScaleSolutionKernel.w8". */
	double inscalar_ScaleSolutionKernel_w9; /**<  [in] Input scalar parameter "ScaleSolutionKernel.w9". */
	const float *instream_inStream; /**<  [in] The stream should be of size ((param_width * param_height) * 4) bytes. */
	float *outstream_outStream; /**<  [out] The stream should be of size (((param_width - 2) * (param_height - 2)) * 4) bytes. */
} ScaleSolution_actions_t;

/**
 * \brief Advanced static function for the interface 'default'.
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in,out] interface_actions Actions to be executed.
 */
void ScaleSolution_run(
	max_engine_t *engine,
	ScaleSolution_actions_t *interface_actions);

/**
 * \brief Advanced static non-blocking function for the interface 'default'.
 *
 * Schedule the actions to run on the engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 *
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in] interface_actions Actions to be executed.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *ScaleSolution_run_nonblock(
	max_engine_t *engine,
	ScaleSolution_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'default'.
 * 
 * \param [in] group Group to use.
 * \param [in,out] interface_actions Actions to run.
 *
 * Run the actions on the first device available in the group.
 */
void ScaleSolution_run_group(max_group_t *group, ScaleSolution_actions_t *interface_actions);

/**
 * \brief Group run advanced static non-blocking function for the interface 'default'.
 * 
 *
 * Schedule the actions to run on the first device available in the group and return immediately.
 * The status of the run must be checked with ::max_wait. 
 * Note that use of ::max_nowait is prohibited with non-blocking running on groups:
 * see the ::max_run_group_nonblock documentation for more explanation.
 *
 * \param [in] group Group to use.
 * \param [in] interface_actions Actions to run.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *ScaleSolution_run_group_nonblock(max_group_t *group, ScaleSolution_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'default'.
 * 
 * \param [in] engarray The array of devices to use.
 * \param [in,out] interface_actions The array of actions to run.
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void ScaleSolution_run_array(max_engarray_t *engarray, ScaleSolution_actions_t *interface_actions[]);

/**
 * \brief Array run advanced static non-blocking function for the interface 'default'.
 * 
 *
 * Schedule to run the array of actions on the array of engines, and return immediately.
 * The length of interface_actions must match the size of engarray.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 *
 * \param [in] engarray The array of devices to use.
 * \param [in] interface_actions The array of actions to run.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *ScaleSolution_run_array_nonblock(max_engarray_t *engarray, ScaleSolution_actions_t *interface_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param [in] maxfile The maxfile to use.
 * \param [in] interface_actions The interface-specific actions to run.
 * \return The dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* ScaleSolution_convert(max_file_t *maxfile, ScaleSolution_actions_t *interface_actions);

/**
 * \brief Initialise a maxfile.
 */
max_file_t* ScaleSolution_init(void);

/* Error handling functions */
int ScaleSolution_has_errors(void);
const char* ScaleSolution_get_errors(void);
void ScaleSolution_clear_errors(void);
/* Free statically allocated maxfile data */
void ScaleSolution_free(void);
/* returns: -1 = error running command; 0 = no error reported */
int ScaleSolution_simulator_start(void);
/* returns: -1 = error running command; 0 = no error reported */
int ScaleSolution_simulator_stop(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* SLIC_DECLARATIONS_ScaleSolution_H */

