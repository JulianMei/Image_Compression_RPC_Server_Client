/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "minifyjpeg.h"

bool_t
xdr_jpeg_in (XDR *xdrs, jpeg_in *objp)
{
	register int32_t *buf;

	 if (!xdr_bytes (xdrs, (char **)&objp->data.data_val, (u_int *) &objp->data.data_len, MAX_FILE_SIZE))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_jpeg_out (XDR *xdrs, jpeg_out *objp)
{
	register int32_t *buf;

	 if (!xdr_bytes (xdrs, (char **)&objp->data.data_val, (u_int *) &objp->data.data_len, MAX_FILE_SIZE))
		 return FALSE;
	return TRUE;
}
