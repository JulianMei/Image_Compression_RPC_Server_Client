#include "magickminify.h"
#include "minifyjpeg.h"

/* Implement the server-side functions here */
bool_t jpeg_minify_1_svc(jpeg_in argp, jpeg_out *result, struct svc_req *rqstp) {
    magickminify_init();
    
    memset(result, 0, sizeof(*result));
    char *src = argp.data.data_val;
    u_int src_len = argp.data.data_len;
    u_int *dst_len = &((result->data).data_len);

    (result->data).data_val = (char *)magickminify((void *)src, (ssize_t)src_len, (ssize_t *)dst_len);

    magickminify_cleanup();
    return 1;  // TODO: 0 means success?
}


int jpeg_prog_1_freeresult (SVCXPRT * transp, xdrproc_t xdr_proc, caddr_t result) {
    jpeg_out *res = (jpeg_out *)result;
    free((res->data).data_val);
    return 1;
}   
