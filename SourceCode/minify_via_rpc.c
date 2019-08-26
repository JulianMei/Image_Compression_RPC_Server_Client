#include "minifyjpeg_clnt.c"
#include "minifyjpeg_xdr.c"
#include <stdio.h>
#include <stdlib.h>

CLIENT* get_minify_client(char *server){
    CLIENT *cl;

    /* Your code goes here */
    cl = clnt_create(server, JPEG_PROG, JPEG_VER, "tcp");
    if (cl == NULL) {
        clnt_pcreateerror(server);
    }

    else {
        // Change the default time-out value
        struct timeval tv;
        tv.tv_sec = 10;
        tv.tv_usec = 0;
        clnt_control(cl, CLSET_TIMEOUT, (char *)&tv);
    }
    return cl;
}

/*
The size of the minified file is not known before the call to the library that minimizes it,
therefore this function should allocate the right amount of memory to hold the minimized file
and return it in the last parameter to it
*/
int minify_via_rpc(CLIENT *cl, void* src_val, size_t src_len, size_t *dst_len, void **dst_val){

	/*Your code goes here */
    // Call rpc to get:
    // 1. size of the minified file 
    // 2. Allocate memory to hold the minified file contents
    // 3. Populate minified file contents to allocated memory 
    // 4. Return dst_val
    jpeg_in in;
    jpeg_out out;
    memset(&in, 0, sizeof(in));
    memset(&out, 0, sizeof(out));

    enum clnt_stat stat = 0;

    in.data.data_val = (char *)src_val;
    in.data.data_len = (u_int)src_len;

    // Allocate memory for the minified file, since we are "down-sizing" src_len is definitely large enough. 
    out.data.data_val = (char *)malloc(src_len);  
    
    // RPC.
    stat = jpeg_minify_1(in, &out, cl);
    if(stat == RPC_TIMEDOUT) {
        return stat;
    }

    *dst_len = (size_t)(out.data.data_len); 
    *dst_val = (char *)(out.data.data_val);
    
    return stat;
}
