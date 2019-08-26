/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "minifyjpeg.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

enum clnt_stat 
jpeg_minify_1(jpeg_in arg1, jpeg_out *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, JPEG_MINIFY,
		(xdrproc_t) xdr_jpeg_in, (caddr_t) &arg1,
		(xdrproc_t) xdr_jpeg_out, (caddr_t) clnt_res,
		TIMEOUT));
}
